#include <stdio.h>
#include <stdlib.h>

#define DEBUG

void bubblesort (int * vetor, int TAM)
{
    int i;
    int j;
    int aux;
    int k = TAM - 1 ;

    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < k; j++)
        {
            if(vetor[j] > vetor[j+1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1]=aux;
            }
        }
        k--;
    }
}
