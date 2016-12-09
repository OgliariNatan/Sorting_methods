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

heap_t *cria_heap(int *vetor, int TAM){

     int i;
     heap_t *a = malloc(sizeof(heap_t));
     a->dados = vetor;
     a->comp = TAM;
     a->tam = TAM;

     for (i = ((TAM-1)/2); i > 0; i--){
          max_heapify(a, i);
     }

     return a;

}


heap_t max_heapify(heap_t *heap, int i){
     int esq, dir, maior;
     //floor = (i-1)/2;
     esq = 2*i +1;
     dir = 2*i +2;

     if (esq < tam_heap(heap) && obter_dado(heap, esq) > obter_dado(heap, i))
          maior = esq;
     else
          maior = i;

     if (dir < tam_heap(heap) && obter_dado(heap, dir) > obter_dado(heap, i))
          maior = dir;

     if (maior != i){
          troca_heap(heap, i, maior);
          max_heapify(heap, maior);
     }

}

void heapSort (int *vetor, int TAM){


}


int tam_heap(heap_t *heap){

     return heap->tam;
}

int obter_dado(heap_t *heap, int j){
     int dado;
     dado = heap->dados[j];
     return dado;
}

void troca_heap(heap_t *heap, int i, int o){
     int dado_aux;
     dado_aux = heap->dados[i];
     heap->dados[i] = heap->dados[o];
     heap->dados[o] = dado_aux;
}
