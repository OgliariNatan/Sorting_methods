<<<<<<< HEAD

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>

#include "incercao.h"
#include "med_3.h"

//#define DEBUG
#define TAM 10000     //!< Ideal 1000000
#define VEZORDENACAO 5 //!< Ideal 20

int main()
{
     int x=0, i;
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
       puts("----------------");

       for (i=1; i<=VEZORDENACAO; i++){
               inicio = clock();
               insertsortDireta(vetor, TAM);
               fim = clock();
               medDireta = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
               printf("media Direta[%d] %f\n", i, medDireta);

               for (x=0; x<TAM; x++){
                    vetor[x] = rand();
                    #ifdef DEBUG
                         printf("%d\n",vetor[x]);
                    #endif // DEBUG
               }

               inicio = clock();
               insercao_binaria(vetor, TAM);
               fim = clock();
               medBinaria = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
               printf("media Binaria[%d] %f\n\n", i, medBinaria);
       }
       puts("----------------");

     free(vetor);
    return 0;
}
=======
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>

#include "incercao.h"
#include "med_3.h"

//#define DEBUG
#define TAM 10000     //!< Ideal 1000000
#define VEZORDENACAO 5 //!< Ideal 20

int main()
{
     int x=0, i;
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
       puts("----------------");

       for (i=1; i<=VEZORDENACAO; i++){
               inicio = clock();
               insertsortDireta(vetor, TAM);
               fim = clock();
               medDireta = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
               printf("media Direta[%d] %f\n", i, medDireta);

               for (x=0; x<TAM; x++){
                    vetor[x] = rand();
                    #ifdef DEBUG
                         printf("%d\n",vetor[x]);
                    #endif // DEBUG
               }

               inicio = clock();
               insercao_binaria(vetor, TAM);
               fim = clock();
               medBinaria = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
               printf("media Binaria[%d] %f\n\n", i, medBinaria);
       }
       puts("----------------");

     free(vetor);
    return 0;
}
>>>>>>> f351e21b541af0018e7ca5363997b8eb344aeb06
