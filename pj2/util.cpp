#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

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
    //base case if heap is null - error message
    if(!heap) {
        fprintf(stderr, "Error: heap is NULL");
    }
    //not NULL: print heap size, then each key value in ELEMENT A array
    else {
        printf("%d\n", heap->size);
        for(int i = 0; i < heap->size; i++) {
            printf("%lf\n",heap->A[i]->key);
        }
    }
}

void writeArray(HEAP *heap, FILE *outputFile) {
    //base case if heap is null - error message
    if(!heap) {
        fprintf(stderr, "Error: heap is NULL");
    }
    //not NULL: write array A to outputFile
    //error if file cannot be opened
    else if (!outputFile) {
        fprintf(stderr, "Error: cannot open file %s\n", "ofile");
    }
    //write first heap-size, then each key value in ELEMENT A array
    else {
        fprintf(outputFile, "%d\n", heap->size);
        for (int i = 0; i < heap->size; i++) {
            fprintf(outputFile, "%lf\n", heap->A[i]->key);
        }
        //close the file DON'T FORGET IT
        fclose(outputFile);
    }
}

void readIn(HEAP *heap, FILE *inputFile) {
    //base case if heap is null - error message
    if(!heap) {
        fprintf(stderr, "Error, file cannot be opened \n");
        exit(0);
    }
    else if (!inputFile) {
        fprintf(stderr, "Error: cannot open file %s\n", "ifile");
    }
    else {
        double key;

        fscanf(inputFile, "%d", &heap->size);
        if (heap->size > heap->capacity) {
            fprintf(stderr, "Error, heap capacity = %d, smaller than desired heap size = %d\n",
                    heap->capacity, heap->size);
            exit(0);
        }
        else {
            ELEMENT *newElem = heap->A[0];
            for (int i = 0; i < heap->size; i++) {
                fscanf(inputFile, "%lf", &key);
                key = heap->A[i]->key;
            }
        }
    }
}



void swap(HEAP *heap, int itemInd1, int itemInd2) {

    //create temp element for swapping
    ELEMENT *temp = NULL;
    ELEMENT *item1 = heap->A[itemInd1];
    ELEMENT *item2 = heap->A[itemInd2];



}