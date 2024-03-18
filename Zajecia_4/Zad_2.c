//
// Created by wikto on 12.03.2024.
//
#include <stdlib.h>
#include <time.h>
#include "stdio.h"
int binarysearch(int *pnumbers, int leftindex, int rightindex, int searchvalue){
    int i;
    if(rightindex>=leftindex){
        int mid = leftindex+(rightindex-leftindex)/2;

        if (pnumbers[mid] == searchvalue)
            return mid;

        else if (pnumbers[mid] > searchvalue)
            return binarysearch(pnumbers, leftindex, mid - 1, searchvalue);
        else {

            return binarysearch(pnumbers, mid + 1, rightindex, searchvalue);
        }
    }
    // We reach here when element is not present in array
    return -1;
    }






int main(){
    int numbers[20];
    int *pnumbers = numbers;
    int i;
    int len = sizeof(numbers)/ sizeof(numbers[0]);

    /* Intializes random number generator */
    time_t t;
    srand((unsigned) time(&t));

    for( i=0; i<len; i++){
        numbers[i]=rand()%10;
    }


    //sort
    for ( i = 0; i < len-1 ; i++) {
        for (int j = 0; j < len - i - 1; ++j) {
            if (numbers[j] > numbers[j+1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
      //wyswietlenie tablicy
        for( i=0; i<len; i++){
            printf("%d ",*(numbers+i));
        }
    printf("\n");

    int res=binarysearch(pnumbers,0,len-1,9);
    printf("Indeks szukanej wartosci: %d",res);



    return 0;
}