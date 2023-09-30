#include <stdio.h>
#include <string.h>
#include "list_write.h"
#include "util.h"  // Include your custom header files

// Function to insert a new node with the given key at the head of the list
void listInsert(LIST *List, double key) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode) {
        std::cerr << "Error: malloc failed" << std::endl;
        exit(1);
    }

    newNode->key = key;
    newNode->next = List->head;
    List->head = newNode;
}

// Function to append a new node with the given key at the tail of the list
void listAppend(LIST *List, double key) {
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode) {
        std::cerr << "Error: malloc failed" << std::endl;
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
