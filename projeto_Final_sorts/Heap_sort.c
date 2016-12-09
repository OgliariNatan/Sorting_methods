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

heap_t cria_heap(int *vetor, int TAM){

     heap_t *a = malloc(sizeof(heap_t));
     a->dados = vetor;



     free(a);
}

