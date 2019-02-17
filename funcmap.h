#ifndef __FUNCMAP_H__
#define __FUNCMAP_H__
#include <stdio.h>
#include "testfunc.h"

struct FUNC_MAP {
    const int msgType;
    const char* pStrFuncName;
    void* pfn;
};

#define BEGIN_ITEM_FUNC(name)             FUNC_MAP g_##name##Func[] = {

#define ITEM_FUNC(msgtype, funcname, fun) {msgtype, funcname, fun},

#define END_ITEM_FUNC()                    {NULL, NULL, NULL}};

#define DECLARE_ITEM_FUNC(name)           extern FUNC_MAP g_##name##Func[];

#define GET_FUNC_MAP(name)                 g_##name##Func

DECLARE_ITEM_FUNC(Main)

#endif