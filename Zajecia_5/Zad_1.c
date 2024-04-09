//
// Created by wikto on 26.03.2024.
//
#include "stdio.h"
#include "stdlib.h"


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


int main(){

    node_t *head = NULL;
    head = (node_t *) malloc(sizeof(node_t)); //returns a pointer to the allocated memory, or NULL.
    if (head == NULL) {
        return 1;
    }


    head->val = 12;
    head->next = NULL; //indicating that it's the last node

    print_list(head);

    free(head); // Free the allocated memory.



    return 0;
}