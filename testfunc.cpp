#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "testfunc.h"

void f() {
    sleep(3);
    printf("this is f\n");
}

int f1(char *pstr) {
    printf("this is f1 %s\n", pstr);
    return 1000;
}

void f2(char *pstr, char *pstr1) {
    printf("this is f2 %s, %s\n", pstr, pstr1);
}

void f3(char *pstr, int cnt) {
    printf("this is f3 %s, %d\n", pstr, cnt);
}

/*struct CZM {
    char *pstr;
    int int_num;
    float float_num;
    double double_num;
    long long_num;
    char *pstr1;
};*/

CZM f4(CZM czm) {
    printf("this is czm struct %s, %d, %f, %f, %ld, %s\n", czm.pstr, czm.int_num, czm.float_num, czm.double_num, czm.long_num, czm.pstr1);
    return czm;
}

