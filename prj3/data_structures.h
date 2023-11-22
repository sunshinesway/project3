// Cheyenne Swasey
// 1227888508

#ifndef _data_structures_h
#define _data_structures_h 1

typedef struct TAG_NODE {
    int index;
    int origin;
    int destin;
    double weight;
    TAG_NODE *next;
}NODE;
//typedef NODE *pNODE;

typedef struct TAG_VERTEX {
    int index;
    //COLOR color;
    double key;
    int parent;
    int position;

    int numAdj;
    NODE** AdjList; //array of pointers to VERTEX's adjacent EDGES

}VERTEX;
typedef VERTEX *ptVERTEX;

typedef struct TAG_HEAP {
    int capacity; /* capacity of the heap */
    int size; /* current size of the heap */

    VERTEX** E; /* array of pointers to ELEMENT */

}HEAP;
//typedef HEAP *pHEAP;

typedef VERTEX ELEMENT;
typedef ELEMENT *pELEMENT;



typedef struct TAG_STACK{
    int capacity;

    TAG_NODE *source;
    TAG_NODE *destination;

    NODE** S;

}STACK;

#endif