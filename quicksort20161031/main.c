#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>

#include "quicksort.h"
#include "med_3.h"

//#define DEBUG
#define TAM 10

int main(){

     int x=0;
     int *vetor;
     float med;
     clock_t inicio, fim;

     vetor = (int*)malloc(sizeof(int)*TAM);

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
     quicksort(vetor, 0, TAM);
     fim = clock();
     med = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
     printf("media %.4f\n\n",med);

     #ifdef DEBUG
          puts("O vetor ordenado: ");
          for (x=0; x<TAM; x++){
               printf("%d\n",vetor[x]);
       }
     #endif // DEBUG

	free(vetor);
    return 0;
}
