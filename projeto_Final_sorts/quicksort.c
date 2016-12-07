#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "global_Uso.h"

#define DEBUG

int particionar (int *vetor, int esq, int dir);

void quicksort(int *vetor, int esq, int dir)
{
    int p;
    if(esq < dir)
    {
        p = particionar (vetor, esq, dir);
        quicksort(vetor, esq, p);
        quicksort(vetor, p+1, dir);
    }
}

int particionar (int *vetor, int esq, int dir)
{
#ifdef DEBUG
    puts("Particionar");
#endif // DEBUG
    int med, i, j, pivo;

    med = medianaDeTres(vetor, esq, dir);
    pivo = vetor[med];
    i = esq;
    j = dir+1;

    while(1)
    {
        do
        {
            i++;
            //puts("Primeiro while do");
        }
        while(vetor[i] < pivo);

        do
        {
            j--;
            //puts("segundo while do");
        }
        while (vetor[j] > pivo);

        if (i >= j)
        {
            return j;
        }
        troca(vetor, i, j);
    }
}






















/*
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
*/
