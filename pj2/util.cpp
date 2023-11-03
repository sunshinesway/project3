#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

int getNext(char *command){
    double key;

    if(strcmp(command, "Stop")==0)
        exit(0);

    else if(strcmp(command, "Init")) {
        fscanf(stdin, "%s", command);
        key = std::stod(command);

    }

    else if(strcmp(command, "Print")){

    }

    else if(strcmp(command, "Write")){

    }

    else if(strcmp(command, "Read")){

    }

    else if(strcmp(command, "Insert")){

    }

    else if(strcmp(command, "ExtractMin")){

    }

    else if(strcmp(command, "DecreaseKey")){

    }
    else {
        fprintf(stderr, "Warning: Invalid instruction\n");
    }
}

HEAP* initArray(int cap) {
    HEAP *heap = (HEAP *)calloc(1, sizeof(HEAP));
        if (!heap) {
            fprintf(stderr, "Error: memory allocation failed for Heap\n");
            exit(0);
        }
    heap->capacity = cap;
    heap->size = 0;

    return heap;
}

void printArray(HEAP *heap) {

}

void writeArray() {

}

void readIn() {

}



void swap(HEAP *heap, int itemInd1, int itemInd2) {

    //create temp element for swapping
    ELEMENT *temp = NULL;
    ELEMENT *item1 = heap->A[itemInd1];
    ELEMENT *item2 = heap->A[itemInd2];



}