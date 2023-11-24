// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

//approximation of infinity for double val
double infinity = std::numeric_limits<double>::infinity();

int Dijkstra(VERTEX **vArray, HEAP *heap, int source, int numVert) {
    int i = 1;
    //initialize qArray with numVertices+1 elements to keep track of vertices to be checked
    //set all initial values to 0


    //set all key values in VERTEX array to infinity
    //set all parent values in VERTEX array to infinity
    //add index to qArray;
    while(vArray[i]->index != 0) {
        vArray[i]->key = infinity;
        vArray[i]->parent = 0;

        i++;
    }
    //set source distance from source to ZERO
    vArray[source]->key = 0;

    while()

    return 0;
}
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

int Dijkstra(VERTEX **vArray, int source, int destin) {
    return 0;
}