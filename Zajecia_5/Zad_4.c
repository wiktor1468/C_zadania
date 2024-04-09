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

void remove_by_index(node_t **head, int index){
    if (*head == NULL) return; // Lista jest pusta

    if (index == 0) {
        node_t *temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    node_t *current = *head;
    node_t *previous = NULL;
    int i = 0;

    while (current != NULL && i < index) {
        previous = current;
        current = current->next;
        i++;
    }

    if (current == NULL) {
        printf("Indeks przekracza długość listy.\n");
        return;
    }

    previous->next = current->next;
    free(current); //zwolnie pamieci zajmowanej przez element o szukanym indeksie




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

    remove_by_index(&head,0);
    print_list(head); //after removing


    //free allocated memory
    while (head != NULL) {
        node_t *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}