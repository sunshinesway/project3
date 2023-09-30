// 1227888508

#include <stdio.h>
#include <string.h>
#include "list_read.h"

// Print the List contents
void listPrint(LIST *List) {
    NODE *pNODE = List->head;
    while (pNODE) {
        printf("%lf\n", pNODE->key);
        pNODE = pNODE->next;
    }
}

// Find the maximum key in List
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