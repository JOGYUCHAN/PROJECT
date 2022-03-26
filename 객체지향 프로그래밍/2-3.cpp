#include<iostream>
using namespace std;

void f1(){
    int i1 = 10;
    int i2 = 20;
    const int* pInt1;

    pInt1 = &i1;
    *pInt1 = 30;
}

void f2(){
    int i1 = 10;
    int i2 = 20;
    int* const pInt1;

    pInt1 = &i1;
    *pInt1 = 30;
}

void f3(){
    int i1 = 10;
    int i2 = 20;
    const int* const pInt1;

    pInt1 = &i1;
    *pInt1 = 30;
}
