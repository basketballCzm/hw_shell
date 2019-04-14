# 命令行基本思路
## 总体介绍
本工具通过命令行动态调用某一正在运行进程中的函数。上面的代码是一个简单的demo。上面代码中testfunc.cpp和testfunc.h是要测试功能函数的文件，maintest.cpp是包含运行的目标程序的main函数，这3个文件简单的模拟被测试的进程。

**本工具的设计思路是**：测试程序（maintest）通过简单修改后重新编译，重新运行测试程序，测试程序会fork出一个进程来并且创建消息队列，等待消息队列中产生符合自己mastype的消息，然后取出消息，分析消息根据funcmap的映射表来查看自己要运行那一个测试函数。（这些测试函数都已经是用户自己注册号重新编译了）**这里在运行测试函数时由于函数指针是void\*类型因此该函数指针不能直接运行测试函数，要在msgreceive.cpp中添加``DEFINE_FUNC_TYPE_ONE("f1", void(*)(char*), char*, "char*", char*(*)(char*));``这个宏，这个宏会指明测试函数的类型，参数的类型，转换参数类型所需要的函数。并且类型专门会有一个typesmap.cpp函数来定义参数类型转换函数。**。测试工具(msgsend)向测试进程发送消息。

**文件说明**：msgsend.cpp是测试工具的main函数入口。msgreceive.cpp和msgreceive.h是工具的运行逻辑。funcmap.h和funcmap.cpp是要测试的函数映射，这里需要自行填入(稍后介绍)。

## 运行流程
1. 如果正常编译完成后会生成msgsend 和 maintest两个可执行文件。
2. 首先运行maintest，然后运行msgsend向进程发送消息。
运行结果如下：

![图片](<images/1.png>)
![图片](<images/2.png>)

msg_type向maintest发送msgtype=1的消息，maintest不能收到，因为它的msgtype=2。然后发送2 f，maintest顺利的执行了f, 接着分别执行了f1, f2, f3, f4（f4的参数类型是自定义的结构体）这4个不同类型的函数，maintest的结果显示都成功的运行了这些函数。（在maintest中加入sleep假设该进程一直在运行）。


## 如何使用
首先用户在要测试的main函数文件中加入```#include "msgreceive.h"``` 和 ```DEFINE_CREATE_MESSAGE_QUEUE(2);``` 两行，然后在funcmap.cpp中注册要测试的函数，即例如这种形式```ITEM_FUNC(2, "f2", (void*)f2)```，这里的3个参数的解释如下。还要在msgreceive.cpp文件中加入DEFINE_FUNC_TYPE_ONE，然后就可以重新编译测试程序。

1. ```ITEM_FUNC(2, "f2", (void*)f2)```宏解释

    **第一个参数**就是msg_type，这里的2要和前面的```DEFINE_CREATE_MESSAGE_QUEUE(2);```中的2相对应，表示这个测试的函数是在程序2号测试程序中的函数，只有给运行2号程序的进程发送运行该函数的指令才能运行该函数，因为只有2号程序才有这个函数（简单来说就是这个函数是属于哪一号程序）。

    **第二个参数**就是函数名，用于校验调用的那一个函数。

    **第三个参数**是存储该函数的地址。这里其实存在以下问题：

2. msgreceive.cpp中```DEFINE_FUNC_TYPE_ONE("f1", void(*)(char*), char*, "char*", char*(*)(char*));```的参数解释。```void f1(char *pstr)``` f1测试函数只有一个参数。

    **第一个参数** 字符类型的f1的名字"f1"

    **第二个参数** 函数f1的类型 ```void(*)(char*)```

    **第三个参数** 第一个参数的类型 char*

    **第四个参数** 第一个参数的类型的名字"char\*"
    
    **第五个参数** 第一个参数的类型所需要的转换函数char* 要转换成char* 或者char* 转换成 int就是```int(*)(char*)```。(注意如果参数是用户自定义的类型，就需要用户自己写char\*到自定义类型的转换函数，并且在typesmap.cpp中定义转换函数，添加转换函数映射。)


## 存在的问题
1. 现在有两个项目要使用这个工具project1和project2,不同项目程序的测试函数理论上都可以写在这里，但是这里是funcmap.cpp文件，如果将两个项目的测试函数都写在这里，重新编译project1时会找不到project2中的函数名，因此会报错。这里因为是写demo就暂时这样做，后面会写成配置文件，编译project1时根据msg_type只加载对应项目的测试函数。**这个问题思考了下还是不用改成配置文件，因为改成配置文件之后就不能获取到测试函数的函数地址。因此这个funcmap.cpp需要针对每个项目进行更改。**
2. 函数类型不明确，因为f,f1,f2的函数类型都不相同，使用空指针类型虽然能够统一的存储地址，但是调用的时候不能转换成f,f1,f2的类型，因此在这里使用内嵌汇编进行跳转。在demo中只测试了无参数的函数，有参数的函数要考虑根据参数类型转换传送给来的数据，然后再传送给汇编码，这里的工作先没有做。**这里自定义了一些宏，用户通过自己编写一些宏来给定程序信息。在msgreceive.cpp中按照一定的格式添加DEFINE_FUNC_TYPE_NO类似的宏。**

## 自定义类型 
对于如下自定义的类型： 
```c
struct CZM {
    char *pstr;
    int int_num;
    float float_num;
    double double_num;
    long long_num;
    char *pstr1;
};
``` 
对应在shell输入的字符串为：{czm,10,10.1,10.11,12345,czmczm}，注意每个成员变量之间必须要以','分隔开，并且中间不能出现空格。 
对于自定义的类型，用户可以自己写字符串到自定义类型的转换，使用本项目自带的宏来自动生成。对于上面自定义的结构体可以参考下面的宏的写法： 
```c
DEFINE_TYPE_CONVERT_FUNC_SIX(CZM, strtoczm, char*, "char*", char*(*)(char*), pstr, int, "int", int(*)(char*), int_num, float, "float", float(*)(char*), float_num, double, "double", double(*)(char*), double_num, long, "long", long(*)(char*), long_num, char*, "char*", char*(*)(char*), pstr1)
```

**进程与进程之间的通讯使用消息队列**



## 本demo运行
本项目使用automake工具自动生成makefile，首先确保安装automake和autoconf。然后分别执行下面命令：

* aclocal
* autoconf
* automake --add-missing
* ./configure
* make

即可生成msgseng和maintest两个可执行文件。

## 注意事项
1. 函数指针和空指针之间强制转换
void* pfn = (void*)f;
((void(*)())pfn)();
2. 既然是一个辅助测试工具，也要适当让用户输入一些信息，前面没有思路是想程序完完整整代替用户工作。
