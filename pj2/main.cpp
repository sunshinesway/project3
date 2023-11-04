// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"

int main(int argc, char **argv){
    HEAP *heap = (HEAP *) calloc(1, sizeof(HEAP));
    FILE *inputFile = nullptr;
    FILE *outputFile = nullptr;
    int flag = std::stoi(argv[3]);
    int capacity;
    double key;
    int count = 0;
    double minimum;
    int j;
    char command[20];


    inputFile = fopen(argv[1], "r");
    if(!inputFile) {
        fprintf(stderr, "Error, file cannot be opened \n");
        exit(1);
    }

    while ((j = fscanf(inputFile, "%lf", &key)) == 1) {

    }
    //loop to read stdin for commands
    while(1) {

        fscanf(stdin, "%19s", command);

        if(strcmp(command, "Stop")==0)
            break;

        else if(strcmp(command, "Init")==0) {
            fscanf(stdin, "%s", command);
            capacity = std::atoi(command);
            heap = initArray(capacity);
        }

        else if(strcmp(command, "Print")==0){
            if(flag ==1)
                printArray(heap, count);
            else
                printArray(heap);
        }

        else if(strcmp(command, "Write")==0){
            outputFile = fopen(argv[2],"w");
            writeArray(heap, outputFile);
        }

        else if(strcmp(command, "Read")==0){
            readIn(heap, inputFile);
            count = 0;
            
        }

        else if(strcmp(command, "Insert")==0){
            fscanf(stdin, "%s", command);
            key = std::stod(command);
            min_heap_insert(heap, key);
        }

        else if(strcmp(command, "ExtractMin")==0){
            minimum = heap_extract_min(heap, count);
            printf("%s%lf\n","ExtractMin: ", minimum);
            count = 0;
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

}


