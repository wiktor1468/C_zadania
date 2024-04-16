//
// Created by wikto on 16.04.2024.
//
#include <stdio.h>

union data{
    int intNum;
    float floatNum;
    char charSymbol;

};
int main(){

    union data d1;
    d1.intNum=5;
    printf("%d  \n",d1.intNum);

    d1.floatNum = 23.47;
    printf("float: %.2f\n", d1.floatNum);

    d1.charSymbol = 'J';
    printf("char: %c\n", d1.charSymbol);

    
    return 0;

}