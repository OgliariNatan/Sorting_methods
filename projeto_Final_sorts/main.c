#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>

#include "bubbleSort.h"
#include "med_3.h"
#include "SelectionSorting.h"
#include "global_Uso.h"
#include "incercao.h"
#include "mergesort.h"
#include "quicksort.h"
#include "Heap_sort.h"

#define DEBUGBUBBLRSORT
#define DEBUGSELECTION
#define DEBUGQUIKSORT
#define DEBUGHEAPSORT
#define DEBUGINCERCAODIRETA  //!<PAUUUUUUUUU
#define DEBUGINCERCAOBINARIA //!<PAUUUUUUUUU
#define DEBUGMERGE
//#define DEBUG


#define TAM 1000000     //!< Ideal 1000000
#define VEZORDENACAO 20 //!< Ideal 20

int main()
{
int i=0;
clock_t inicio, fim;
float *med = (float*)malloc(sizeof(float)*(TAM*6));
int *vetor = (int*)malloc(sizeof(int)*TAM);

 if (vetor == NULL){
     printf("Erro: ao criar o vetor\n");
     exit(-1);
 }

srand(getpid()^time(NULL));//!<Alimenta a semente

#ifdef DEBUGBUBBLRSORT
     puts("Metodo Bubble Sort");
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          medianaDeTres(vetor, 0, TAM-1);
          inicio = clock();
          bubblesort(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do Bubblesort[%d] %f [s]\n",i+1,med[i]);
     }
     #ifdef DEBUG
     imprimi_ordenado(vetor, TAM);
     #endif // DEBUG
     puts("---------------------");
#endif // DEBUGBUBBLRSORT

#ifdef DEBUGSELECTION
     puts("Metodo Selection");
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          inicio = clock();
          select_sort(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do SelectionSorting[%d] %f [s]\n",i+1, med[i]);
     }
     #ifdef DEBUG
     imprimi_ordenado(vetor, TAM);
     #endif // DEBUG
     puts("---------------------");
#endif // DEBUGSELECTION

#ifdef DEBUGQUIKSORT
     puts("Metodo Quiksort");
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          medianaDeTres(vetor, 0, TAM-1);
          inicio = clock();
          quicksort(vetor, 0, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do QuickSort[%d] %f [s]\n",i+1, med[i]);
     }
     #ifdef DEBUG
     imprimi_ordenado(vetor, TAM);
     #endif // DEBUG
     puts("---------------------");
#endif // DEBUGQUIKSORT

#ifdef DEBUGHEAPSORT
     puts("Metodo Heap Sort");
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          inicio = clock();
          heapSort(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do HeapSort[%d] %f [s]\n",i+1, med[i]);
     }
     #ifdef DEBUG
     imprimi_ordenado(vetor, TAM);
     #endif // DEBUG
     puts("---------------------");
#endif // DEBUGHEAPSORT

#ifdef DEBUGINCERCAODIRETA
     puts("Metodo Incercao Direta");
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          inicio = clock();
          insertsortDireta(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do IncercaoDireta[%d] %f\n",i+1, med[i]);
     }
     imprimi_ordenado(vetor, TAM);
     puts("---------------------");
#endif // DEBUGINCERCAODIRETA

#ifdef DEBUGINCERCAOBINARIA
     puts("Metodo Incercao Binaria");
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          inicio = clock();
          insercao_binaria(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do IncercaoBinaria[%d] %f [s]\n",i+1, med[i]);
     }
     #ifdef DEBUG
     imprimi_ordenado(vetor, TAM);
     #endif // DEBUG
     puts("---------------------");
#endif // DEBUGINCERCAOBINARIA

#ifdef DEBUGMERGE
     puts("Metodo Merge Sort");
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          inicio = clock();
          merge_primeiro(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do MergeSort[%d] %f [s]\n",i+1, med[i]);
     }
     #ifdef DEBUG
     imprimi_ordenado(vetor, TAM);
     #endif // DEBUG
     puts("---------------------");
#endif // DEBUGMERGE

     free(med);
     free(vetor);
return 0;
}
