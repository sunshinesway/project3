// Cheyenne Swasey
// 1227888508
#ifndef heap_h
#define heap_h
#include "data_structures.h"

void min_heapify(HEAP *heap, int elementIndex, int& count);
/*
 * input: HEAP struct, containing array A of ELEMENT structs, AND
 *        index of element to heapify in minheap, AND
 *        reference to heapify count int variable
 * output: void return
 * note: purpose to recursively update minheap element-by-element
 */
void build_min_heap(HEAP *heap, int& count);
/*
 * input: HEAP struct, containing array A of ELEMENT structs, AND
 *        reference to heapify count int variable
 * output: void return
 * note: creates minheap of doubles from array. Calls min_heapify
 */
double heap_extract_min(HEAP *heap, int& count);
/*
 * input: HEAP struct, containing array A of ELEMENT structs, AND
 *        reference to heapify count int variable
 * output: double, key value of smallest element
 * note: removes element, calls min_heapify to maintain heap
 */
void heap_decrease_key(HEAP *heap, int elem, double key);
/*
 * input: HEAP struct, containing array A of ELEMENT structs AND
 *        index of ELEMENT in minheap AND
 *        key value to update for ELEMENT
 * output: void return
 * note: updates key value of an ELEMENT in array. SWAPs parent elements as
 *       needed to maintain haep
 */
void min_heap_insert(HEAP *heap, double key);
/*
 * input: HEAP struct, containing array A of ELEMENT structs AND
 *        key value for new ELEMENT in array
 * output: void return
 * note: adds new ELEMENT to array with key value. Calls heap_decrease_key
 */

#endif