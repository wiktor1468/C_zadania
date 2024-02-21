
#include <stdio.h>

int main()
{
    //zd2
    int grades[5][2] = {
            {5, 6},
            {4, 2},
            {3, 5},
            {3, 5},
            {5, 6}
    };
    int len = sizeof(grades) / sizeof(grades[0]);
    int sumaM = 0;
    int sumaF = 0;
    //printf("%d", sizeof(grades[0])/sizeof(grades[0][0]));  //liczba kolumn

    for (int i = 0; i < len; i++)
    {
            sumaM += grades[i][0];
            sumaF += grades[i][1];
    }

    printf("Srednia z matematyki: %.2f\n", sumaM / (float)(len ));
    printf("Srednia z fizyki : %.2f\n", sumaF / (float)(len ));
    printf("%d",len);


    return 0;
}