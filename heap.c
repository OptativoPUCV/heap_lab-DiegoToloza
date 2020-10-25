#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq -> size == 0){
    return NULL;
  }else{
    return pq -> heapArray[0].data;
  }
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq -> size == pq -> capac){
    pq -> capac = pq -> capac * 2 + 1;
    pq -> heapArray = realloc(pq -> heapArray, (pq -> capac)*sizeof(heapElem));
  }
  pq -> heapArray[pq -> size].priority = priority;
  pq -> heapArray[pq -> size].data = data;

  int auxP = pq -> size;
  int parent =( (auxP - 1)/2 );

  while (pq -> heapArray[parent].priority < pq -> heapArray[auxP].priority){
    heapElem tmp = pq -> heapArray[parent];
    pq -> heapArray[parent] = pq -> heapArray[auxP];
    pq -> heapArray[auxP] = tmp;
    auxP = parent;
    parent = ((auxP - 1)/2);
  }
  pq -> size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
    Heap* newH = (Heap*)malloc( sizeof(Heap) );
    newH -> heapArray = (heapElem*)malloc( 3*sizeof(heapElem) );
    newH -> size = 0;
    newH -> capac = 3;
    return newH;
}
