#ifndef _util_h
#define _util_h 1
#include "data_structures.h"

HEAP* initArray(int cap);
void swap(HEAP *heap, int itemInd1, int itemInd2);
int  nextInstruction(char *Word, double *key);


#endif