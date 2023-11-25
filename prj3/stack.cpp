// Cheyenne Swasey
// 1227888508

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "util.h"
#include "heap.h"
#include "data_structures.h"

void push(STACK *stack, VERTEX *vertex) {
    VERTEX *newVertex = (VERTEX *)malloc(sizeof(VERTEX));
    newVertex->parent = vertex->parent;
    newVertex->key = vertex->key;

    newVertex->next = stack->top;
    stack->top = newVertex;
}

void pop() {

}