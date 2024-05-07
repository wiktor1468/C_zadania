//
// Created by wikto on 16.04.2024.
//
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int sub(int a, int b) {
    return a - b;
}
int main()
{

    char vowels[][5] = {
            {'A', 'E', 'I', 'O', 'U'},
            {'a', 'e', 'i', 'o', 'u'}
    };
    printf("%c", vowels[1][3]);
    // Function pointer declaration
    int (*operation)(int, int);

    int num1, num2;
    int choice;


    printf("Choose operation:\n");
    printf("1 - Add\n");
    printf("2 - Multiplication\n");
    printf("3 - Sub\n");

    scanf(" %d", &choice);

    // Assigning function pointer based on user choice
    switch (choice) {
        case 1 :
            operation = add;
            break;
        case 2:
            operation = multiply;
            break;
        case 3:
            operation = sub;
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Calling function using function pointer
    int res = operation(num1, num2);

    printf("Res: %d\n", res);
    return 0;
}