//
// Created by wikto on 22.02.2024.
//
#include <cstdio>
int main() {
    printf("Podaj liczbe: ");
    int maxVal=0;
    scanf("%d",&maxVal);

    int suma=0;
    if(maxVal<0)
    {
        printf("0");
        return 0;
    }

    for(int i=1; i<=maxVal; i++)
    {
        if(i%3==0 && i%5==0)
        {
            suma+=i;
        }
        else if(i%3==0 || i%5==0)
        {
            suma+=i;
        }

    }
    printf("Suma to: %d",suma);
    return 0;
}
