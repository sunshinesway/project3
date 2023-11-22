// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "heap.h"

int main(int argc, char **argv) {

    //initialize files as NULL
    FILE *inputFile = nullptr;
    char *graphType = argv[2];
    //pull in flag value from arguments
    int flag = std::stoi(argv[3]);
    char command[20];
    int numEdges;
    int numVertices;
    bool graph = false;
    int i;
    //directed == TRUE,
    // undirected == FALSE
    if(strcmp(graphType, "DirectedGraph")==0) {
        graph = true;
    }


    fscanf(stdin, "%19s", command);
    numVertices = std::atoi(command);

    fscanf(stdin, "%19s", command);
    numEdges = std::atoi(command);

    ptVERTEX *V;
    V = (ptVERTEX *)calloc(1, sizeof(ptVERTEX));
    int *adjList = new int[numVertices];

    for(i = 1; i <= numEdges; i++) {
        V[i] = (VERTEX *) calloc(1, sizeof(VERTEX));
        if (!V[i]) {
            fprintf(stderr, "Error: memory allocation failed for Vertex\n");
        }
        adjList[i] = *(int *) calloc(1, sizeof(int));
    }

    for(i = numEdges; i > 0; i--) {
        if(graph) {
            if(flag == 1) {

            }
        }

    }
}