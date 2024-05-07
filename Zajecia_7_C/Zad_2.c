//
// Created by wikto on 07.05.2024.
//DOESNT WORK
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the hash table
typedef struct Node {
    char color[20];
    int number;
    struct Node* next;
} Node;

// Function to create a new node with the given color and number
Node* createNode(const char* color, int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->color, color);
    newNode->number = number;
    newNode->next = NULL;
    return newNode;
}
// Function to calculate the hash value for a given color
int hash(const char* color) {
    // Simple hash function that sums the ASCII values of characters in the color string
    int sum = 0;
    for (int i = 0; color[i] != '\0'; i++) {
        sum += color[i];
    }
    return sum % 10; // Modulo operation to fit within the table size
}

// Function to insert a new node into the hash table
void insert(Node** table, const char* color, int number) {
    int index = hash(color); // Calculate the hash value
    Node* newNode = createNode(color, number); // Create a new node
    if (table[index] == NULL) {
        table[index] = newNode; // If the slot is empty, insert the node
    } else {
        newNode->next = table[index]; // If collision occurs, add the node to the beginning of the linked list
        table[index] = newNode;
    }
}



// Function to print the hash table
void printHashTable(Node** table, int size) {
    printf("Dictionary:\n");
    for (int i = 0; i < size; i++) {
        Node* current = table[i];
        while (current != NULL) {
            printf("%s: %d\n", current->color, current->number);
            current = current->next;
        }
    }
}

int main() {
    FILE* file = fopen("..\\Zajecia_7_C\\input2.txt", "r"); // Open the file for reading
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    Node* hashTable[10] = {NULL}; // Initialize the hash table with NULL pointers
    char color[20];
    int number;

    if (fscanf(file, "%s %d", color, &number) == 2) { // Read color and number pairs from the first row of the file
        insert(hashTable, color, number); // Insert into the hash table
    }

    fclose(file); // Close the file

    // Print the hash table
    printHashTable(hashTable, 10);

    return 0;
}
