// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

//approximation of infinity for double val
double infinity = std::numeric_limits<double>::infinity();

void min_heapify(HEAP *heap, int elementIndex, int& count) {
    //increment heapifyCall count
    count++;
    //return if Element @elementIndex is null
    ELEMENT *element = heap->A[elementIndex];
    if(!element)
        return;

    //set current element to smallest
    ELEMENT *smallestKey = element;
    //initialize smallIndex<0
    int smallIndex = -1;
    //create ELEMENT objects for children of current
    int leftIndex = elementIndex*2;
    int rightIndex = elementIndex*2 + 1;
    ELEMENT *leftC = nullptr;
    ELEMENT *rightC = nullptr;
    //check if leftIndex is within current array, only assign leftC !NULL if YES
    if (leftIndex >= 0 && leftIndex <= heap->size) {
        leftC = heap->A[leftIndex];
    }
    //check if rightIndex is within current array, only assign rightC !NULL if YES
    if (rightIndex >=0 && rightIndex <= heap->size) {
        rightC = heap->A[rightIndex];
    }

    //if to check leftChild key is smaller than current
    if(leftC != nullptr && leftC->key < smallestKey->key) {
        smallestKey = leftC;
        smallIndex = leftIndex;
    }
    //if to check leftChild key is smaller than current or leftChild
    if(rightC != nullptr && rightC->key < smallestKey->key) {
        smallestKey = rightC;
        smallIndex = rightIndex;
    }
    //if smallestKey was updated to L or R child, swap and update heap
    //if current smaller than children, end function w/o action
    if(smallestKey->key != element->key && smallIndex >= 0 && smallIndex <= heap->size)  {
        swap(heap, elementIndex, smallIndex);
        min_heapify(heap, smallIndex, count);
    }

}

void build_min_heap(HEAP *heap, int& count) {
    //loop through heap to heapify - starting middle, work up
    for (int i = (heap->size/2); i > 0; i--) {
        min_heapify(heap, i, count);
    }
}

double heap_extract_min(HEAP *heap, int& count){
    //return max double val(infinity) with error mess. if heap empty
    if (heap->size < 1) {
        fprintf(stderr, "Error: heap empty\n");
        return infinity;
    }
    else {
        //min is first val in heap
        double minimum = heap->A[1]->key;
        //make last item in heap top of heap
        heap->A[1] = heap->A[heap->size];

        //set old last element to NULL
        heap->A[heap->size] = nullptr;
        //reduce heap size
        heap->size--;

        //update heap to maintain after remove min
        min_heapify(heap, 1, count);
        return minimum;
    }
}

void heap_decrease_key(HEAP *heap, int elem, double newKey) {
    //error mess. if new key not less than current
    //to decrease key you must have a decreased key
    if (newKey > heap->A[elem]->key)
        fprintf(stderr, "Error: NEW KEY NOT LESS\n");
    else {
        //update key value
        heap->A[elem]->key = newKey;
        //swap values in heap to maintain with new key value
        int parent = elem/2;
        while(elem > 1 && heap->A[parent]->key > heap->A[elem]->key ) {
            swap(heap, parent, elem);
            elem = parent;
            parent = elem/2;
        }
    }
}

void min_heap_insert(HEAP *heap, double key) {
    //increase heap size
    heap->size++;
    //create new element, allocate memory
    ELEMENT *newElem = (ELEMENT *)malloc(sizeof(ELEMENT));
    heap->A[heap->size] = newElem;
    //make new element key as high as possible
    heap->A[heap->size]->key = infinity;
    //call decrease key to maintain heap structure with swaps
    heap_decrease_key(heap, heap->size, key);
}


/*
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
 */