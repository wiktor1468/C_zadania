//
// Created by wikto on 26.02.2024.
//
#include <string.h>
#include "stdio.h"



int main() {
    printf("Podaj ilosc rund");

    int iloscRund =0;
    scanf("%d",&iloscRund);
    int res[iloscRund][3];  // Zmieniony typ na int

    for (int i = 0; i < iloscRund; ++i) {
        printf("Podaj ruch: (p=papier, k=kamien, n=nozyce)\n");
        char move1;
        scanf(" %c", &move1);  // Zmieniony sposób wczytywania na %c

        printf("Podaj ruch: (p=papier, k=kamien, n=nozyce)\n");
        char move2;
        scanf(" %c", &move2);  // Zmieniony sposób wczytywania na %c

        res[i][0] = move1;
        res[i][1] = move2;

        // Warunki gry
        if (move1 == move2) {
            res[i][2] = 0;  // Remis
        } else if ((move1 == 'p' && move2 == 'k') || (move1 == 'k' && move2 == 'n') || (move1 == 'n' && move2 == 'p')) {
            res[i][2] = 1;  // Wygrywa gracz 1
        } else {
            res[i][2] = 2;  // Wygrywa gracz 2
        }


    }

    //wyswietlanie
    printf("Wpisz 'scores', aby zobaczyc wyniki: ");
    char komenda[10];
    scanf("%s", komenda);
    if (strcmp(komenda, "scores") == 0) {
        printf("Zawartosc tablicy :\n");
        for (int i = 0; i < iloscRund; ++i) {
            printf("%c vs %c - Wynik: %d\n", res[i][0], res[i][1], res[i][2]);
        }
    } else {
        printf("Bledna komenda.\n");
    }






    return 0;
}
