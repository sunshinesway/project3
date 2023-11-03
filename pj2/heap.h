#define _util_h
#include "data_structures.h"

void min_heapify(HEAP *heap, int elementIndex);
void build_min_heap(HEAP *heap);
void heapsort(HEAP *heap);
int heap_min(HEAP *heap);
int heap_extract_min(HEAP *heap);
void heap_decrease_key(HEAP *heap, int elem, int key);
void min_heap_insert(HEAP *heap, int key);