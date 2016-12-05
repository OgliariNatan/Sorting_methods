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
#define DEBUGINCERCAODIRETA
#define DEBUGINCERCAOBINARIA
#define DEBUGMERGE
//#define DEBUG


#define TAM 1000     //!< Ideal 1000000
#define VEZORDENACAO 5 //!< Ideal 20

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

puts("---------------------");

#ifdef DEBUGBUBBLRSORT
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          medianaDeTres(vetor, 0, TAM-1);
          inicio = clock();
          bubblesort(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do Bubblesort[%d] %f\n",i+1,med[i]);
     }
     //imprimi_ordenado(vetor, TAM);
     puts("---------------------");
#endif // DEBUGBUBBLRSORT

#ifdef DEBUGSELECTION
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          inicio = clock();
          select_sort(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do SelectionSorting[%d] %f\n",i+1, med[i]);
     }
     //imprimi_ordenado(vetor, TAM);
     puts("---------------------");
#endif // DEBUGSELECTION

#ifdef DEBUGQUIKSORT
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          medianaDeTres(vetor, 0, TAM-1);
          inicio = clock();
          quicksort(vetor, 0, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do QuickSort[%d] %f\n",i+1, med[i]);
     }
     //imprimi_ordenado(vetor, TAM);
     puts("---------------------");
#endif // DEBUGQUIKSORT

#ifdef DEBUGHEAPSORT
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          inicio = clock();
          heapSort(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do HeapSort[%d] %f\n",i+1, med[i]);
     }
     //imprimi_ordenado(vetor, TAM);
     puts("---------------------");
#endif // DEBUGHEAPSORT

#ifdef DEBUGINCERCAODIRETA
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          inicio = clock();
          //insertsortDireta(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do IncercaoDireta[%d] %f\n",i+1, med[i]);
     }
     //imprimi_ordenado(vetor, TAM);
     puts("---------------------");
#endif // DEBUGINCERCAODIRETA

#ifdef DEBUGINCERCAOBINARIA
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          inicio = clock();
          insercao_binaria(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do IncercaoBinaria[%d] %f\n",i+1, med[i]);
     }
     //imprimi_ordenado(vetor, TAM);
     puts("---------------------");
#endif // DEBUGINCERCAOBINARIA

#ifdef DEBUGMERGE
     for (i=0; i<VEZORDENACAO; i++){
          randomico(vetor,TAM);
          inicio = clock();
          merge_primeiro(vetor, TAM);
          fim = clock();
          med[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do MergeSort[%d] %f\n",i+1, med[i]);
     }
     //imprimi_ordenado(vetor, TAM);
     puts("---------------------");
#endif // DEBUGMERGE

     free(med);
     free(vetor);
return 0;
}
