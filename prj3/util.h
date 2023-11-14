// Cheyenne Swasey
// 1227888508

#ifndef _util_h
#define util_h 1
#include "data_structures.h"

HEAP* initArray(int cap);
/*
* input: integer capacity, from stdin command
* output: HEAP struct, containing an array A of ELEMENTs
* note:
*/
void printArray(HEAP *heap);
/*
 * input: pointer to HEAP struct
 * output: void return
 * note: FLAG ==0, prints array A in heap to stdout: size of array, then each element
 */
void writeArray(HEAP *heap, FILE *outputFile);
/*
 * input: pointer to HEAP struct AND
 *        pointer to a FILE to write data to
 * output: void return
 * note: writes array A in heap to outputFile, same as printArray()
 */
void readIn(HEAP *heap, FILE *inputFile, int& count);
/*
 * input: pointer to HEAP struct AND
 *        pointer to a FILE to read data from, AND
 *        reference to heapify count int variable
 * output: void return
 * note: reads data from inputFile and designates first int as array size,
 *       then each following as an key for each ELEMENT in array
 */
void swap(HEAP *heap, int itemInd1, int itemInd2);
/*
 * input: pointer to HEAP struct AND
 *        TWO indexes to ELEMENTs in heap's array A
 * output: void return
 * note: swaps position of ELEMENTs at 1 and 2
 */
void freeMemory(HEAP *heap);
/*
* input: pointer to HEAP struct
* output: void return
* note: frees memory of all array elements, array, and heap
*/

#endif