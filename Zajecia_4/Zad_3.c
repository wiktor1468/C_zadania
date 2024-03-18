//
// Created by wikto on 15.03.2024.
//
#include "stdio.h"
void permute(int *array, int start, int end){
    int j;
    if(start==end)
    {
        for (int i = 0; i <= end; i++){ //function has generated a permutation
            printf("%d ",array[i]);
        }
        printf("\n");
    }
    else{
        for(j=start; j<=end; j++){
            int temp =array[start];
            array[start]=array[j]; // swaps the element at the start index with the element at the current index (j)
            array[j] = temp;

            permute(array, start+1, end);

            // Backtrack: restore to original
            temp = array[start];
            array[start] = array[j];
            array[j] = temp;
        }
    }

}
int main(){
    int array[4]={1,2,3,4};
    int *parray = array;
    permute(parray,0,sizeof(array)/ sizeof(array[0])-1);

    return 0;
}