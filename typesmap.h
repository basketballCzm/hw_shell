#ifndef __TYPEMAP_H__
#define __TYPEMAP_H__

struct TYPE_MAP {
    const char* pStrTypeName;
    void* pfn;
};

#define BEGIN_ITEM_TYPE(name)             TYPE_MAP g_##name##Type[] = {

#define ITEM_TYPE(typestr, func)          {typestr, func},

#define END_ITEM_TYPE()                    {NULL, NULL}};

#define DECLARE_ITEM_TYPE(name)           extern TYPE_MAP g_##name##Type[];

#define GET_TYPE_MAP(name)                 g_##name##Type

DECLARE_ITEM_TYPE(Main)

#define DEFINE_FUNC_TYPE_NO(name, functype) \
if (0 == strcmp(name, phead->pStrFuncName)) { \
          ((functype)(phead->pfn))(); \
          break; \
}

#define DEFINE_FUNC_TYPE_ONE(name, functype, var1type, var1typec, var1functype) \
if (0 == strcmp(name, phead->pStrFuncName)) { \
    var1type var1; \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(var1typec, pheadtype->pStrTypeName)) { \
            var1 = ((var1functype)(pheadtype->pfn))(msgbuf[1]); \
            break; \
        } \
        pheadtype++; \
    } \
    if(NULL == pheadtype->pStrTypeName){ \
        printf(" do not have parameters type replace!\n"); \
        continue; \
    } \
    ((functype)(phead->pfn))(var1); \
    break; \
}


#define DEFINE_FUNC_TYPE_TWO(name, functype, var1type, var1typec, var1functype, var2type, var2typec, var2functype) \
if (0 == strcmp(name, phead->pStrFuncName)) { \
    var1type var1; \
    var2type var2; \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(var1typec, pheadtype->pStrTypeName)) { \
            var1 = ((var1functype)(pheadtype->pfn))(msgbuf[1]); \
            break; \
        } \
        pheadtype++; \
    } \
    if(NULL == pheadtype->pStrTypeName){ \
        printf("%s do not have parameters type replace, you have to define this function!\n", var1typec); \
        continue; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(var2typec, pheadtype->pStrTypeName)) { \
            var2 = ((var2functype)(pheadtype->pfn))(msgbuf[2]); \
            break; \
        } \
        pheadtype++; \
    } \
    if(NULL == pheadtype->pStrTypeName){ \
        printf("%s do not have parameters type replace, you have to define this function!\n", var2typec); \
        continue; \
    } \
    ((functype)(phead->pfn))(var1, var2); \
    break; \
}

#define DEFINE_FUNC_TYPE_THREE(name, functype, var1type, var1typec, var1functype, var2type, var2typec, var2functype, var3type, var3typec, var3functype) \
if (0 == strcmp(name, phead->pStrFuncName)) { \
    var1type var1; \
    var2type var2; \
    var3type var3; \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(var1typec, pheadtype->pStrTypeName)) { \
            var1 = ((var1functype)(pheadtype->pfn))(msgbuf[1]); \
            break; \
        } \
        pheadtype++; \
    } \
    if(NULL == pheadtype->pStrTypeName){ \
        printf(" do not have parameters type replace!\n"); \
        continue; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(var2typec, pheadtype->pStrTypeName)) { \
            var2 = ((var2functype)(pheadtype->pfn))(msgbuf[2]); \
            break; \
        } \
        pheadtype++; \
    } \
    if(NULL == pheadtype->pStrTypeName){ \
        printf("%s do not have parameters type replace, you have to define this function!\n", var2typec); \
        continue; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(var3typec, pheadtype->pStrTypeName)) { \
            var3 = ((var3functype)(pheadtype->pfn))(msgbuf[3]); \
            break; \
        } \
        pheadtype++; \
    } \
    if(NULL == pheadtype->pStrTypeName){ \
        printf("%s do not have parameters type replace, you have to define this function!\n", var3typec); \
        continue; \
    } \
    ((functype)(phead->pfn))(var1, var2, var3); \
    break; \
}

#define DEFINE_FUNC_TYPE_FOUR(name, functype, var1type, var1typec, var1functype, var2type, var2typec, var2functype, var3type, var3typec, var3functype, var4type, var4typec, var4functype) \
if (0 == strcmp(name, phead->pStrFuncName)) { \
    var1type var1; \
    var2type var2; \
    var3type var3; \
    var4type var4; \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(var1typec, pheadtype->pStrTypeName)) { \
            var1 = ((var1functype)(pheadtype->pfn))(msgbuf[1]); \
            break; \
        } \
        pheadtype++; \
    } \
    if(NULL == pheadtype->pStrTypeName){ \
        printf(" do not have parameters type replace!\n"); \
        continue; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(var2typec, pheadtype->pStrTypeName)) { \
            var2 = ((var2functype)(pheadtype->pfn))(msgbuf[2]); \
            break; \
        } \
        pheadtype++; \
    } \
    if(NULL == pheadtype->pStrTypeName){ \
        printf("%s do not have parameters type replace, you have to define this function!\n", var2typec); \
        continue; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(var3typec, pheadtype->pStrTypeName)) { \
            var3 = ((var3functype)(pheadtype->pfn))(msgbuf[3]); \
            break; \
        } \
        pheadtype++; \
    } \
    if(NULL == pheadtype->pStrTypeName){ \
        printf("%s do not have parameters type replace, you have to define this function!\n", var3typec); \
        continue; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(var4typec, pheadtype->pStrTypeName)) { \
            var4 = ((var4functype)(pheadtype->pfn))(msgbuf[4]); \
            break; \
        } \
        pheadtype++; \
    } \
    if(NULL == pheadtype->pStrTypeName){ \
        printf("%s do not have parameters type replace, you have to define this function!\n", var4typec); \
        continue; \
    } \
    ((functype)(phead->pfn))(var1, var2, var3, var4); \
    break; \
}

#endif