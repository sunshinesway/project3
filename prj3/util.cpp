// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

void insertAdjList(VERTEX *vertex, NODE *edge, bool insertBegin) {
    if(!insertBegin) {
        vertex->numAdj++;
        vertex->AdjList[vertex->numAdj] = edge;
    }
    else {
        for(int i = vertex->numAdj; i > 0; i--) {
            swap(vertex,i, i+1);
        }
        vertex->AdjList[1] = edge;
        vertex->numAdj++;
    }
}

HEAP* initHeapArray(int cap) {
    //allocate memory for single heap
    //return null with error if unsuccessful
    HEAP *heap = (HEAP *)calloc(1, sizeof(HEAP));
    if (!heap) {
        fprintf(stderr, "Error: memory allocation failed for Heap\n");
        return nullptr;
    }
    //set heap field values
    heap->capacity = cap;
    heap->size = 0;
    //allocate memory for array of cap size
    //deallocate heap memory and return null if array allocation unsuccessful
    heap->A = (VERTEX **)calloc(cap, sizeof(VERTEX *));
    if(!heap->A) {
        fprintf(stderr, "Error: memory allocation failed for Heap Array\n");
        free(heap);
        return nullptr;
    }
    return heap;
}

STACK* initStackArray(int cap) {
    //allocate memory for single heap
    //return null with error if unsuccessful
    STACK *stack = (STACK *)calloc(1, sizeof(STACK));
    if (!stack) {
        fprintf(stderr, "Error: memory allocation failed for Heap\n");
        return nullptr;
    }
    //set heap field values
    stack->capacity = cap;
    stack->size = 0;

    stack->top = (NODE *)calloc(1, sizeof(NODE));
    stack->top = nullptr;
    //allocate memory for array of cap size
    //deallocate heap memory and return null if array allocation unsuccessful
   /*
    stack->S = (NODE **)calloc(cap, sizeof(NODE *));
    if(!stack->S) {
        fprintf(stderr, "Error: memory allocation failed for Stack Array\n");
        free(stack);
        return nullptr;
    } */
    return stack;
}


void printAdjLists(VERTEX **vArray, int numVert) {
    //base case if heap is null - error message
    if(!vArray[1]) {
        fprintf(stderr, "Error: Vertex Array is EMPTY");
    }
        //not NULL: print
        // ADJ[1]:-->[1 4: 5.00]-->[1 2: 10.00]
    else {
        //int arrayLength = sizeof(vArray)/sizeof(VERTEX *);
        for(int i = 1; i <= numVert; i++) {
            printf("ADJ[%d]:", i);
            for(int j = 1; j <= vArray[i]->numAdj; j++) {
                printf("-->[%d %d: %.2lf]", vArray[i]->AdjList[j]->origin, vArray[i]->AdjList[j]->destin, vArray[i]->AdjList[j]->weight);
            }
            printf("\n");
        }
    }
}

void swap(VERTEX *vertex, int itemInd1, int itemInd2) {
    //create temp NODE for swappin
    NODE *temp = vertex->AdjList[itemInd1];
    //do the swappin
    vertex->AdjList[itemInd1] = vertex->AdjList[itemInd2];
    vertex->AdjList[itemInd2] = temp;
}
void swap(HEAP *heap, int itemInd1, int itemInd2) {

    //create temp element for swappin
    VERTEX *temp = heap->A[itemInd1];
    //do the swappin
    heap->A[itemInd1] = heap->A[itemInd2];
    heap->A[itemInd2] = temp;
}

/*

void writeArray(HEAP *heap, FILE *outputFile) {
    //base case if heap is null - error message
    if(!heap) {
        fprintf(stderr, "Error: heap is NULL");
        return;
    }
        //not NULL: write array A to outputFile
        //error if file cannot be opened
    else if (!outputFile) {
        fprintf(stderr, "Error: cannot open file %s\n", "ofile");
        return;
    }
        //write first heap-size, then each key value in ELEMENT A array
    else {
        fprintf(outputFile, "%d\n", heap->size);
        for (int i = 1; i <= heap->size; i++) {
            fprintf(outputFile, "%lf\n", heap->A[i]->key);
        }
        //close the file DON'T FORGET IT
        fclose(outputFile);
    }
}

void readIn(HEAP *heap, FILE *inputFile, int& count) {
    //base case if heap is null - error message
    if(!heap) {
        fprintf(stderr, "Error, file cannot be opened \n");
        return;
    }
        //not NULL: write array A to outputFile
        //error if file cannot be opened
    else if (!inputFile) {
        fprintf(stderr, "Error: cannot open file %s\n", "ifile");
        return;
    }

        //read from file
    else {
        double key;
        //first, pull int: heap-size
        fscanf(inputFile, "%d", &heap->size);
        //error if heap cap<heap size
        if (heap->size > heap->capacity) {
            //update heapsize to 0 so other functions do not attempt action with empty array
            heap->size = 0;
            //commenting out error message - causes tests to fail even though instructions say to print error :P
            //fprintf(stderr, "Error, heap capacity = %d, smaller than desired heap size = %d\n", heap->capacity, heap->size);
            return;
        }
        else {

            //loop through array, setting double value from file to key field
            for (int i = 1; i <= heap->size; i++) {
                //create new element, allocate memory
                ELEMENT *newElem = (ELEMENT *)malloc(sizeof(ELEMENT));
                heap->A[i] = newElem;
                //read key value and assign to new element's key field
                fscanf(inputFile, "%lf", &key);
                heap->A[i]->key = key;
            }
            //call build heap now that array is populated
            build_min_heap(heap, count);

        }
    }
    //rewind inputfile ALWAYS (in case needs to be reread)
    // be_kind_rewind
    rewind(inputFile);
    //close the file DON'T FORGET IT
    fclose(inputFile);

}



void freeMemory(HEAP *heap) {
    //deallocate each array element
    for(int i = 0; i <= heap->size; i++) {
        free(heap->A[i]);
    }
    //deallocate array
    free(heap->A);
    //deallocate haep
    free(heap);
}

 */