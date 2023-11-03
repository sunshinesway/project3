#ifndef _util_h
#define _util_h 1
#include "data_structures.h"

HEAP* initArray(int cap);
void printArray(HEAP *heap);
void writeArray();
void readIn();
void swap(HEAP *heap, int itemInd1, int itemInd2);
int getNext(char *command)

#endif