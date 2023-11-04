#ifndef _util_h
#define _util_h 1
#include "data_structures.h"

HEAP* initArray(int cap);
    /*
    * input:
    * output:
    * note:
    */
void printArray(HEAP *heap);
    /*
     * input:
     * output:
     * note:
     */
void writeArray(HEAP *heap, FILE *outputFile);
    /*
     * input:
     * output:
     * note:
     */
void readIn(HEAP *heap, FILE *inputFile);
    /*
     * input:
     * output:
     * note:
     */
void swap(HEAP *heap, int itemInd1, int itemInd2);
    /*
     * input:
     * output:
     * note:
     */


#endif