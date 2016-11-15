#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "med_3.h"

#define DEBUG


void quicksort(int *vetor, int esq, int dir){

    int pivo = esq, i,ch,j;         //Declaração das variavés e inicialização do pivo com o primeiro algarismo da sequencia
    for(i=esq+1;i<=dir;i++){        //Percorre todos os espaços do vetor
        j = i;                      //atribuição de valor
        if(vetor[j] < vetor[pivo]){     //verifica se o vetor da posição pivo é maior que de outra posição
         ch = vetor[j];               //ch recebe o valor que é menor
         while(j > pivo){           //repete enquanto o j que é a posição do algarismo menor que o pivo ficar na posição 0
            vetor[j] = vetor[j-1];      //reorganiza a posição de vetores
            j--;                    //decremento para a organização
         }
         vetor[j] = ch;               // atribuição da variavel menor que o pivo na posição inicial
         pivo++;                    // aumenta a posição do pivo em uma unidade
        }
    }
    if(pivo-1 >= esq){              // verifica se o valor do pivo é maior que o final do vetor.
        quicksort(vetor,esq,pivo-1);      //final da execursão da função
    }
    if(pivo+1 <= dir){              //verifica se o valor do pivo é menor, indicando que ainda estar dentro das limitações do vetor
        quicksort(vetor,pivo+1,dir);      //chama a função para ecutar novamente
    }
}



