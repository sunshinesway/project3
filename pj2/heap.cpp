#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "data_structures.h"


max_heapify(ELEMENT *element) {
    //return if Element is null
    if(!element)
        return;

    ELEMENT *leftC = element->left;
    ELEMENT *rightC = element->right;
    ELEMENT *largestKey = element;

    if(leftC != null && leftC->key > element->key) {

    }

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