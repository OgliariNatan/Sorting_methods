<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include "incercao.h"
#include "med_3.h"

//#define DEBUG

/** \brief ordanação por Inserção direta
 *
 * \param
 * \param
 * \return
 *
 */

void insertsortDireta (int *vetor, int t){
     int n, a;

     for (n=1; n<t; n++){

          for(a=n; a>0 && vetor[a-1] > vetor[a]; a--){
               troca(vetor, a, a-1);
          }
     }
}

/** \brief ordanação por Insercao Binaria
 *
 * \param vetor de n elementos
 * \param tamanho do vetor
 *
 */
void insercao_binaria(int *vetor, int tam){
     int i, j, tmp, meio, esq, dir;

     for (i=1; i<tam; i++){

          tmp = vetor[i];
          esq = 0;
          dir = i;
          while(esq<dir){
               meio = (esq+dir)/2;
               if (tmp >= vetor[tam])
                    esq = meio + 1;
               else
                    dir = meio;
          }
          for (j=i; j>esq; j--)
               troca(vetor, j-1, j);
     }
}
=======
#include <stdio.h>
#include <stdlib.h>
#include "incercao.h"
#include "med_3.h"

//#define DEBUG

/** \brief ordanaÃ§Ã£o por InserÃ§Ã£o direta
 *
 * \param
 * \param
 * \return
 *
 */

void insertsortDireta (int *vetor, int t){
     int n, a;

     for (n=1; n<t; n++){

          for(a=n; a>0 && vetor[a-1] > vetor[a]; a--){
               troca(vetor, a, a-1);
          }
     }
}

/** \brief ordanaÃ§Ã£o por Insercao Binaria
 *
 * \param vetor de n elementos
 * \param tamanho do vetor
 *
 */
void insercao_binaria(int *vetor, int tam){
     int i, j, tmp, meio, esq, dir;

     for (i=1; i<tam; i++){

          tmp = vetor[i];
          esq = 0;
          dir = i;
          while(esq<dir){
               meio = (esq+dir)/2;
               if (tmp >= vetor[tam])
                    esq = meio + 1;
               else
                    dir = meio;
          }
          for (j=i; j>esq; j--)
               troca(vetor, j-1, j);
     }
}
>>>>>>> f351e21b541af0018e7ca5363997b8eb344aeb06
