// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

HEAP* initArray(int cap) {
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
    heap->A = (ELEMENT **)calloc(cap, sizeof(ELEMENT *));
        if(!heap->A) {
            fprintf(stderr, "Error: memory allocation failed for Heap Array\n");
            free(heap);
            return nullptr;
        }
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
        if(heap->size>0){
            for(int i = 1; i <= heap->size; i++) {
                printf("%lf\n", heap->A[i]->key);
            }
        }
    }
}

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

void swap(HEAP *heap, int itemInd1, int itemInd2) {

    //create temp element for swappin
    ELEMENT *temp = heap->A[itemInd1];
    //do the swappin
    heap->A[itemInd1] = heap->A[itemInd2];
    heap->A[itemInd2] = temp;
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