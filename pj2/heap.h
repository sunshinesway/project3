#define _util_h
#include "data_structures.h"

void min_heapify(HEAP *heap, int elementIndex);
void build_min_heap(HEAP *heap);
void heapsort(HEAP *heap);
double heap_min(HEAP *heap);
double heap_extract_min(HEAP *heap);
void heap_decrease_key(HEAP *heap, int elem, double key);
void min_heap_insert(HEAP *heap, double key);