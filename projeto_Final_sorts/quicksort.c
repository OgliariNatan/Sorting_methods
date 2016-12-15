#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "quicksort.h"
#include "global_Uso.h"

//#define DEBUG

void quicksort(int *vetor, int esq, int dir){
     int i = esq, j = dir, pivo, med;

     med = medianaDeTres(vetor, esq, dir);
     pivo = vetor[med];

     do{
         while (vetor[i] < pivo)
               i++;
         while (pivo < vetor[j])
               j--;
         if (i <= j){
               troca(vetor, i, j);
               i++;
               j--;
          }
     } while (j>i);

          if (esq < j)
               quicksort(vetor, esq, j);
          if (i < dir)
               quicksort(vetor, i, dir);
}
