#ifndef __TYPEMAP_H__
#define __TYPEMAP_H__
#include "../testfunc.h"

struct TYPE_MAP {
    const char* pStrTypeName;
    void* pfn;
};

//每个函数最大的参数数量
#define MAX_PARAMETER_NUM 10

#define MAX_PARAMETER_LEN 255

#define BEGIN_ITEM_TYPE(name)             TYPE_MAP g_##name##Type[] = {

#define ITEM_TYPE(typestr, func)          {typestr, func},

#define END_ITEM_TYPE()                    {NULL, NULL}};

#define DECLARE_ITEM_TYPE(name)           extern TYPE_MAP g_##name##Type[];

#define GET_TYPE_MAP(name)                 g_##name##Type

DECLARE_ITEM_TYPE(Main)


//定义类型转换
#define DEFINE_TYPE_CONVERT_FUNC_ONE(returntype, functionname, type1, type1c, type1func, membername1)  \
returntype functionname(char* pstr) { \
    returntype returnVal; \
    if (NULL == pstr) { \
        return returnVal; \
    } \
    int len = strlen(pstr); \
    *(pstr + len - 1) = '\0'; \
    pstr++; \
    char parameterbuff[MAX_PARAMETER_NUM][MAX_PARAMETER_LEN] = {""}; \
    char* pch = strtok(pstr, ","); \
    for (int i = 0; NULL != pch; i++) { \
        strcpy(parameterbuff[i], pch); \
        pch = strtok(NULL, ","); \
    } \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            returnVal.membername1 = ((type1func)(pheadtype->pfn))(parameterbuff[0]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type1c); \
        return returnVal; \
    } \
    return returnVal; \
}

#define DEFINE_TYPE_CONVERT_FUNC_TWO(returntype, functionname, type1, type1c, type1func, membername1, type2, type2c, type2func, membername2)  \
returntype functionname(char* pstr) { \
    returntype returnVal; \
    if (NULL == pstr) { \
        return returnVal; \
    } \
    int len = strlen(pstr); \
    *(pstr + len - 1) = '\0'; \
    pstr++; \
    char parameterbuff[MAX_PARAMETER_NUM][MAX_PARAMETER_LEN] = {""}; \
    char* pch = strtok(pstr, ","); \
    for (int i = 0; NULL != pch; i++) { \
        strcpy(parameterbuff[i], pch); \
        pch = strtok(NULL, ","); \
    } \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            returnVal.membername1 = ((type1func)(pheadtype->pfn))(parameterbuff[0]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type1c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type2c, pheadtype->pStrTypeName)) { \
            returnVal.membername2 = ((type2func)(pheadtype->pfn))(parameterbuff[1]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type2c); \
        return returnVal; \
    } \
    return returnVal; \
}


#define DEFINE_TYPE_CONVERT_FUNC_THREE(returntype, functionname, type1, type1c, type1func, membername1, type2, type2c, type2func, membername2, type3, type3c, type3func, membername3)  \
returntype functionname(char* pstr) { \
    returntype returnVal; \
    if (NULL == pstr) { \
        return returnVal; \
    } \
    int len = strlen(pstr); \
    *(pstr + len - 1) = '\0'; \
    pstr++; \
    char parameterbuff[MAX_PARAMETER_NUM][MAX_PARAMETER_LEN] = {""}; \
    char* pch = strtok(pstr, ","); \
    for (int i = 0; NULL != pch; i++) { \
        strcpy(parameterbuff[i], pch); \
        pch = strtok(NULL, ","); \
    } \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            returnVal.membername1 = ((type1func)(pheadtype->pfn))(parameterbuff[0]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type1c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type2c, pheadtype->pStrTypeName)) { \
            returnVal.membername2 = ((type2func)(pheadtype->pfn))(parameterbuff[1]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type2c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type3c, pheadtype->pStrTypeName)) { \
            returnVal.membername3 = ((type3func)(pheadtype->pfn))(parameterbuff[2]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type3c); \
        return returnVal; \
    } \
    return returnVal; \
}


