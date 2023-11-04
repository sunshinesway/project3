// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <string.h>
#include "list_read.h"

// Print the List contents
void listPrint(LIST *List) {
    // start with head of List
    NODE *pNODE = List->head;

    //iterate through list, print each key
    while (pNODE != NULL) {
        printf("%lf\n", pNODE->key);
        pNODE = pNODE->next;
    }
}

// Find the maximum key in List
double listMax(LIST *List) {
    // start with head of List and second node to do first comparison
    double max = List->head->key;
    NODE *pNODE = List->head->next;

    //iterate through entire List, compare key values, keeping track of current max key
    while (pNODE != NULL) {
        if (pNODE->key > max) {
            max = pNODE->key;
        }
        pNODE = pNODE->next;
    }

    return max;
}