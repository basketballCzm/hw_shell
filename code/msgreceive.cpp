#include "msgreceive.h"
void* create_message_queue(void* arg) {
  int running = 1;
  int msgid = -1;
  struct msg_st recv_data;
  struct msg_st ret_data;
  ret_data.msg_type = RETURN_MSEEAGE_TYPE;
  //获取父进程的进程号
  int msgtype = getpid();
  char szTestBuff[255] = "";
  //接收端的消息类型为0则能够全部接收，大于0才开始进行消息数据包的匹配

  //建立消息队列
  msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
  if (msgid == -1) {
    fprintf(stderr, "msgget failed with error: %d\n", errno);

    exit(EXIT_FAILURE);
  }

  //从消息队列中获取消息，直到遇到end消息为止
  while (running) {
    memset((char*)&recv_data, 0, sizeof(msg_st));
    memset((char*)&ret_data.text, 0, BUFSIZ);
    if (msgrcv(msgid, (void*)&recv_data, BUFSIZ, msgtype, 0) == -1) {
      fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
      exit(EXIT_FAILURE);
    }


    char msgbuf[MESSAGE_NUM][MESSAGE_SIZE] = {""};
    char* pch = strtok(recv_data.text, " ");
    for (int i = 0; NULL != pch; i++) {
      strcpy(msgbuf[i], pch);
      pch = strtok(NULL, " ");
    }

    printf("You wrote :%s\n", msgbuf[0]);

    //遇到end结束
    if (0 == strncmp(msgbuf[0], "end", 3)) {
      running = 0;
      sprintf(szTestBuff, "End of test process No. %d", msgtype);
      strcpy(ret_data.text, szTestBuff);
      SEND_MESSAGE()
      continue;
    }

    FUNC_MAP *phead = GET_FUNC_MAP(Main);
    while (NULL != phead->pStrFuncName) {
      if (0 == strcmp(phead->pStrFuncName, msgbuf[0])) {
        /*if (0 == strcmp("f", phead->pStrFuncName)) {
          ((void(*)())(phead->pfn))();
        }*/
        //改进在这里只需要每个测试函数对应添加一个宏即可
        if (0 == strcmp("help", phead->pStrFuncName)) {
          cmd_help(&ret_data);
          break;
        }
        DEFINE_FUNC_TYPE_NO("f", void(*)());
        DEFINE_FUNC_RETURN_TYPE_ONE("f1", int(*)(char*), int, "int", void(*)(int, char*), char*, "char*", char*(*)(char*));
        DEFINE_FUNC_TYPE_TWO("f2", void(*)(char*, char*), char*, "char*", char*(*)(char*), char*, "char*", char*(*)(char*));
        DEFINE_FUNC_TYPE_TWO("f3", void(*)(char*, int), char*, "char*", char*(*)(char*), int, "int", int(*)(char*));
        DEFINE_FUNC_RETURN_TYPE_ONE("f4", CZM(*)(CZM), CZM, "CZM", void(*)(CZM, char*), CZM, "CZM", CZM(*)(char*));
      }
      phead++;
    }

    if (NULL == phead->pStrFuncName) {
      strcpy(ret_data.text, "The function name has not been register! please register the function in funcmap.cpp.");
      SEND_MESSAGE()
      continue;
    }

    strcat(ret_data.text , "  Function call succeeded");
    SEND_MESSAGE()
  }

  exit(EXIT_SUCCESS);
}