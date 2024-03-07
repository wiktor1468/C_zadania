#include <stdio.h>
int main() {


    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < len; i++) {
        long silnia = 1;
        for (int j = 1; j <= array[i]; j++) {
            silnia *= j;
        }

        printf("Silnia liczby %d to %ld\n", array[i], silnia);
    }

    return 0;
}
