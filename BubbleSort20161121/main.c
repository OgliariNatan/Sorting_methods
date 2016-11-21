#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>

#include "bubbleSort.h"
#include "med_3.h"

//#define DEBUG
#define TAM 100000

int main()
{


     int x=0;
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


       inicio = clock();
       bubblesort(vetor, TAM);
       fim = clock();
       med = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
       printf("media %f\n",med);
       puts("----------------");

       #ifdef DEBUG
       puts("O vetor ordenado vale:");
        for (x=0; x<TAM; x++){
           printf("%d\n",vetor[x]);
        }
       #endif // DEBUG


    return 0;
}
