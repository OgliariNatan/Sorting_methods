#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>

#include "global_Uso.h"

//#define DEBUG

void select_sort ( int * vetor, int n ){
    int i, j, max = 0;

    for (i=n; i>1; i--) {

        max = 0;//!<Indice do vetor

        for (j = 1; j < i; j ++)
            if ( vetor [j] > vetor [max])
                max = j ;
        troca (vetor,i - 1, max);
    }
#ifdef DEBUG
    printf("A troca vale:\t");
    for(j=0; j<n; j++)
        printf(" %d, ",vetor[j]);
    printf("\n");
#endif // DEBUG
}
