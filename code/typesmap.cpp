#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typesmap.h"

char* strtostr(char* pstr) {
    return pstr;
}

int strtoint(char* pstr) {
    if (NULL == pstr) {
        return 0;
    }
    return atoi(pstr);
}

float strtofloat(char* pstr) {
    if (NULL == pstr) {
        return 0;
    }
    return atof(pstr);
}

/*std::string strtostring(char* pstr) {
    return std::string(pstr);
}*/

double strtodouble(char* pstr) {
    if (NULL == pstr) {
        return 0;
    }
    return strtod(pstr, NULL);
}

long strtolong(char* pstr) {
    if (NULL == pstr) {
        return 0;
    }
    return atol(pstr);
}

CZM strtoczm(char* pstr) {
    CZM czm;
    if (NULL == pstr) {
        return czm;
    }
    int len = strlen(pstr);
    //去掉'}'
    *(pstr + len - 1) = '\0';
    pstr++;
    char parameterbuff[MAX_PARAMETER_NUM][MAX_PARAMETER_LEN] = {""};
    char* pch = strtok(pstr, ",");
    for (int i = 0; NULL != pch; i++) {
        strcpy(parameterbuff[i], pch);
        pch = strtok(NULL, ",");
    }

    czm.pstr = strtostr(parameterbuff[0]);
    czm.int_num = strtoint(parameterbuff[1]);
    czm.float_num = strtofloat(parameterbuff[2]);
    czm.double_num = strtodouble(parameterbuff[3]);
    czm.long_num = strtolong(parameterbuff[4]);
    czm.pstr1 = strtostr(parameterbuff[5]);

    return czm;

}

/*DEFINE_TYPE_CONVERT_NUM_SIX(CZM, strtoczm, char*, "char*", char*(*)(char*), pstr, int, "int", int(*)(char*), int_num, float, "float", float(*)(char*), float_num, double, "double", double(*)(char*), double_num, long, "long", long(*)(char*), long_num, char*, "char*", char*(*)(char*), pstr1)*/


BEGIN_ITEM_TYPE(Main)
ITEM_TYPE("char*", (void*)strtostr)
ITEM_TYPE("int", (void*)strtoint)
ITEM_TYPE("float", (void*)strtofloat)
//ITEM_TYPE("string", (void*)strtostring)
ITEM_TYPE("double", (void*)strtodouble)
ITEM_TYPE("long", (void*)strtolong)
ITEM_TYPE("CZM", (void*)strtoczm)
END_ITEM_TYPE()

