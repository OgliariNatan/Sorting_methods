#include <stdio.h>
#include <stdlib.h>

#include "global_Uso.h"
#include "Heap_sort.h"

#define DEBUG

struct heap {
     int comp;
     int tam;
     int *dados;
};


void cria_heap (int * vetor, int TAM){
     struct heap heap_t;
     heap_t.tam = TAM;
     heap_t.dados = vetor;
     heap_t.comp = heap_t.tam-1;



}


//void heapSort
