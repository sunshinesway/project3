// 1227888508

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_write.h"
#include "util.h"

// Insert a NEW node with the key at the head of List
void listInsert(LIST *List, double key) {
    // allocate memory for newNode
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(1);
    }

    newNode->key = key;
    newNode->next = List->head;
    List->head = newNode;
}

// Append a NEW node with the key at the tail of List
void listAppend(LIST *List, double key) {
    // allocate memory for newNode
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(1);
    }

    newNode->key = key;
    newNode->next = NULL;

    if (!List->head) {
        List->head = newNode;
    } else {
        NODE *pNODE = List->head;
        while (pNODE->next) {
            pNODE = pNODE->next;
        }
        pNODE->next = newNode;
    }
}
// Delete a node with the key from List
void listDelete(LIST *List, double key) {
    NODE *curr = List->head;
    NODE *prev = NULL;

    // Search for the node with key
    while (curr != NULL) {
        if (curr->key == key) {
            // Node with key found
            if (prev == NULL) {
                // Key at Head
                List->head = curr->next;
            } else {
                // Key elsewhere in List
                prev->next = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}
