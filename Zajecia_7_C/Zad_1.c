#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to represent a node in the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(Node **head, int data) {
    Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to free the memory allocated to the linked list
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to convert word representations of numbers to their numerical equivalents
int wordToNumber(const char *word) {
    if (strcmp(word, "zero") == 0) return 0;
    if (strcmp(word, "one") == 0) return 1;
    if (strcmp(word, "two") == 0) return 2;
    if (strcmp(word, "three") == 0) return 3;
    if (strcmp(word, "four") == 0) return 4;
    if (strcmp(word, "five") == 0) return 5;
    if (strcmp(word, "six") == 0) return 6;
    if (strcmp(word, "seven") == 0) return 7;
    if (strcmp(word, "eight") == 0) return 8;
    if (strcmp(word, "nine") == 0) return 9;
    return -1; // Not a valid word representation of a number
}

int main() {
    FILE *file = fopen("..\\Zajecia_7_C\\input.txt", "r"); // Open the file for reading
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    char line[100]; // Assuming maximum line length is 100 characters
    Node *head = NULL; // Initialize the linked list head
    while (fgets(line, sizeof(line), file)) { // Read lines from the file
        char numberStr[20]; // Buffer to store the word representation of a number
        int wordIndex = 0; // Index to track the current position in the word
        int isFirstNumber = 1; // Flag to indicate whether it's the first number in the row
        for (int index = 0; line[index] != '\0'; ++index) { // Iterate over each character in the line
            if (isalpha(line[index])) { // If the character is alphabetic
                numberStr[wordIndex++] = line[index]; // Add it to the word
            } else { // If the character is non-alphabetic
                if (wordIndex > 0) { // If we have a word to process
                    numberStr[wordIndex] = '\0'; // Null-terminate the string
                    int number = wordToNumber(numberStr); // Convert the word to a number
                    if (number != -1) { // If a valid number is found
                        if (isFirstNumber) { // If it's the first number in the row
                            number *= 10; // Multiply it by 10
                            isFirstNumber = 0; // Reset the flag
                        }
                        insertNode(&head, number); // Insert the number into the linked list
                    }
                    wordIndex = 0; // Reset the word index
                }
            }
        }
    }

    fclose(file); // Close the file

    // Calculate the sum of numbers in the linked list
    int sum = 0;
    Node *current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }

    // Print the sum
    printf("Sum of numbers: %d\n", sum);

    // Free the memory allocated to the linked list
    freeList(head);

    return 0;
}
