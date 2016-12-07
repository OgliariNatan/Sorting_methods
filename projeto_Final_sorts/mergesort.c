#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>
#include "mergesort.h"
#include "global_Uso.h"

//#define DEBUG

clock_t inicio, fim;

float merge_primeiro (int * vetor, int tam)
{

    int * tempvector  = malloc(sizeof(int) * tam);
    int esq =0, dir = tam-1;
    float tempo;

    inicio = clock();
    merge_sort(vetor, tempvector, esq, dir);
    fim = clock();
    tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;

#ifdef DEBUG
    printf("merge_primeiro\n");
#endif // DEBUG

    free(tempvector);
    return tempo;
}

void merge_sort ( int * vetor, int *tempvector, int esq, int dir )   //!< Função da ordenação
{

    int meio;

    if ( esq < dir )
    {

        meio = ( esq + dir ) / 2;

        merge_sort ( vetor, tempvector, esq, meio    );  //!<Chama recursivamente a função
        merge_sort ( vetor, tempvector, meio + 1, dir ); //!<Chama recursivamente a função

        funde (vetor, tempvector, esq, meio, dir );

    }
#ifdef DEBUG
    printf("merge_sort\n");
#endif // DEBUG
}

void funde ( int * vetor, int *tempvector, int esq, int meio, int dir )     //!< Realiza a fundição dos vetor já ordenados.
{
    int i = esq ;
    int j = esq ;
    int k = meio + 1;

#ifdef DEBUG
    printf("funde\n");
#endif // DEBUG

    while (j <= meio && k <= dir )
    {

        if ( vetor [j] < vetor [ k ])
            tempvector [ i ++] = vetor [j ++];
        else
            tempvector [ i ++] = vetor [k ++];
    }

    while (j <= meio )
        tempvector [ i ++] = vetor [j ++];

    for (i = esq ; i < k; i ++)
        vetor [i] = tempvector [ i ];
}
