#include "funcmap.h"
#include <string.h>
void cmd_help(msg_st* pmsg) {
    FUNC_MAP *phead = GET_FUNC_MAP(Main);
    while (NULL != phead->pStrFuncName) {
        strcat(pmsg->text, phead->pStrFuncName);
        strcat(pmsg->text, "\n");
        phead++;
    }
}

BEGIN_ITEM_FUNC(Main)
ITEM_FUNC("f", (void*)f)
ITEM_FUNC("f1", (void*)f1)
ITEM_FUNC("f2", (void*)f2)
ITEM_FUNC("f3", (void*)f3)
ITEM_FUNC("f4", (void*)f4)
ITEM_FUNC("help", (void*)cmd_help)
END_ITEM_FUNC()
