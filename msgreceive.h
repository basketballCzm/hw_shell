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
#include "funcmap.h"
#include "typesmap.h"
//函数名和函数变量的个数
#define MESSAGE_NUM 10

//每个字符串的大小
#define MESSAGE_SIZE 100
struct msg_st {
    long int msg_type;
    char text[BUFSIZ];
};

void create_message_queue(long int msgtype);

#define DEFINE_CREATE_MESSAGE_QUEUE(msgtype)\
{\
int pid = 0; \
if ((pid == fork()) == 0) {\
create_message_queue(msgtype); \
}\
}

#endif