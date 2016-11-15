#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "med_3.h"

#define DEBUG


void quicksort(int *vetor, int esq, int dir){

    int pivo = esq, i,ch,j;         //Declara��o das variav�s e inicializa��o do pivo com o primeiro algarismo da sequencia
    for(i=esq+1;i<=dir;i++){        //Percorre todos os espa�os do vetor
        j = i;                      //atribui��o de valor
        if(vetor[j] < vetor[pivo]){     //verifica se o vetor da posi��o pivo � maior que de outra posi��o
         ch = vetor[j];               //ch recebe o valor que � menor
         while(j > pivo){           //repete enquanto o j que � a posi��o do algarismo menor que o pivo ficar na posi��o 0
            vetor[j] = vetor[j-1];      //reorganiza a posi��o de vetores
            j--;                    //decremento para a organiza��o
         }
         vetor[j] = ch;               // atribui��o da variavel menor que o pivo na posi��o inicial
         pivo++;                    // aumenta a posi��o do pivo em uma unidade
        }
    }
    if(pivo-1 >= esq){              // verifica se o valor do pivo � maior que o final do vetor.
        quicksort(vetor,esq,pivo-1);      //final da execurs�o da fun��o
    }
    if(pivo+1 <= dir){              //verifica se o valor do pivo � menor, indicando que ainda estar dentro das limita��es do vetor
        quicksort(vetor,pivo+1,dir);      //chama a fun��o para ecutar novamente
    }
}



