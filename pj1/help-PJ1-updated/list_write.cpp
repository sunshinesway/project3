// Cheyenne Swasey
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
    // print error if malloc fails
    if (!newNode) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(1);
    }
    // assign key value to newNode key field
    newNode->key = key;

    // update head of List to be newNode
    newNode->next = List->head;
    List->head = newNode;
}

// Append a NEW node with the key at the tail of List
void listAppend(LIST *List, double key) {
    // allocate memory for newNode
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    // print error if malloc fails
    if (!newNode) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(1);
    }
    // assign key value to newNode key field
    newNode->key = key;
    // make newNode next field NULL as the List tail
    newNode->next = NULL;

    // if List empty, newNode is new head
    // else, iterate through List until end, then add newNode to be tail
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
    // create 2 nodes to iterate through List
    NODE *curr = List->head;
    NODE *prev = NULL;

    // Search for the node with key until end of List
    while (curr != NULL) {
        if (curr->key == key) {
            // Node with key found
            if (prev == NULL) {
                // Key at Head, update head to node after curr/deleted node
                List->head = curr->next;
            } else {
                // Key elsewhere in List
                // update prev node to node after Deleted/curr node
                prev->next = curr->next;
            }
            // free mallocd space for deleted node
            free(curr);
            return;
        }
        // move to next node in List
        prev = curr;
        curr = curr->next;
    }
}
