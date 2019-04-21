#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <sys/msg.h>
//函数名和函数变量的个数
#define MESSAGE_NUM 10
#define BUFSIZ 128
//返回信息的message_type 1
#define RETURN_MSEEAGE_TYPE 1

//每个字符串的大小
#define MESSAGE_SIZE 100
struct msg_st {
	long int msg_type;
	char text[BUFSIZ];
};

int main() {
	int running = 1;
	struct msg_st data;
	char buffer[BUFSIZ] = "";
	int msgid = -1;

	//建立消息队列
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if (msgid == -1) {
		fprintf(stderr, "msgget failed with error: %d\n", errno);
		exit(EXIT_FAILURE);
	}

	//向消息队列中写入消息，直到写入end
	while (running) {
		memset((char*)&data, 0, sizeof(msg_st));
		//输入数据
		printf("Enter some text:");
		//这里会加入/n,但是会接收到空格
		fgets(buffer, BUFSIZ, stdin);
		//去除'\n'
		buffer[strlen(buffer) - 1] = '\0';

		//输入end结束输入
		if (strncmp(buffer, "end", 3) == 0) {
			running = 0;
			continue;
		}

		int cnt = 0;
		while (' ' == buffer[cnt++]);
		for (; '\0' != buffer[cnt] && ' ' != buffer[cnt]; cnt++);
		char szBuffer[BUFSIZ] = "";
		strncpy(szBuffer, buffer, cnt);
		szBuffer[cnt] = '\0';

		while (' ' == buffer[cnt++]);
		if ('\0' == buffer[cnt - 1]) {
			printf("You only input msg_type!then you should input function address!\n");
			continue;
		}

		int msg_type = atoi(szBuffer);
		if (0 == msg_type) {
			printf("Input msg_type is wrong! please input a number not a word!\n");
			continue;
		}
		data.msg_type = msg_type;


		printf ("msg_buffer: %s\n", buffer + cnt - 1);
		strcpy(data.text, buffer + cnt - 1);

		//向对列发送数据
		if (msgsnd(msgid, (void*)&data, BUFSIZ, 0) == -1) {
			fprintf(stderr, "msgsnd failed\n");
			exit(EXIT_FAILURE);
		}
		memset((char*)&data, 0, sizeof(msg_st));

		//这里不加会造成回复消息的延后
		sleep(1);
		// IPC_NOWAIT 不用阻塞，当没有该消息时直接返回 循环取出消息，直到为空
		while (true) {
			if (msgrcv(msgid, (void*)&data, BUFSIZ, 2, IPC_NOWAIT) == -1) {
				if (errno != ENOMSG) {
					fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
					exit(EXIT_FAILURE);
				} else {
					printf("%d\n", errno);
					break;
				}
			}
			printf("result: %s\n", data.text);
			memset((char*)&data, 0, sizeof(msg_st));
		}

	}

	//删除消息队列
	if (msgctl(msgid, IPC_RMID, 0) == -1) {
		fprintf(stderr, "msgctl(IPC_RMID) failed\n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}