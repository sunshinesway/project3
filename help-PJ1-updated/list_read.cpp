#include <stdio.h>
#include <string.h>
#include "list_read.h"

// Function to print the contents of the list to stdout
void listPrint(LIST *List) {
    NODE *pNODE = List->head;
    while (pNODE) {
        std::cout << pNODE->key << std::endl;
        pNODE = pNODE->next;
    }
}

// Function to find and return the maximum key in the list
double listMax(LIST *List) {
    double max = List->head->key;
    NODE *pNODE = List->head->next;

    while (pNODE) {
        if (pNODE->key > max) {
            max = pNODE->key;
        }
        pNODE = pNODE->next;
    }

    return max;
}