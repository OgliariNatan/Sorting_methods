#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

#define DEBUG

void quicksort(int *vetor, int esq, int dir){

    int pivo = esq, i,ch,j;
    for(i=esq+1;i<=dir;i++){
        j = i;
        if(vetor[j] < vetor[pivo]){
         ch = vetor[j];
         while(j > pivo){
            vetor[j] = vetor[j-1];
            j--;
         }
         vetor[j] = ch;
         pivo++;
        }
    }

    if(pivo-1 >= esq){
        quicksort(vetor,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        quicksort(vetor,pivo+1,dir);
    }
}
