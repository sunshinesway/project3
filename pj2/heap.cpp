#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "data_structures.h"


void min_heapify(HEAP *heap, int elementIndex) {
    //return if Element is null
    ELEMENT *element = heap->A[elementIndex];
    if(!element)
        return;

    ELEMENT *smallestKey = element;
    int smallIndex = 0;
    ELEMENT *leftC = heap->A[elementIndex*2];
    ELEMENT *rightC = heap->A[elementIndex*2 + 1];

    if(leftC != NULL && leftC->key < element->key) {
        *smallestKey = *leftC;
        smallIndex = elementIndex*2;
    }
    if(rightC != NULL && rightC->key < smallestKey->key) {
        *smallestKey = *rightC;
        smallIndex = elementIndex*2 + 1;
    }
    if(smallestKey->key != element->key)  {
        swap(heap, elementIndex, smallIndex);
        min_heapify(heap, smallIndex);
    }

}

void build_min_heap(HEAP *heap) {
    heap->size = sizeof(heap->A) / sizeof(ELEMENT);
    for (int i = 0; i <= (heap->size/2; i++)) {
        min_heapiy(heap, i);
    }
}

void heapsort(HEAP *heap) {
    build_min_heap(heap);
    for (int i = )

}
//HEAPSORT
heapsort(A) {
        build_max_heap(A);
        for i = length(A) to 2
        SWAP A[1], A[i];
        heap-size[A]--;
        max_heapify(A,1);
}

//HEAP-MAXIMUM
heap_max(A) {
        return A[1];
}

//HEAP-EXTRACT-MAX
heap_extract_max(A) {
        if heap-size[A] < 1
        "error: heap empty"
        else
        max = A[1];
        A[1] = A[heap-size[A]];
        heap-size[A]--;
        max_heapify(A,1);
        return max;
}

//INCREASE-KEY
heap_increase_key(A,i,key) {
if key < A[i]
"error: new key smaller than current"
else
A[i] = key;
while i > 1 && A[PARENT(i)] < A[i]
SWAP A[i], A[PARENT(i)];
i = PARENT(i);
}

//INSERTION
max_heap_insert(A,key) {
heap-size[A]++;
i = heap-size[A];

A[i] = -INFINITY;
heap_increase_key(A,i,key);
}



//MAX-HEAPIFY
max_heapify(A,i) {
l = Left(i);
r = right(i);
if l <= heap-size[A] && A[l] > A[i]
largest = l;
else
largest = i;

if r <= heap-size[A] && A[r] > A[largest]
largest = r;
if largest != i
SWAP() A[i], A[largest];
max_heapify(A, largest)
}
//BUILD-HEAP
build_max_heap(A) {
        heap-size[A] = length(A);
        for i = ((length(A)/2)) to 1
        max_heapify(A,i);
}