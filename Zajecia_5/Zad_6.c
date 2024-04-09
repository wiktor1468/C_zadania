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

void add_in_given_index(node_t **head, int index, int value){

    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (new_node == NULL) {
        printf("Błąd alokacji pamięci.\n");
        return;
    }
    new_node->val = value;
    new_node->next = NULL;

    // Jeśli indeks jest równy 0, wstaw węzeł na początek listy
    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Przechodzenie przez listę, aby znaleźć poprzedni węzeł dla nowego węzła
    node_t *current = *head;
    for (int i = 0; current != NULL && i < index - 1; i++) {
        current = current->next;
    }

    // Sprawdzenie, czy osiągnięto koniec listy przed wstawieniem
    if (current == NULL) {
        printf("Indeks przekracza długość listy.\n");
        free(new_node);
        return;
    }

    // Wstawienie nowego węzła po poprzednim węźle
    new_node->next = current->next;
    current->next = new_node;
}

int main()
{
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

    add_in_given_index(&head,3,16);
    print_list(head); //after removing

    return 0;
}