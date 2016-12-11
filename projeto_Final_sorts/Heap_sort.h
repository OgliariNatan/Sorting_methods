#ifndef HEAP_SORT_H_INCLUDED
#define HEAP_SORT_H_INCLUDED

typedef struct heaps heap_t;

heap_t *cria_heap(int *vetor, int tamanho);

void constroi_heap(heap_t *heap);

int get_tamanho_heap(heap_t *heap);

void set_comp_heap(heap_t *heap, int comprimento);

int pai(int indice);

int direita(int indice);

int esquerda(int indice);

void heapify(heap_t* heap, int i);

void heapsort(heap_t *heap, int tamanho);

#endif // HEAP_SORT_H_INCLUDED


/*
typedef struct heap heap_t;

heap_t *cria_heap(int *vetor, int TAM);

heap_t max_heapify(heap_t *heap, int i);

int tam_heap(heap_t *heap);

int obter_dado(heap_t *heap, int j);

void troca_heap(heap_t *heap, int i, int o);

void heapSort (int *vetor, int TAM);
*/
