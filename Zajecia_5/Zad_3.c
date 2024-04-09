//
// Created by wikto on 26.03.2024.
//
#include "stdlib.h"
#include "stdio.h"

typedef struct node{
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

void remove_last(node_t **head){
    // Check if the list is empty or has only one node
    if (*head == NULL || (*head)->next == NULL)
        return;


    // move the list until the second-to-last node
    node_t *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    // Free the last node
    free(current->next);

    // Set the next pointer of the second-to-last node to NULL
    current->next = NULL;

}
int main(){

    node_t *head = NULL;
    head = (node_t *) malloc(sizeof(node_t)); //returns a pointer to the allocated memory, or NULL.
    if (head == NULL) {
        return 1;
    }

    head = (node_t *) malloc(sizeof(node_t));
    head->val = 12;
    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = (node_t *) malloc(sizeof(node_t));
    head->next->next->val = 37;
    head->next->next->next = NULL;

    print_list(head); //before removing
    printf("\n");

    remove_last(&head);

    print_list(head);

    //free allocated memory
    while (head != NULL) {
        node_t *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}