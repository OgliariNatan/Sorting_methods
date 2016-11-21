
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
     int i, x, L, R, m, j;
     for(i=2;i<=tam;i++){
           x = vetor[i];
           L = 1;
           R = i;
           while(L<R){
               m = (L+R) / 2;
               if(vetor[m] <= x)
                  L = m + 1;
               else
                 R = m;
          }
          for(j=i;j>R;j++)
               vetor[j] = vetor[j-1];
          vetor[R] = x;
     }
}
