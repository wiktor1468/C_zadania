//
// Created by wikto on 09.04.2024.
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

void remove_by_given_value(node_t **head, int value){

    if (*head == NULL) return; // Lista jest pusta




    node_t *current = *head;
    node_t *previous = NULL;
    int i;

    while (current != NULL && current->val!=value) {
        previous = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Węzeł o podanej wartości nie został znaleziony.\n");
        return;
    }

    // Usuń węzeł z podaną wartością
    if (previous == NULL) {
        // Węzeł o wartości do usunięcia jest pierwszym węzłem
        *head = current->next;
    } else {
        // Węzeł o wartości do usunięcia jest wewnętrznym węzłem
        previous->next = current->next;
    }

    free(current); // Zwolnij pamięć po usuniętym węźle


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

    remove_by_given_value(&head,37);
    print_list(head); //after removing


    return 0;
}