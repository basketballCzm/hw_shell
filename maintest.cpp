#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//添加头文件，现在重新编译maintest要自己在Makefile.am文件中加上该工具的一些.cpp文件。后面我会把该工具打包，重新编译的时候直接链接工具的库文件即可
#include "msgreceive.h"


int main() {
    //用户自己需要加这一行后重新编译，参数2是用户自定义，表示从消息队列中取出消息的类型，也就是说msg_type=2是发送给maintest的消息。
    DEFINE_CREATE_MESSAGE_QUEUE(2);
    f();
    f1("czm");
    f2("czm", "czmczm");
    //process working!!!
    sleep(1000);
    return 0;
}