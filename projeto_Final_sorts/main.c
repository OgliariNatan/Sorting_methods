#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <process.h>
#include <time.h>
#include <windows.h>

#include "bubbleSort.h"
#include "SelectionSorting.h"
#include "global_Uso.h"
#include "incercao.h"
#include "mergesort.h"
#include "quicksort.h"
#include "Heap_sort.h"

#define DEBUGBUBBLRSORT
//#define DEBUGQUIKSORT
//#define DEBUGINCERCAODIRETA
//#define DEBUGINCERCAOBINARIA
//#define DEBUGSELECTION
//#define DEBUGHEAPSORT //!<FALTA
//#define DEBUGMERGE
#define DEBUG


#define TAM 10000    //!< Ideal 1000000
#define VEZORDENACAO 10 //!< Ideal 20
#define TAMEXPORTA 501 //!< Define a quantidade de elementos a serem exportados

int main(){
    int i=0;
    char nomeArq[20];
    clock_t inicio, fim;
    float tempo;
    int *vetor = (int*)malloc(sizeof(int)*TAM);

    if (vetor == NULL) {
        printf("Erro: ao criar o vetor\n");
        exit(-1);
    }

    srand(getpid()^time(NULL));//!<Alimenta a semente

#ifdef DEBUGBUBBLRSORT //!< BUBLLE SORT
    puts("Metodo Bubble Sort");
    for (i=0; i<VEZORDENACAO; i++)
    {
        randomico(vetor,TAM);
        medianaDeTres(vetor, 0, TAM-1);
        inicio = clock();
        bubblesort(vetor, TAM);
        fim = clock();
        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo do Bubblesort[%d] %f [s]\n",i+1,tempo);
    }
#ifdef DEBUG
    strcpy(nomeArq, "BublleSort.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGBUBBLRSORT

#ifdef DEBUGQUIKSORT //!< QUICK SORT
    puts("Metodo Quiksort");
    for (i=0; i<VEZORDENACAO; i++) {
        randomico(vetor,TAM);
        medianaDeTres(vetor, 0, TAM-1);
        inicio = clock();
        quicksort(vetor, 0, TAM-1);
        fim = clock();
        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo do QuickSort[%d] %f [s]\n",i+1, tempo);
    }
#ifdef DEBUG
    strcpy(nomeArq, "QuickSort.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGQUIKSORT

#ifdef DEBUGINCERCAODIRETA //!<Inserção Direta
    puts("Metodo Incercao Direta");
    for (i=0; i<VEZORDENACAO; i++) {
        randomico(vetor,TAM);
        inicio = clock();
        insertsortDireta(vetor, TAM);
        fim = clock();
        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo do IncercaoDireta[%d] %f [s]\n",i+1, tempo);
    }
#ifdef DEBUG
    strcpy(nomeArq, "InsercaoDireta.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGINCERCAODIRETA

#ifdef DEBUGINCERCAOBINARIA //!<Inserção Binária
    puts("Metodo Incercao Binaria");
    for (i=0; i<VEZORDENACAO; i++) {
        randomico(vetor,TAM);
        inicio = clock();
        insercao_binaria(vetor, TAM);
        fim = clock();
        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo do IncercaoBinaria[%d] %f [s]\n",i+1, tempo);
    }
#ifdef DEBUG
    strcpy(nomeArq, "InsercaoBinaria.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGINCERCAOBINARIA


#ifdef DEBUGSELECTION //!< Seleção Direta
    puts("Metodo Selection");
    for (i=0; i<VEZORDENACAO; i++) {
        randomico(vetor,TAM);
        inicio = clock();
        select_sort(vetor, TAM);
        fim = clock();
        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo do SelectionSorting[%d] %f [s]\n",i+1, tempo);
    }
#ifdef DEBUG
    strcpy(nomeArq, "SelecaoDireta.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGSELECTION



#ifdef DEBUGHEAPSORT //!< Seleção HEAPSORT
    puts("Metodo Heap Sort");
    puts("NAO IMPLEMENTADO");
    for (i=0; i<VEZORDENACAO; i++){
        randomico(vetor,TAM);
        inicio = clock();
        cria_heapSort(vetor, TAM);
        fim = clock();
        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo do HeapSort[%d] %f [s]\n",i+1, tempo);
    }
#ifdef DEBUG
    strcpy(nomeArq, "SelecaoHeapSort.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGHEAPSORT



#ifdef DEBUGMERGE //!< MergeSort
    puts("Metodo Merge Sort");
    for (i=0; i<VEZORDENACAO; i++) {
        randomico(vetor,TAM);
        tempo = merge_primeiro(vetor, TAM);
        printf("Tempo do MergeSort[%d] %f [s]\n",i+1, tempo);
    }
#ifdef DEBUG
    strcpy(nomeArq, "MergeSort.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGMERGE


    free(vetor);
    return 0;
}
