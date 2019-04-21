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
    msg.msg_type = 27348;
    strcpy(msg.text, "f1 czm");

    while (true) {
        if (msgsnd(msgid, (void*)&msg, BUFSIZ, 0) == -1) {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        usleep(500);
    }
    return NULL;
}

//所有线程共用一个进程的ID，每个线程有自己的线程ID
void *doSomeThing1(void *arg) {
    msg_st msg;
    msg.msg_type = 27346;
    strcpy(msg.text, "f1 czm");

    while (true) {
        if (msgsnd(msgid, (void*)&msg, BUFSIZ, 0) == -1) {
            fprintf(stderr, "msgsnd failed\n");
            exit(EXIT_FAILURE);
        }
        usleep(500);
    }
    return NULL;
}

void *doSomeThing2(void *arg) {
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

    err = pthread_create(&(tid[2]), NULL, &doSomeThing2, NULL);
    if (err != 0) printf("\n can't create thread:[%s]", strerror(err));
    else printf("\n Thread created successfully\n");

    sleep(300);
    return 0;
}