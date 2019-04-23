/*
这个文件的逻辑就是msgsend的处理逻辑，在该文件中起了两个该线程逻辑同时运行，发现能够保持良好的效果。说明该msgsend工具的逻辑能够承受1秒钟1000条指令。这个结果每次消息队列中的值也很少
*/
#include <pthread.h> // for thread
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/msg.h>

pthread_t tid[3];  // 创建两个线程

#define BUFSIZ 128

struct msg_st {
    long int msg_type;
    char text[BUFSIZ];
};

int msgid = -1;

//所有线程共用一个进程的ID，每个线程有自己的线程ID
void *doSomeThing(void *arg) {
    msg_st msg;
    msg_st recv_msg;
    msg.msg_type = 3167;
    strcpy(msg.text, "f1 你好");

    while (true) {
        if (msgsnd(msgid, (void*)&msg, BUFSIZ, 0) == -1) {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        usleep(500);

        while (true) {
            if (msgrcv(msgid, (void*)&recv_msg, BUFSIZ, 2, IPC_NOWAIT) == -1) {
                if (errno != ENOMSG) {
                    fprintf(stderr, "recv_msgrcv failed with errno: %d\n", errno);
                    exit(EXIT_FAILURE);
                } else {
                    break;
                }
            }
            printf("result: %s\n", recv_msg.text);
            memset((char*)&recv_msg, 0, sizeof(msg_st));
        }
    }
    return NULL;
}

//所有线程共用一个进程的ID，每个线程有自己的线程ID
void *doSomeThing1(void *arg) {
    msg_st msg;
    msg_st recv_msg;
    msg.msg_type = 3169;
    strcpy(msg.text, "f2 你好 我很好");

    while (true) {
        if (msgsnd(msgid, (void*)&msg, BUFSIZ, 0) == -1) {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        usleep(500);

        while (true) {
            if (msgrcv(msgid, (void*)&recv_msg, BUFSIZ, 2, IPC_NOWAIT) == -1) {
                if (errno != ENOMSG) {
                    fprintf(stderr, "recv_msgrcv failed with errno: %d\n", errno);
                    exit(EXIT_FAILURE);
                } else {
                    break;
                }
            }
            printf("result: %s\n", recv_msg.text);
            memset((char*)&recv_msg, 0, sizeof(msg_st));
        }
    }
    return NULL;
}

/*void *doSomeThing2(void *arg) {
    msg_st msg;
    strcpy(msg.text, "f1 czm");
    while (true) {
        msg.msg_type = 2;
        if (msgrcv(msgid, (void*)&msg, BUFSIZ, 2, 0) == -1) {
            if (errno != ENOMSG) {
                fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
                exit(EXIT_FAILURE);
            }
        }
        printf("result: %s\n", msg.text);
        usleep(10);
        memset((char*)&msg, 0, sizeof(msg_st));
    }
    return NULL;
}
*/
int main(void) {
    int i = 0;
    int err;
    //两者相同

    //建立消息队列
    msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
    if (msgid == -1) {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }

    err = pthread_create(&(tid[0]), NULL, &doSomeThing, NULL);
    if (err != 0) printf("\n can't create thread:[%s]", strerror(err));
    else printf("\n Thread created successfully\n");

    err = pthread_create(&(tid[1]), NULL, &doSomeThing1, NULL);
    if (err != 0) printf("\n can't create thread:[%s]", strerror(err));
    else printf("\n Thread created successfully\n");

    /*    err = pthread_create(&(tid[2]), NULL, &doSomeThing2, NULL);
        if (err != 0) printf("\n can't create thread:[%s]", strerror(err));
        else printf("\n Thread created successfully\n");*/

    sleep(300);
    return 0;
}