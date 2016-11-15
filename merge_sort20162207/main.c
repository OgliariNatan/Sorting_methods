#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>
#include "mergesort.h"
#include "med_3.h"

#define DEBUG
#define TAM 10

int main()
{
     int x;
     float med;
     clock_t inicio, fim;
     int *vetor = malloc(sizeof(int)*TAM);

     for (x=0; x<TAM; x++){
          vetor[x] = rand()%1000;
          #ifdef DEBUG
               printf("%d\n",vetor[x]);
          #endif // DEBUG
     }

     medianaDeTres(vetor, 0, TAM-1);
     puts("----------------");

     inicio = clock();
     merge_primeiro(vetor, TAM);
     fim = clock();
     med = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
     printf("media %.3f\n",med);


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
