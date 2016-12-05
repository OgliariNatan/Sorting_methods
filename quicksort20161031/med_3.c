#include <stdio.h>
#include <stdlib.h>

#include "med_3.h"

//#define DEBUG


int medianaDeTres (int *vetor, int esq, int dir){//!< Realiza a operação de Três

     int med;

     med = (esq + dir) / 2;

     if (vetor[esq] > vetor[dir])
          troca(vetor, esq, med);

     if (vetor[esq] > vetor[dir])
          troca(vetor, esq, dir);

     if (vetor[med] >
          vetor[dir])
          troca(vetor, med, dir);

     #ifdef DEBUG
          printf("medianaDeTres\n");
          printf("A posicao da med e: %d\n",med);
     #endif // DEBUG

     return med;
}

void troca (int *vetor, int esq, int dir){//!< Realiza a troca de dois elementos
     int ant_arry;

     ant_arry  = vetor[esq];
     vetor[esq] = vetor[dir];
     vetor[dir] = ant_arry;

     #ifdef DEBUG
          printf("troca\n");
     #endif // DEBUG
}
