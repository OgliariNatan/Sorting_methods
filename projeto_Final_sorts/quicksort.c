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

/*
void quicksort(int *vetor, int esq, int dir){
    int p;
    if(esq < dir) {
        p = particionar (vetor, esq, dir);
        puts("Quick esquerdo");
        quicksort(vetor, esq, p);
        Sleep(200);
        quicksort(vetor, p+1, dir);
        puts("Quick direito");
        Sleep(200);
        printf("---------------------------------------------------P: %d\n",p);
    }
}

int particionar (int *vetor, int esq, int dir){
#ifdef DEBUG
    puts("Particionar");
    Sleep(200);
#endif // DEBUG
    int med, i, j, pivo;

    med = medianaDeTres(vetor, esq, dir);
    pivo = vetor[med];
    i = esq;
    j = dir+1;

    while(1){
        do{
            i++;
            puts("Primeiro while do");
            //Sleep(200);
        }while(vetor[i] < pivo);

        do{
            j--;
            puts("segundo while do");
            //Sleep(200);
        } while (vetor[j] > pivo);

        if (i >= j){
            return j;
        }
        troca(vetor, i, j);
    }
}
*/
