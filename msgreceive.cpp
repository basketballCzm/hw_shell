#include "msgreceive.h"
void create_message_queue(long int msgtype) {
  int running = 1;
  int msgid = -1;
  struct msg_st data;
  //接收端的消息类型为0则能够全部接收，大于0才开始进行消息数据包的匹配

  //建立消息队列
  msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
  if (msgid == -1) {
    fprintf(stderr, "msgget failed with error: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  //从消息队列中获取消息，直到遇到end消息为止
  while (running) {
    if (msgrcv(msgid, (void*)&data, BUFSIZ, msgtype, 0) == -1) {
      fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
      exit(EXIT_FAILURE);
    }

    printf("You wrote :%s\n", data.text);

    //遇到end结束
    if (0 == strncmp(data.text, "end", 3)) {
      running = 0;
    }

    FUNC_MAP *phead = GET_FUNC_MAP(Main);
    while (NULL != phead->pStrFuncName) {
      if (0 == strcmp(phead->pStrFuncName, data.text)) {
        __asm__ __volatile__(
          ".code32;"
          "call *%%eax;"
          :
          : "a" (phead->pfn)
        );
        break;
      }
      phead++;
    }

    if (NULL == phead->pStrFuncName) {
      printf("the function name has not been register! please register the function in funcmap.cpp. \n");
    }
  }

  //删除消息队列
  if (msgctl(msgid, IPC_RMID, 0) == -1) {
    fprintf(stderr, "msgctl(IPC_RMID) failed\n");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}