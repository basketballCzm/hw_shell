#ifndef __MSGRECEIVE_H__
#define __MSGRECEIVE_H__
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <pthread.h>
#include "funcmap.h"
#include "typesmap.h"
//函数名和函数变量的个数
#define MESSAGE_NUM 10

//返回信息的message_type 1
#define RETURN_MSEEAGE_TYPE 2
//消息包中的len
#define BUFSIZ 128
//每个字符串的大小
#define MESSAGE_SIZE 100
//BUFSIZ 8192
struct msg_st {
    long int msg_type;
    char text[BUFSIZ];
};

void* create_message_queue(void* arg);

#define DEFINE_CREATE_MESSAGE_QUEUE()\
pthread_t tid = 0; \
int err = pthread_create(&tid, NULL, &create_message_queue, NULL); \
if (0 != err) { \
    printf("Can not create thread: %s\n", strerror(err)); \
}

#define SEND_MESSAGE()\
if (msgsnd(msgid, (void*)&ret_data, BUFSIZ, 0) == -1) { \
      fprintf(stderr, "msgsnd failed\n"); \
      exit(EXIT_FAILURE); \
}

#define SEND_MESSAGE_USER(data, size)\
if (msgsnd(msgid, (void*)&data, size, 0) == -1) { \
      fprintf(stderr, "msgsnd failed\n"); \
      exit(EXIT_FAILURE); \
}

#endif