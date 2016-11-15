#include <stdio.h>
#include <stdlib.h>
#include "incercao.h"
#include "med_3.h"

//#define DEBUG




void insertsort (int *vetor, int t){
     int n, a;

     for (n=1; n<t; n++){

          for(a=n; a>0 && vetor[a-1] > vetor[a]; a--){
               troca(vetor, a, a-1);
          }
     }
}

