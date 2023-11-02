#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

HEAP* initArray(int cap) {
    HEAP *heap = new HEAP;
    heap->capacity = cap;
    heap->size = 0;

    heap->A = new ELEMENT*[cap];

    for (int i = 0; i < cap; i++) {
        heap->A[i] = NULL;
    }

    return heap;
}

void swap(HEAP *heap, int itemInd1, int itemInd2) {

    //create temp element for swapping
    ELEMENT *temp = NULL;
    ELEMENT *item1 = heap->A[itemInd1];
    ELEMENT *item2 = heap->A[itemInd2];



}