
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>

#include "SelectionSorting.h"
#include "med_3.h"

//#define DEBUG
#define TAM 100000     //!< Ideal 1000000
#define VEZORDENACAO 20 //!< Ideal 20

int main()
{
    int x=0, i;
    int *vetor;
	float med;
    clock_t inicio, fim;

    vetor = (int*)malloc(sizeof(int)*TAM);

    srand(getpid()^time(NULL));

     for (x=0; x<TAM; x++){
          vetor[x] = rand();
          #ifdef DEBUG
               printf("%d\n",vetor[x]);
          #endif // DEBUG
     }
     puts("---------------");

     #ifdef DEBUG
       medianaDeTres(vetor, 0, TAM-1);
       puts("----------------\n");
     #endif // DEBUG

     #ifdef DEBUG
       for (x=0; x<TAM; x++){

          printf("%d\n",vetor[x]);
       }
     #endif // DEBUG

     for (i=1; i<=VEZORDENACAO; i++){
          for (x=0; x<TAM; x++){
               vetor[x] = rand();
               #ifdef DEBUG
                    printf("%d\n",vetor[x]);
               #endif // DEBUG
          }
          inicio = clock();
          select_sort(vetor, TAM);
          fim = clock();
          med = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media[%d] %f\n",i, med);
     }

     free(vetor);

    return 0;
}
