// Cheyenne Swasey
// 1227888508

#ifndef _data_structures_h
#define _data_structures_h 1

typedef struct TAG_NODE {
    int index;
    int origin;
    int destin;
    double weight;
    //TAG_NODE *next;
}NODE;
//typedef NODE *pNODE;

typedef struct TAG_VERTEX {
    int index = 0;
    //COLOR color;
    double key;
    int parent;
    int position;
    TAG_VERTEX *next;

    int numAdj = 0;
    NODE** AdjList; //array of pointers to VERTEX's adjacent EDGES

}VERTEX;
typedef VERTEX *ptVERTEX;

typedef struct TAG_HEAP {
    int capacity; /* capacity of the heap */
    int size; /* current size of the heap */


    VERTEX** A; /* array of pointers to ELEMENT */

}HEAP;
//typedef HEAP *pHEAP;
//typedef VERTEX ELEMENT;
//typedef ELEMENT *pELEMENT;



typedef struct TAG_STACK{
    int capacity;
    int size;

    TAG_VERTEX *top;

    //NODE** S; /* array of pointers to EDGES */

}STACK;


#endif