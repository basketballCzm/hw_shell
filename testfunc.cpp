#include <stdio.h>
#include "testfunc.h"

void f() {
    printf("this is f\n");
}

void f1(char *pstr) {
    printf("this is f1 %s\n", pstr);
}

void f2(char *pstr, char *pstr1) {
    printf("this is f2 %s, %s\n", pstr, pstr1);
}

void f3(char *pstr, int cnt) {
    printf("this is f3 %s, %d\n", pstr, cnt);
}

