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

//#define DEBUGBUBBLRSORT
#define DEBUGQUIKSORT
#define DEBUGINCERCAODIRETA
#define DEBUGINCERCAOBINARIA
#define DEBUGSELECTION
#define DEBUGHEAPSORT
#define DEBUGMERGE
#define DEBUG  //!<Imprimi na tela e exporta para .txt


#define TAM 1000000    //!< Ideal 1000000
#define VEZORDENACAO 20 //!< Ideal 20
#define TAMEXPORTA 100 //!< Define a quantidade de elementos a serem exportados

int main(){
    int i=0;
    char nomeArq[20];
    clock_t inicio, fim;
    float tempo, media;
    int *vetor = (int*)malloc(sizeof(int)*TAM);

    if (vetor == NULL) {
        printf("Erro: ao criar o vetor\n");
        exit(-1);
    }

    srand(getpid()^time(NULL));//!<Alimenta a semente

#ifdef DEBUGBUBBLRSORT //!< BUBLLE SORT
    puts("Metodo Bubble Sort");
    media = 0;
    for (i=0; i<VEZORDENACAO; i++)
    {
        randomico(vetor,TAM);
        inicio = clock();
        bubblesort(vetor, TAM);
        fim = clock();
        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        media = media + tempo;
        printf("Tempo do Bubblesort[%d] %f [s]\n",i+1,tempo);
    }
    printf("Media do BubbleSort vale: %f\n",media/VEZORDENACAO);
#ifdef DEBUG
    strcpy(nomeArq, "BublleSort.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGBUBBLRSORT

#ifdef DEBUGQUIKSORT //!< QUICK SORT
    puts("Metodo Quiksort");
    media = 0;
    for (i=0; i<VEZORDENACAO; i++) {
        randomico(vetor,TAM);
        medianaDeTres(vetor, 0, TAM-1);
        inicio = clock();
        quicksort(vetor, 0, TAM-1);
        fim = clock();
        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        media = media + tempo;
        printf("Tempo do QuickSort[%d] %f [s]\n",i+1, tempo);
    }
    printf("Media do QuickSort vale: %f\n",media/VEZORDENACAO);
#ifdef DEBUG
    strcpy(nomeArq, "QuickSort.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGQUIKSORT

#ifdef DEBUGINCERCAODIRETA //!<Inserção Direta
    puts("Metodo Incercao Direta");
    media = 0;
    for (i=0; i<VEZORDENACAO; i++) {
        randomico(vetor,TAM);
        inicio = clock();
        insertsortDireta(vetor, TAM);
        fim = clock();
        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        media = media + tempo;
        printf("Tempo do IncercaoDireta[%d] %f [s]\n",i+1, tempo);
    }
    printf("Media do IncercaoDireta vale: %f\n",media/VEZORDENACAO);
#ifdef DEBUG
    strcpy(nomeArq, "InsercaoDireta.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGINCERCAODIRETA

#ifdef DEBUGINCERCAOBINARIA //!<Inserção Binária
    puts("Metodo Incercao Binaria");
    media = 0;
    for (i=0; i<VEZORDENACAO; i++) {
        randomico(vetor,TAM);
        inicio = clock();
        insercao_binaria(vetor, TAM);
        fim = clock();
        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        media = media + tempo;
        printf("Tempo da Incercao Binaria[%d] %f [s]\n",i+1, tempo);
    }
    printf("Media da Incersao Binaria vale: %f\n",media/VEZORDENACAO);
#ifdef DEBUG
    strcpy(nomeArq, "InsercaoBinaria.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGINCERCAOBINARIA


#ifdef DEBUGSELECTION //!< Seleção Direta
    puts("Metodo Selection");
    media = 0;
    for (i=0; i<VEZORDENACAO; i++) {
        randomico(vetor,TAM);
        inicio = clock();
        select_sort(vetor, TAM);
        fim = clock();
        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        media = media + tempo;
        printf("Tempo da Selecao Direta[%d] %f [s]\n",i+1, tempo);
    }
    printf("Media da Selecao Direta vale: %f\n",media/VEZORDENACAO);
#ifdef DEBUG
    strcpy(nomeArq, "SelecaoDireta.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGSELECTION



#ifdef DEBUGHEAPSORT //!< Seleção HEAPSORT
    puts("Metodo Heap Sort");
    media = 0;
    for (i=0; i<VEZORDENACAO; i++){
        heap_t *meu_heap;
        meu_heap = cria_heap(vetor, TAM);
        randomico(vetor,TAM);

        inicio = clock();
        heapsort(meu_heap, TAM);
        fim = clock();

        tempo = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        media = media + tempo;
        printf("Tempo do HeapSort[%d] %f [s]\n",i+1, tempo);
        free(meu_heap);
    }
    printf("Media da Selecao HeapSort vale: %f\n",media/VEZORDENACAO);
#ifdef DEBUG
    strcpy(nomeArq, "SelecaoHeapSort.txt");
    exporta_txt(vetor, TAMEXPORTA, nomeArq);
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGHEAPSORT



#ifdef DEBUGMERGE //!< MergeSort
    puts("Metodo Merge Sort");
    media = 0;
    for (i=0; i<VEZORDENACAO; i++) {
        randomico(vetor,TAM);
        tempo = merge_primeiro(vetor, TAM);
        media = media + tempo;
        printf("Tempo do MergeSort[%d] %f [s]\n",i+1, tempo);
    }
    printf("Media do MergeSort vale: %f\n",media/VEZORDENACAO);
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
