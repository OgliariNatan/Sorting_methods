
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>
#include "mergesort.h"
#include "med_3.h"

//#define DEBUG
#define TAM 1000000     //!< Ideal 1000000
#define VEZORDENACAO 20 //!< Ideal 20

int main()
{
     int x, i;
     float med;
     clock_t inicio, fim;
     int *vetor = malloc(sizeof(int)*TAM);

     for (x=0; x<TAM; x++){
          vetor[x] = rand();
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
          inicio = clock();
          merge_primeiro(vetor, TAM);
          fim = clock();
          med = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
          printf("media[%d] %f\n",i, med);
     }

     #ifdef DEBUG
          puts("----------------");
          printf("Ordenado\n");
          for (x=0; x<TAM; x++){
               printf("%d\n",vetor[x]);
          }
          puts("----------------");
     #endif // DEBUG

    return 0;
}
