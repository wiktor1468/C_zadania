//
// Created by wikto on 11.03.2024.
//
#include <stdio.h>
#include "stdlib.h"

int validateInput(int *value) {
    char term;
    int validInput = 0;

    while (!validInput) {
        if (scanf("%d%c", value, &term) == 2 && term == '\n') {
            validInput = 1;
        } else {
            printf("Invalid input. Please enter a valid integer.\n");
            while (getchar() != '\n');  // Clear the input buffer
        }
    }

    return 1;  // Indicates that the input is valid
}

int main(){


    int ncols;
    int nrows;
    int i, j;

    printf("Enter the number of cols: ");
    validateInput(&ncols);

    printf("Enter the number of rows: ");
    validateInput(&nrows);


// Allocate memory for nrows pointers
    int **pvalues = (int **) malloc(nrows * sizeof(int *));

// For each row, allocate memory for ncols elements
    for(i=0; i<nrows;i++) {
        pvalues[i] = (int *) malloc(ncols * sizeof(int));

    }

    for (i = 0; i < nrows; i++) {
        for(j = 0; j < ncols; j++) {
            int random = rand() ;
            pvalues[i][j] = random;
        }
    }

    //display
    for (i = 0; i < nrows; i++) {
        for (j = 0; j < ncols; j++) {
            printf("%d ", pvalues[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    for (i = 0; i < nrows; i++) {
        free(pvalues[i]); // free the memory for each individual row
    }
    free(pvalues); // Free the top-level pointer, releases the memory that was initially allocated

    return 0;
}