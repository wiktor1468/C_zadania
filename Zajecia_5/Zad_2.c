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

void pop_first(node_t **head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);
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
    head->next->next = NULL;

    print_list(head); //before removing

    pop_first(&head);
    printf("\n");
    print_list(head);

    //free allocated memory
    while (head != NULL) {
        node_t *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}