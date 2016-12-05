#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>

#include "bubbleSort.h"
#include "med_3.h"
#include "SelectionSorting.h"

#define DEBUGBUBBLRSORT
#define DEBUGSELECTION
//#define DEBUG
#define TAM 10000     //!< Ideal 1000000
#define VEZORDENACAO 20 //!< Ideal 20

int main()
{


     int x=0,i;
     float med;
     clock_t inicio, fim;

     int *vetor = (int*)malloc(sizeof(int)*TAM);

	 if (vetor == NULL){
          printf("Erro: ao criar o vetor\n");
          exit(-1);
	 }

     srand(getpid()^time(NULL));

     for (x=0; x<TAM; x++){
          vetor[x] = rand()%600;
          #ifdef DEBUG
               printf("%d\n",vetor[x]);
          #endif // DEBUG
     }


       medianaDeTres(vetor, 0, TAM-1);
       puts("----------------");


for (i=1; i<=VEZORDENACAO; i++){
          for (x=0; x<TAM; x++){
               vetor[x] = rand();
               #ifdef DEBUG
                    printf("%d\n",vetor[x]);
               #endif // DEBUG
          }
#ifdef DEBUGBUBBLRSORT
       inicio = clock();
       bubblesort(vetor, TAM);
       fim = clock();
       med = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
       printf("media do Bubblesort[%d] %f\n",i,med);
       puts("----------------");
#endif // DEBUGBUBBLRSORT


#ifdef DEBUGSELECTION
          inicio = clock();
          select_sort(vetor, TAM);
          fim = clock();
          med = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media do Sels[%d] %f\n",i, med);
#endif // DEBUGSELECTION


     }


       #ifdef DEBUG
       puts("O vetor ordenado vale:");
        for (x=0; x<TAM; x++){
           printf("%d\n",vetor[x]);
        }
       #endif // DEBUG


    return 0;
}
