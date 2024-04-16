//
// Created by wikto on 16.04.2024.
//

#include <stdio.h>

int main()
{

    int tab[10];


    for (int i = 0; i < 10; i++) {
        tab[i] = i;
    }

    int *pointer = &tab[0];//point to the 1st element in the array
    //printf("%x, has value: %d",pointer, *pointer);

    //iteration
    while(pointer != &tab[10]){
        printf("%x  , has value: %d\n",pointer, *pointer);
        pointer++;
    }



    return 0;
}