#define DEFINE_TYPE_CONVERT_FUNC_FOUR(returntype, functionname, type1, type1c, type1func, membername1, type2, type2c, type2func, membername2, type3, type3c, type3func, membername3, type4, type4c, type4func, membername4)  \
returntype functionname(char* pstr) { \
    returntype returnVal; \
    if (NULL == pstr) { \
        return returnVal; \
    } \
    int len = strlen(pstr); \
    *(pstr + len - 1) = '\0'; \
    pstr++; \
    char parameterbuff[MAX_PARAMETER_NUM][MAX_PARAMETER_LEN] = {""}; \
    char* pch = strtok(pstr, ","); \
    for (int i = 0; NULL != pch; i++) { \
        strcpy(parameterbuff[i], pch); \
        pch = strtok(NULL, ","); \
    } \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            returnVal.membername1 = ((type1func)(pheadtype->pfn))(parameterbuff[0]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type1c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type2c, pheadtype->pStrTypeName)) { \
            returnVal.membername2 = ((type2func)(pheadtype->pfn))(parameterbuff[1]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type2c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type3c, pheadtype->pStrTypeName)) { \
            returnVal.membername3 = ((type3func)(pheadtype->pfn))(parameterbuff[2]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type3c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type4c, pheadtype->pStrTypeName)) { \
            returnVal.membername4 = ((type4func)(pheadtype->pfn))(parameterbuff[3]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type4c); \
        return returnVal; \
    } \
    return returnVal; \
}


#define DEFINE_TYPE_CONVERT_FUNC_FIVE(returntype, functionname, type1, type1c, type1func, membername1, type2, type2c, type2func, membername2, type3, type3c, type3func, membername3, type4, type4c, type4func, membername4, type5, type5c, type5func, membername5)  \
returntype functionname(char* pstr) { \
    returntype returnVal; \
    if (NULL == pstr) { \
        return returnVal; \
    } \
    int len = strlen(pstr); \
    *(pstr + len - 1) = '\0'; \
    pstr++; \
    char parameterbuff[MAX_PARAMETER_NUM][MAX_PARAMETER_LEN] = {""}; \
    char* pch = strtok(pstr, ","); \
    for (int i = 0; NULL != pch; i++) { \
        strcpy(parameterbuff[i], pch); \
        pch = strtok(NULL, ","); \
    } \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            returnVal.membername1 = ((type1func)(pheadtype->pfn))(parameterbuff[0]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type1c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type2c, pheadtype->pStrTypeName)) { \
            returnVal.membername2 = ((type2func)(pheadtype->pfn))(parameterbuff[1]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type2c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type3c, pheadtype->pStrTypeName)) { \
            returnVal.membername3 = ((type3func)(pheadtype->pfn))(parameterbuff[2]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type3c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type4c, pheadtype->pStrTypeName)) { \
            returnVal.membername4 = ((type4func)(pheadtype->pfn))(parameterbuff[3]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type4c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type5c, pheadtype->pStrTypeName)) { \
            returnVal.membername5 = ((type5func)(pheadtype->pfn))(parameterbuff[4]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type5c); \
        return returnVal; \
    } \
    return returnVal; \
}


#define DEFINE_TYPE_CONVERT_FUNC_SIX(returntype, functionname, type1, type1c, type1func, membername1, type2, type2c, type2func, membername2, type3, type3c, type3func, membername3, type4, type4c, type4func, membername4, type5, type5c, type5func, membername5, type6, type6c, type6func, membername6)  \
returntype functionname(char* pstr) { \
    returntype returnVal; \
    if (NULL == pstr) { \
        return returnVal; \
    } \
    int len = strlen(pstr); \
    *(pstr + len - 1) = '\0'; \
    pstr++; \
    char parameterbuff[MAX_PARAMETER_NUM][MAX_PARAMETER_LEN] = {""}; \
    char* pch = strtok(pstr, ","); \
    for (int i = 0; NULL != pch; i++) { \
        strcpy(parameterbuff[i], pch); \
        pch = strtok(NULL, ","); \
    } \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            returnVal.membername1 = ((type1func)(pheadtype->pfn))(parameterbuff[0]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type1c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type2c, pheadtype->pStrTypeName)) { \
            returnVal.membername2 = ((type2func)(pheadtype->pfn))(parameterbuff[1]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type2c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type3c, pheadtype->pStrTypeName)) { \
            returnVal.membername3 = ((type3func)(pheadtype->pfn))(parameterbuff[2]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type3c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type4c, pheadtype->pStrTypeName)) { \
            returnVal.membername4 = ((type4func)(pheadtype->pfn))(parameterbuff[3]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type4c); \
        return returnVal; \
    } \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type5c, pheadtype->pStrTypeName)) { \
            returnVal.membername5 = ((type5func)(pheadtype->pfn))(parameterbuff[4]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type5c); \
        return returnVal; \
    } \
    return returnVal; \
    pheadtype = GET_TYPE_MAP(Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type6c, pheadtype->pStrTypeName)) { \
            returnVal.membername6 = ((type6func)(pheadtype->pfn))(parameterbuff[5]); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        printf("%s do not have parameters type replace, you have to define this function!\n", type6c); \
        return returnVal; \
    } \
    return returnVal; \
}


#endif