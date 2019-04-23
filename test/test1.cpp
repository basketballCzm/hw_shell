/*这个文件测试使用三个个进程，两个进程分别向消息队列中放同一类消息，每500微秒放一次，一个取消息进程向消息队列中持续取返回信息的消息，这个测试文件良好的运行证明了消息队列能够达到一秒钟1000条命令的处理效果，以及指定进程只会接收指定的消息，不会出现消息接收混乱的现象。这个结果每次消息队列中剩余值很少
*/

/*造成死锁的现象：请求数据存了128个消息，然后服务端消费消息后由于消息队列已经满了，造成无法写入数据。
这里的处理办法：
1. 将服务端的返回数据msgsnd设置为IPC_NOWAIT，这样在队列满后直接丢弃该返回消息。
2. 限制消息发送速度(服务端来不及消费这么多消息)，并且快速取消息。
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
    msg.msg_type = 3134;
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
    msg.msg_type = 3136;
    strcpy(msg.text, "f2 czm czmmmmm");

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
    while (true) {
        msg.msg_type = 2;
        //IPC_NOWAIT 阻塞和非阻塞都能及时消费消息
        if (msgrcv(msgid, (void*)&msg, BUFSIZ, 2, 0) == -1) {
            if (errno != ENOMSG) {
                fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
                exit(EXIT_FAILURE);
            } else {
                continue;
            }
        }
        printf("result: %s\n", msg.text);
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