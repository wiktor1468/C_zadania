//
// Created by wikto on 04.03.2024.
//
#include "stdio.h"
void makeDouble(float *x)
{
    (*x)*=2;
}

int main(){

    float x=3.0;
    printf("%f\n",x);
    makeDouble(&x);
    //after
    printf("After function: %f",x);




    return 0;
}