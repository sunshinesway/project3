// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <cfloat>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

1  function Dijkstra(Graph, source):
2
3      for each vertex v in Graph.Vertices:
4          dist[v] ← INFINITY
5          prev[v] ← UNDEFINED
6          add v to Q
7      dist[source] ← 0
8
9      while Q is not empty:
10          u ← vertex in Q with min dist[u]
11          remove u from Q
12
13          for each neighbor v of u still in Q:
14              alt ← dist[u] + Graph.Edges(u, v)
15              if alt < dist[v]:
16                  dist[v] ← alt
17                  prev[v] ← u
18
19      return dist[], prev[]

void Dijkstra(VERTEX **vArray, int source, int destin) {
    int i = 1;
    double newKey;
    //initialize qArray with numVertices+1 elements to keep track of vertices to be checked
    //set all initial values to 0


    //set all key values in VERTEX array to infinity
    //set all parent values in VERTEX array to infinity
    //add index to qArray;
    while(vArray[i]->index != 0) {
        vArray[i]->key = DBL_MAX;
        vArray[i]->parent = 0;
        min_heap_insert(Qheap, vArray[i], vArray[i]->key);
        i++;
    }
    //set source distance from source to ZERO
    //update heapQ
    heap_decrease_key(Qheap, source, 0);

    VERTEX *currentVert = (VERTEX *)malloc(sizeof(VERTEX));
    VERTEX *adjVert = (VERTEX *)malloc(sizeof(VERTEX));

    while(Qheap->size != 0) {
        currentVert = Qheap->A[1];
        if (destin != 0 && currentVert->index == destin){
            return;
        }
        heap_extract_min(Qheap);

        for(int j = 1; j <= currentVert->numAdj; j++) {
            adjVert = vArray[currentVert->AdjList[j]->destin];
            for(int k = 1; k < Qheap->size; k++) {
                if (adjVert->index != Qheap->A[k]->index) {
                    continue;
                }
                else {
                    newKey = currentVert->key + currentVert->AdjList[j]->weight;
                    if(newKey < adjVert->key) {
                        adjVert->key = newKey;
                        adjVert->parent = currentVert->index;
                    }
                    break;
                }
            }
        }
    }
}