#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typesmap.h"
#include "returntypesmap.h"

void strtostr(char* pstrs , char* pstrd) {
	if (NULL != pstrd && NULL != pstrs) {
		strcpy(pstrd, pstrs);
	}
}

void inttostr(int num, char* pstr) {
	if (NULL != pstr) {
		sprintf(pstr, "%d", num);
	}
}

void floattostr(float num, char* pstr) {
	if (NULL != pstr) {
		sprintf(pstr, "%f", num);
	}
}

void doubletostr(double num, char* pstr) {
	if (NULL != pstr) {
		sprintf(pstr, "%f", num);
	}
}

void longtostr(long num, char* pstr) {
	if (NULL != pstr) {
		sprintf(pstr, "%ld", num);
	}
}

/*void CZMtostr(CZM czm, char* pstr) {
	if (NULL == pstr) {
		return;
	}

	sprintf(pstr, "{%s, %d, %f, %f, %ld, %s}", czm.pstr, czm.int_num, czm.float_num, czm.double_num, czm.long_num, czm.pstr1);
}*/


DEFINE_RETURN_TYPE_CONVERT_NUM_SIX(CZM, CZMtostr, char*, "char*", void(*)(char*, char*), pstr, int, "int", void(*)(int, char*), int_num, float, "float", void(*)(float, char*), float_num, double, "double", void(*)(double, char*), double_num, long, "long", void(*)(long, char*), long_num, char*, "char*", void(*)(char*, char*), pstr1)

BEGIN_ITEM_TYPE(Return_Main)
ITEM_TYPE("char*", (void*)strtostr)
ITEM_TYPE("int", (void*)inttostr)
ITEM_TYPE("float", (void*)floattostr)
//ITEM_TYPE("string", (void*)strtostring)
ITEM_TYPE("double", (void*)doubletostr)
ITEM_TYPE("long", (void*)longtostr)
ITEM_TYPE("CZM", (void*)CZMtostr)
END_ITEM_TYPE()