//
// Created by wikto on 05.03.2024.
//
//
// Created by wikto on 03.03.2024.
//
#include <stdio.h>


//#include "Zad_1.h"


int main() {


    int a=5;
    int * pA = &a; /* define a pointer variable, and point it to a using the & operator */
    printf("The value a is %d:, The value of a is also %d\n",a,*pA);


    //modyfikacja zmiennej za pomoca wskaznika
    *pA +=2;
    printf("The value a is %d:, The value of a is also %d\n",a,*pA);
    return 0;
}