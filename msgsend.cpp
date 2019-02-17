#include "msgreceive.h"

int main() {
	int running = 1;
	struct msg_st data;
	char buffer[BUFSIZ];
	int msgid = -1;

	//建立消息队列
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if (msgid == -1) {
		fprintf(stderr, "msgget failed with error: %d\n", errno);
		exit(EXIT_FAILURE);
	}

	//向消息队列中写入消息，直到写入end
	while (running) {
		//输入数据
		printf("Enter some text:");
		//这里会加入/n,但是会接收到空格
		fgets(buffer, BUFSIZ, stdin);
		//去除'\n'
		buffer[strlen(buffer) - 1] = '\0';
		char* pch = strtok(buffer, " ");
		if (*pch < '0' && *pch > '9') {
			printf("Input msg_type is wrong! please input a number not a word!\n");
			continue;
		}
		data.msg_type = atoi(pch);
		pch = strtok(NULL, " ");
		if (NULL == pch) {
			printf("You only input msg_type!then you should input function address!\n");
			continue;
		}
		strcpy(buffer, pch);

		//data.msg_type = 1; //注意2
		printf ("msg_type: %ld\n", data.msg_type);
		strcpy(data.text, buffer);

		//向对列发送数据
		if (msgsnd(msgid, (void*)&data, BUFSIZ, 0) == -1) {
			fprintf(stderr, "msgsnd failed\n");
			exit(EXIT_FAILURE);
		}

		//输入end结束输入
		if (strncmp(buffer, "end", 3) == 0) {
			running = 0;
		}
		sleep(1);
	}
	exit(EXIT_SUCCESS);
}