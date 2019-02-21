#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typesmap.h"

char* strtostr(char* pstr) {
    return pstr;
}

int strtoint(char* pstr) {
    return atoi(pstr);
}

float strtofloat(char* pstr) {
    return atof(pstr);
}

/*std::string strtostring(char* pstr) {
    return std::string(pstr);
}*/

double strtodouble(char* pstr) {
    return atof(pstr);
}

long strtolong(char* pstr) {
    return atol(pstr);
}


BEGIN_ITEM_TYPE(Main)
ITEM_TYPE("char*", (void*)strtostr)
ITEM_TYPE("int", (void*)strtoint)
ITEM_TYPE("float", (void*)strtofloat)
//ITEM_TYPE("string", (void*)strtostring)
ITEM_TYPE("double", (void*)strtodouble)
ITEM_TYPE("long", (void*)strtolong)
END_ITEM_TYPE()