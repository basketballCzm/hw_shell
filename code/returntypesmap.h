#ifndef __RETURNTYPESMAP_H__
#define __RETURNTYPESMAP_H__

//定义类型转换
#define DEFINE_RETURN_TYPE_CONVERT_NUM_ONE(returntype, functionname, type1, type1c, type1func, membername1)  \
void functionname(returntype returnVal, char* pstr) { \
    if (NULL == pstr) { \
        return ; \
    } \
    char szBuff[MAX_PARAMETER_LEN] = ""; \
    strcat(pstr, "{"); \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            ((type1func)(pheadtype->pfn))(returnVal.membername1, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type1c); \
        strcat(pstr,szBuff); \
    } \
    pstr[strlen(pstr)-1] = '}'; \
}

#define DEFINE_RETURN_TYPE_CONVERT_NUM_TWO(returntype, functionname, type1, type1c, type1func, membername1, type2, type2c, type2func, membername2)  \
void functionname(returntype returnVal, char* pstr) { \
    if (NULL == pstr) { \
        return; \
    } \
    char szBuff[MAX_PARAMETER_LEN] = ""; \
    strcat(pstr, "{"); \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            ((type1func)(pheadtype->pfn))(returnVal.membername1, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type1c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type2c, pheadtype->pStrTypeName)) { \
            ((type2func)(pheadtype->pfn))(returnVal.membername2, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type2c); \
        strcat(pstr,szBuff); \
    } \
    pstr[strlen(pstr)-1] = '}'; \
}


#define DEFINE_RETURN_TYPE_CONVERT_NUM_THREE(returntype, functionname, type1, type1c, type1func, membername1, type2, type2c, type2func, membername2, type3, type3c, type3func, membername3)  \
void functionname(returntype returnVal, char* pstr) { \
    if (NULL == pstr) { \
        return ; \
    } \
    char szBuff[MAX_PARAMETER_LEN] = ""; \
    strcat(pstr, "{"); \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            ((type1func)(pheadtype->pfn))(returnVal.membername1, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type1c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type2c, pheadtype->pStrTypeName)) { \
            ((type2func)(pheadtype->pfn))(returnVal.membername2, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type2c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type3c, pheadtype->pStrTypeName)) { \
            ((type3func)(pheadtype->pfn))(returnVal.membername3, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type3c); \
        strcat(pstr,szBuff); \
    } \
    pstr[strlen(pstr)-1] = '}'; \
}


#define DEFINE_RETURN_TYPE_CONVERT_NUM_FOUR(returntype, functionname, type1, type1c, type1func, membername1, type2, type2c, type2func, membername2, type3, type3c, type3func, membername3, type4, type4c, type4func, membername4)  \
void functionname(returntype returnVal, char* pstr) { \
    if (NULL == pstr) { \
        return ; \
    } \
    char szBuff[MAX_PARAMETER_LEN] = ""; \
    strcat(pstr, "{"); \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            ((type1func)(pheadtype->pfn))(returnVal.membername1, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type1c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type2c, pheadtype->pStrTypeName)) { \
            ((type2func)(pheadtype->pfn))(returnVal.membername2, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type2c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type3c, pheadtype->pStrTypeName)) { \
            ((type3func)(pheadtype->pfn))(returnVal.membername3, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type3c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type4c, pheadtype->pStrTypeName)) { \
            ((type4func)(pheadtype->pfn))(returnVal.membername4, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type4c); \
        strcat(pstr,szBuff); \
    } \
    pstr[strlen(pstr)-1] = '}'; \
}


#define DEFINE_RETURN_TYPE_CONVERT_NUM_FIVE(returntype, functionname, type1, type1c, type1func, membername1, type2, type2c, type2func, membername2, type3, type3c, type3func, membername3, type4, type4c, type4func, membername4, type5, type5c, type5func, membername5)  \
void functionname(returntype returnVal, char* pstr) { \
    if (NULL == pstr) { \
        return ; \
    } \
    char szBuff[MAX_PARAMETER_LEN] = ""; \
    strcat(pstr, "{"); \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            ((type1func)(pheadtype->pfn))(returnVal.membername1, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type1c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type2c, pheadtype->pStrTypeName)) { \
            ((type2func)(pheadtype->pfn))(returnVal.membername2, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type2c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type3c, pheadtype->pStrTypeName)) { \
            ((type3func)(pheadtype->pfn))(returnVal.membername3, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type3c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type4c, pheadtype->pStrTypeName)) { \
            ((type4func)(pheadtype->pfn))(returnVal.membername4, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type4c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type5c, pheadtype->pStrTypeName)) { \
            ((type5func)(pheadtype->pfn))(returnVal.membername5, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type5c); \
        strcat(pstr,szBuff); \
    } \
    pstr[strlen(pstr)-1] = '}'; \
}


#define DEFINE_RETURN_TYPE_CONVERT_NUM_SIX(returntype, functionname, type1, type1c, type1func, membername1, type2, type2c, type2func, membername2, type3, type3c, type3func, membername3, type4, type4c, type4func, membername4, type5, type5c, type5func, membername5, type6, type6c, type6func, membername6)  \
void functionname(returntype returnVal, char* pstr) { \
    if (NULL == pstr) { \
        return ; \
    } \
    char szBuff[MAX_PARAMETER_LEN] = ""; \
    strcat(pstr, "{"); \
    TYPE_MAP* pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type1c, pheadtype->pStrTypeName)) { \
            ((type1func)(pheadtype->pfn))(returnVal.membername1, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type1c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type2c, pheadtype->pStrTypeName)) { \
            ((type2func)(pheadtype->pfn))(returnVal.membername2, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type2c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type3c, pheadtype->pStrTypeName)) { \
            ((type3func)(pheadtype->pfn))(returnVal.membername3, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type3c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type4c, pheadtype->pStrTypeName)) { \
            ((type4func)(pheadtype->pfn))(returnVal.membername4, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type4c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type5c, pheadtype->pStrTypeName)) { \
            ((type5func)(pheadtype->pfn))(returnVal.membername5, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type5c); \
        strcat(pstr,szBuff); \
    } \
    pheadtype = GET_TYPE_MAP(Return_Main); \
    while (NULL != pheadtype->pStrTypeName) { \
        if (0 == strcmp(type6c, pheadtype->pStrTypeName)) { \
            ((type6func)(pheadtype->pfn))(returnVal.membername6, szBuff); \
            strcat(pstr,szBuff); \
            strcat(pstr," ,"); \
            break; \
        } \
        pheadtype++; \
    } \
    if (NULL == pheadtype->pStrTypeName) { \
        sprintf(szBuff, "%s not ", type6c); \
        strcat(pstr,szBuff); \
    } \
    pstr[strlen(pstr)-1] = '}'; \
}

#endif