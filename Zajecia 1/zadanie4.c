//
// Created by wikto on 21.02.2024.
//
#include <cstdio>
int main()
{
    for (int i = 1; i <= 200; i++) {
        if (i % 5 == 0 && i % 7 == 0) {
            printf("FooBar\n");
        } else if (i % 5 == 0) {
            printf("Foo\n");
        } else if (i % 7 == 0) {
            printf("Bar\n");
        } else {
            printf("%d\n", i);
        }
        return 0;
    }
}
