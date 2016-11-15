#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>

#include "incercao.h"
#include "med_3.h"

//#define DEBUG
#define TAM 10000
int main()
{


     int x=0;
     float med;
     clock_t inicio, fim;

     int *vetor = (int*)malloc(sizeof(int)*TAM);

     srand(getpid()^time(NULL));

     for (x=0; x<TAM; x++){
          vetor[x] = rand();
          #ifdef DEBUG
               printf("%d\n",vetor[x]);
          #endif // DEBUG
     }


       medianaDeTres(vetor, 0, TAM-1);
       puts("----------------\n");

       for (x=0; x<TAM; x++){

          printf("%d\n",vetor[x]);
       }

       inicio = clock();
       insertsort(vetor, TAM);
       fim = clock();
       med = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
       printf("media %f",med);

    return 0;
}
