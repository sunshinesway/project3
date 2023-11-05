// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"

int main(int argc, char **argv){
    //initialize heap as NULL
    HEAP *heap = nullptr;
    //initialize files as NULL
    FILE *inputFile = nullptr;
    FILE *outputFile = nullptr;
    //pull in flag value from arguments
    int flag = std::stoi(argv[3]);
    int capacity;
    double key;
    int count = 0;
    double minimum;
    int j;
    //allow significant excess characters for commands JIC
    char command[100];


    //loop to read stdin for valid commands
    while(1) {
        //scan in command
        fscanf(stdin, "%99s", command);

        //end loop
        if(strcmp(command, "Stop")==0)
            break;

        else if(strcmp(command, "Init")==0) {
            fscanf(stdin, "%s", command);
            capacity = std::atoi(command);
            //if Init is being called AGAIN, free heap memory FIRST
            if(heap) {
                freeMemory(heap);
            }
            heap = initArray(capacity);
        }

        else if(strcmp(command, "Print")==0){
            printArray(heap);
        }

        else if(strcmp(command, "Write")==0){
            //open output file to write to, for WRITING
            outputFile = fopen(argv[2],"w");
            writeArray(heap, outputFile);
        }

        else if(strcmp(command, "Read")==0){
            //open output file to read in, for READING
            inputFile = fopen(argv[1], "r");
            if(!inputFile) {
                fprintf(stderr, "Error, file cannot be opened \n");
                exit(1);
            }
            count = 0;
            readIn(heap, inputFile, count);

            //print heapifyCall count if flag=1 and heap is not empty
            if(flag == 1 && heap->size > 0) {
                printf("Number of Heapify calls: %d\n", count);
            }

        }

        else if(strcmp(command, "Insert")==0){
            //read Insert VALUE
            fscanf(stdin, "%s", command);
            //check IF heap array has space for addtl element
            if(heap->size < heap->capacity) {
                key = std::stod(command);
                min_heap_insert(heap, key);
            }
        }

        else if(strcmp(command, "ExtractMin")==0){
            //check if heap is empty, NO ACTION if empty
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
            //read position value
            fscanf(stdin, "%s", command);
            j = std::atoi(command);
            //read new key value
            fscanf(stdin, "%s", command);
            double newKey = std::stod(command);
            heap_decrease_key(heap, j, newKey);
        }
        else {
            fprintf(stderr, "Warning: Invalid instruction\n");
        }
    }
    //deallocate memory at end of program
    freeMemory(heap);
}


