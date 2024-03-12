//
// Created by wikto on 12.03.2024.
//
#include "stdio.h"

int validateInput(unsigned int *value) {
    char term;
    int validInput = 0;

    while (!validInput) {
        if (scanf("%u%c", value, &term) == 2 && term == '\n' && value>=0) {
            validInput = 1;
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n');  // Clear the input buffer
        }
    }

    return 1;  // Indicates that the input is valid
}

unsigned int factorial(unsigned int x) {
    if (x == 0 || x==1){
        return 1;
    }
    else{
        return x * factorial(x-1);
    }
}

int main(){
    unsigned int x;
    printf("Podaj liczbe: ");
    validateInput(&x);

    printf("%d", factorial(x));



    return 0;

}