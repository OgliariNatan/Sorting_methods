#include <stdio.h>
#include <stdlib.h>

#include "global_Uso.h"
#include "Heap_sort.h"

//#define DEBUG

typedef struct heaps{
    int comprimento;
    int tamanho;
    int *dados;
}heap_t;

heap_t *cria_heap(int* vetor, int tamanho){
    heap_t* h = malloc(sizeof(heap_t));

    h->tamanho = tamanho;
    h->comprimento = tamanho;
    h->dados = vetor;

    return h;
}

int get_comp_heap(heap_t* heap){
    if (heap == NULL)  {
        fprintf(stderr,"get_tamanho_heap: ponteiros invalidos\n");
        exit(EXIT_FAILURE);
    }

    return heap->comprimento;
}

void set_comp_heap(heap_t* heap, int comprimento){
    if (heap == NULL)    {
        fprintf(stderr,"set_tamanho_heap: ponteiros invalidos\n");
        exit(EXIT_FAILURE);

        heap->comprimento = comprimento;
    }
}



int pai(int i){
    return((i-1)/2);
}


int direita(int i){
    return((2*i)+2);
}


int esquerda(int i){
    return((2*i)+1);
}


void heapify(heap_t* heap, int i){
    int e = esquerda(i);

    int d = direita(i);

    int maior;

    int comp = get_comp_heap(heap);

    if(e < heap->comprimento && heap->dados[e] > heap->dados[i])
        maior = e;
    else
        maior = i;

    if(d < heap->comprimento && heap->dados[d] > heap->dados[maior])
        maior = d;

    #ifdef DEBUG
    printf("esquerda = %d\n", e);
    printf("direita = %d\n", d);
    printf("comprimento = %d\n", comp);
    printf("maior = %d\n\n", maior);
    #endif // DEBUG

    if(maior != i)    {
        troca(heap->dados, i, maior);
        heapify(heap, maior);
        #ifdef DEBUG
        printf("Alteracao do vetor por heapify! \n");
        imprimi_ordenado(heap->dados, heap->comprimento);
        #endif // DEBUG
    }
}


void constroi_heap(heap_t* heap){
    int i;

    for(i = (heap->tamanho-1)/2;i >= 0; i--)
        heapify(heap,i);
}


void heapsort(heap_t *heap, int tamanho){
	int i;
    #ifdef DEBUG
    printf("Construcao do heap iniciada!\n");
    #endif // DEBUG
    constroi_heap(heap);
    #ifdef DEBUG
    printf("Construcao do heap encerrada!\n");
    printf("Vetor apos buildheap : \n");
    imprimi_ordenado(heap->dados,heap->tamanho);
    #endif // DEBUG

    for(i = tamanho-1; i > 0;i--)    {
        troca(heap->dados,0,i);

        set_comp_heap(heap, ((heap->comprimento)--));
        heapify(heap,0);
    }
}










/*

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
*/
