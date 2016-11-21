
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>

#include "incercao.h"
#include "med_3.h"

//#define DEBUG
#define TAM 1000
int main()
{
     int x=0;
     float medDireta, medBinaria;
     clock_t inicio, fim;

     int *vetor = (int*)malloc(sizeof(int)*TAM);

	 if (vetor == NULL){
          printf("Erro ao criar o vetor\n");
          exit(-1);
     }

     srand(getpid()^time(NULL));

     for (x=0; x<TAM; x++){
          vetor[x] = rand();
          #ifdef DEBUG
               printf("%d\n",vetor[x]);
          #endif // DEBUG
     }

       medianaDeTres(vetor, 0, TAM-1);
       puts("----------------\n");

       inicio = clock();
       insertsortDireta(vetor, TAM);
       fim = clock();
       medDireta = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
       printf("media Direta %f\n",medDireta);

       for (x=0; x<TAM; x++){
          vetor[x] = rand();
          #ifdef DEBUG
               printf("%d\n",vetor[x]);
          #endif // DEBUG
       }

       inicio = clock();
       //insercao_binaria(vetor, TAM);
       fim = clock();
       medBinaria = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
       printf("media Binaria %f\n",medBinaria);



    return 0;
}
