// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"

int main(int argc, char **argv){
    HEAP *heap = nullptr;
    FILE *inputFile = nullptr;
    FILE *outputFile = nullptr;
    int flag = std::stoi(argv[3]);
    int capacity;
    double key;
    int count = 0;
    double minimum;
    int j;
    char command[100];


    inputFile = fopen(argv[1], "r");
    if(!inputFile) {
        fprintf(stderr, "Error, file cannot be opened \n");
        exit(1);
    }

    //loop to read stdin for commands
    while(1) {

        fscanf(stdin, "%99s", command);

        if(strcmp(command, "Stop")==0)
            break;

        else if(strcmp(command, "Init")==0) {
            fscanf(stdin, "%s", command);
            capacity = std::atoi(command);
            //if Init is being called AGAIN, free heap memory, and rewind inputFile to pull heapsize again
            if(heap) {
                freeMemory(heap);
                rewind(inputFile);
            }
            heap = initArray(capacity);
        }

        else if(strcmp(command, "Print")==0){
            printArray(heap);
        }

        else if(strcmp(command, "Write")==0){
            outputFile = fopen(argv[2],"w");
            writeArray(heap, outputFile);
        }

        else if(strcmp(command, "Read")==0){
            count = 0;
            readIn(heap, inputFile, count);

            if(flag == 1) {
                printf("Number of Heapify calls: %d\n", count);
            }

        }

        else if(strcmp(command, "Insert")==0){
            fscanf(stdin, "%s", command);
            if(heap->size < heap->capacity) {
                key = std::stod(command);
                min_heap_insert(heap, key);
            }
        }

        else if(strcmp(command, "ExtractMin")==0){
            if(heap->size>0) {
                count = 0;
                minimum = heap_extract_min(heap, count);
                printf("%s%lf\n", "ExtractMin: ", minimum);

                if(flag == 1) {
                    printf("Number of Heapify calls: %d\n", count);
                }
            }
        }

        else if(strcmp(command, "DecreaseKey")==0){
            fscanf(stdin, "%s", command);
            j = std::atoi(command);
            fscanf(stdin, "%s", command);
            double newKey = std::stod(command);
            heap_decrease_key(heap, j, newKey);
        }
        else {
            fprintf(stderr, "Warning: Invalid instruction\n");
        }
    }
    freeMemory(heap);
}


