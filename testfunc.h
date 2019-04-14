#ifndef __TESTFUNC_H__
#define __TESTFUNC_H__
void f();

void f1(char *pstr);

void f2(char *pstr, char *pstr1);

void f3(char *pstr, int cnt);

struct CZM {
    char *pstr;
    int int_num;
    float float_num;
    double double_num;
    long long_num;
    char *pstr1;
};

void f4(CZM czm);

#endif
