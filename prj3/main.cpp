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
    FILE *outputFile = nullptr;
    char *graphType = argv[2];
    //pull in flag value from arguments
    int flag = std::stoi(argv[3]);
    char command[20];
    int numEdges;
    int numVertices = 0;
    bool graph = false;
    bool const insertBegin = true;
    int i;
    int originInput;
    int destinInput;


    //directed: graph
    //undirected: !graph
    if(strcmp(graphType, "DirectedGraph")==0) {
        graph = true;
    }

    //open inputFile to READ
    //error if cannot open
    inputFile = fopen(argv[1], "r");
    if(!inputFile) {
        fprintf(stderr, "Error, file cannot be opened \n");
        exit(1);
    }
    //read inputFile to get num of Vert and num of Edges
    fscanf(inputFile, "%d", &numVertices);
    fscanf(inputFile, "%d", &numEdges);

    ptVERTEX *V;
    V = (ptVERTEX *)calloc(1, sizeof(ptVERTEX));
    //int *adjList = new int[numVertices];

    for(i = 1; i <= numVertices; i++) {
        V[i] = (VERTEX *) calloc(1, sizeof(VERTEX));
        if (!V[i]) {
            fprintf(stderr, "Error: memory allocation failed for Vertex\n");
        }
        //set index value for VERTEX
        V[i]->index = i;
        //allocate memory for VERTEX's adjacencyList -> MAX num of adjVert = numVert-1
        V[i]->AdjList = (NODE **)calloc((numVertices-1), sizeof(NODE *));

        //adjList[i] = *(int *) calloc(1, sizeof(int));
    }

    for(i = numEdges; i > 0; i--) {
        NODE *newEdge = (NODE *)malloc(sizeof(NODE));

        fscanf(inputFile, "%d", &newEdge->index);
        fscanf(inputFile, "%d", &newEdge->origin);
        int origin = newEdge->origin;
        fscanf(inputFile, "%d", &newEdge->destin);
        int destin = newEdge->destin;
        fscanf(inputFile, "%lf", &newEdge->weight);
        int weight = newEdge->weight;

        //DIRECTED GRAPH
        if(graph) {
            //IF FLAG 1
            //insert EDGE at BEGINNING of V[origin] adjList
            if (flag == 1) {
                insertAdjList(V[newEdge->origin], newEdge, insertBegin);
            }
                //IF FLAG 2
                //insert EDGE at END of V[origin] adjList
            else {
                insertAdjList(V[newEdge->origin], newEdge, !insertBegin);
            }
        }
        //UNDIRECTED GRAPH
        else {
            //create EDGE with reverse origin/destination to insert into destin VERTEX adjList
            NODE *revEdge = (NODE *)malloc(sizeof(NODE));
            revEdge->origin = newEdge->destin;
            revEdge->destin = newEdge->origin;
            revEdge->weight = newEdge->weight;
            revEdge->index = newEdge->index;

            //IF FLAG 1
            //insert EDGE at BEGINNING of BOTH V[origin] adjList & the reverse to V[destin] adjList
            if (flag == 1) {
                insertAdjList(V[newEdge->origin], newEdge, insertBegin);
                insertAdjList(V[newEdge->destin], revEdge, insertBegin);
            }
            //IF FLAG 2
            //insert EDGE at END of BOTH V[origin] adjList & the reverse to V[destin] adjList
            else {
                insertAdjList(V[newEdge->origin], newEdge, !insertBegin);
                insertAdjList(V[newEdge->destin], revEdge, !insertBegin);
            }
        }

    }
    fclose(inputFile);

    //initialize HEAP pointer with capacity of numVertices
    HEAP *heap = nullptr;
    heap = initHeapArray(numVertices);

    //initialize STACK pointer with capacity of numVertices
    STACK *stack = nullptr;
    stack = initStackArray(numVertices);

    while(1) {
        //scan in command
        fscanf(stdin, "%19s", command);

        //end while loop
        if(strcmp(command, "Stop")==0)
            break;

        else if(strcmp(command, "PrintADJ")==0) {
            printAdjLists(V, numVertices);
        }

        else if(strcmp(command, "SinglePair")==0){
            //read source node, convert to int
            fscanf(stdin, "%s", command);
            originInput = std::stod(command);
            //read destination node, convert to int
            fscanf(stdin, "%s", command);
            destinInput = std::stod(command);

        }

        else if(strcmp(command, "SingleSource")==0){
            fscanf(stdin, "%s", command);
            originInput = std::stod(command);
        }

        else if(strcmp(command, "PrintLength")==0){

        }

        else if(strcmp(command, "PrintPath")==0){

        }

        else {
            fprintf(stderr, "Warning: Invalid instruction\n");
        }
    }
    //deallocate memory at end of program
    //freeMemory();
}