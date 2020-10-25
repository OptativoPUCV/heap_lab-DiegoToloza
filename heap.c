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
  int i = 0;
  pq -> heapArray[0] = pq -> heapArray[pq -> size];
  pq -> size--;
  heapElem hijoIzq = pq -> heapArray[1];
  heapElem hijoDer = pq -> heapArray[2];
  int left = i + 1;
  int right = i + 2;

  while( (pq -> heapArray[i].priority < hijoIzq.priority) || (pq -> heapArray[i].priority < hijoDer.priority) ){
      heapElem auxP = pq -> heapArray[i];
      if(hijoIzq.priority > hijoDer.priority){
          pq -> heapArray[i] = hijoIzq;
          pq -> heapArray[left] = auxP;
          i = left;
          left = ( (2 * i) + 1);
          hijoIzq = pq -> heapArray[left];
    }else{
        pq -> heapArray[i] = hijoDer;
        pq -> heapArray[right] = auxP;
        i = right;
        left = ( (2 * i) + 2);
        hijoDer = pq -> heapArray[right];
}
if( (left > pq -> size) && (right > pq -> size) ){
  break;
    }
  }
}
Heap* createHeap(){
    Heap* newH = (Heap*)malloc( sizeof(Heap) );
    newH -> heapArray = (heapElem*)malloc( 3*sizeof(heapElem) );
    newH -> size = 0;
    newH -> capac = 3;
    return newH;
}
