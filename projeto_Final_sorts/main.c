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

#define DEBUGBUBBLRSORT
#define DEBUGSELECTION
//#define DEBUG
#define TAM 10     //!< Ideal 1000000
#define VEZORDENACAO 10 //!< Ideal 20

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
     imprimi_ordenado(vetor, TAM);
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
     imprimi_ordenado(vetor, TAM);
#endif // DEBUGSELECTION


     free(med);
     free(vetor);
return 0;
}
