<<<<<<< HEAD

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mergesort.h"
#include "med_3.h"

//#define DEBUG

void merge_primeiro (int * vetor, int tam){
     int * tempvector  = malloc(sizeof(int) * tam);
     int esq =0, dir = tam-1;

     merge_sort(vetor, tempvector, esq, dir);

#ifdef DEBUG
     printf("merge_primeiro\n");
#endif // DEBUG

     free(tempvector);
}

void merge_sort ( int * vetor , int *tempvector, int esq , int dir ){//!< Função da ordenação

     int meio;

     if ( esq < dir ) {

          meio = ( esq + dir ) / 2;

          merge_sort ( vetor, tempvector , esq , meio    );//!<Chama recursivamente a função
          merge_sort ( vetor, tempvector , meio + 1, dir );//!<Chama recursivamente a função

          funde (vetor, tempvector , esq , meio , dir );

     }
#ifdef DEBUG
     printf("merge_sort\n");
#endif // DEBUG
}

void funde ( int * vetor, int *tempvector , int esq , int meio , int dir ) {//!< Realiza a fundição dos vetor já ordenados.
    int i = esq ;
    int j = esq ;
    int k = meio + 1;

#ifdef DEBUG
     printf("funde\n");
#endif // DEBUG

     while (j <= meio && k <= dir ) {

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

=======

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mergesort.h"
#include "med_3.h"

//#define DEBUG

void merge_primeiro (int * vetor, int tam){
     int * tempvector  = malloc(sizeof(int) * tam);
     int esq =0, dir = tam-1;

     merge_sort(vetor, tempvector, esq, dir);

#ifdef DEBUG
     printf("merge_primeiro\n");
#endif // DEBUG

     free(tempvector);
}

void merge_sort ( int * vetor , int *tempvector, int esq , int dir ){//!< FunÃ§Ã£o da ordenaÃ§Ã£o

     int meio;

     if ( esq < dir ) {

          meio = ( esq + dir ) / 2;

          merge_sort ( vetor, tempvector , esq , meio    );//!<Chama recursivamente a funÃ§Ã£o
          merge_sort ( vetor, tempvector , meio + 1, dir );//!<Chama recursivamente a funÃ§Ã£o

          funde (vetor, tempvector , esq , meio , dir );

     }
#ifdef DEBUG
     printf("merge_sort\n");
#endif // DEBUG
}

void funde ( int * vetor, int *tempvector , int esq , int meio , int dir ) {//!< Realiza a fundiÃ§Ã£o dos vetor jÃ¡ ordenados.
    int i = esq ;
    int j = esq ;
    int k = meio + 1;

#ifdef DEBUG
     printf("funde\n");
#endif // DEBUG

     while (j <= meio && k <= dir ) {

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

>>>>>>> f351e21b541af0018e7ca5363997b8eb344aeb06
