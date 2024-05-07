//
// Created by wikto on 07.05.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_SIZE 9 // Maximum number of elements in the map

int size = 0; // Current number of elements in the map
int keys[MAX_SIZE]; // Array to store the keys (digits)
char values[MAX_SIZE][100]; // Array to store the values (strings)

// Function to get the index of a key in the keys array
int getIndex(int key) {
    for (int i = 0; i < size; i++) {
        if (keys[i] == key) {
            return i;
        }
    }
    return -1; // Key not found
}

// Function to insert a key-value pair into the map
void insert(int key, char value[]) {

    int index = getIndex(key);
    if (index == -1) { // Key not found
        keys[size] = key;
        strcpy(values[size], value);
        size++;
    } else { // Key found
        strcpy(values[index], value);
    }
}

//Fuction to get value of a key
char* get(int key){
    int index = getIndex(key);
    if (index == -1) { // Key not found
        return NULL;
    } else { // Key found
        return values[index];
    }
}

void printMap() {
    for (int i = 0; i < size; i++) {
        printf("%d: %s\n", keys[i], values[i]);
    }
}
int main(){
    insert(1, "One");
    insert(2, "Two");
    insert(3, "Three");
    insert(4, "Four");
    insert(5, "Five");
    insert(6, "Six");
    insert(7, "Seven");
    insert(8, "Eight");
    insert(9, "Nine");

    printf("Value of complete Map: \n");
    printMap();

    FILE* ptr;
    char ch;

    // Opening file in reading mode
    //ptr = fopen("..\\Zajecia_7_C\\input.txt", "r");
    ptr = fopen("..\\Zajecia_7_C\\test.txt", "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }


    // Printing what is written in file
    // character by character using loop.
    do {
        ch = fgetc(ptr);
        printf("%c", ch);

        // Checking if character is not EOF.
    } while (ch != EOF);
    fclose(ptr);





    return 0;
}