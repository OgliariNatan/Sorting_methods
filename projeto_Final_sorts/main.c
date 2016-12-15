#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <process.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#include "bubbleSort.h"
#include "SelectionSorting.h"
#include "global_Uso.h"
#include "incercao.h"
#include "mergesort.h"
#include "quicksort.h"
#include "Heap_sort.h"

#define DEBUGBUBBLRSORT
#define DEBUGQUIKSORT
#define DEBUGINCERCAODIRETA
#define DEBUGINCERCAOBINARIA
#define DEBUGSELECTION
#define DEBUGHEAPSORT
#define DEBUGMERGE
//#define DEBUG  //!<Imprimi na tela e exporta para .txt


#define TAM 1000    //!< Ideal 1000000
#define VEZORDENACAO 20 //!< Ideal 20
#define TAMEXPORTA 100 //!< Define a quantidade de elementos a serem exportados

int main(){
    int i;
    clock_t inicio, fim;
    float desvio, media;
    float* tempos = malloc((sizeof(float))*VEZORDENACAO);
    int *vetor = (int*)malloc(sizeof(int)*TAM);

    if (vetor == NULL) {
        printf("Erro: ao criar o vetor\n");
        exit(EXIT_FAILURE);
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
        tempos[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo do Bubblesort[%d] %f [s]\n",i+1,tempos[i]);
    }
    media = media_tempos(tempos, VEZORDENACAO);
    printf("Media do BubbleSort vale: %f [s]\n",media);
    desvio = desvio_tempos(tempos, media, VEZORDENACAO);
    printf("O desvio padrao vale: %f \n",desvio);
#ifdef DEBUG
    exporta_txt(vetor, TAMEXPORTA, "BublleSort.txt");
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
        tempos[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo do QuickSort[%d] %f [s]\n",i+1, tempos[i]);
    }
    media = media_tempos(tempos, VEZORDENACAO);
    printf("Media do QuickSort vale: %f [s]\n",media);
    desvio = desvio_tempos(tempos, media, VEZORDENACAO);
    printf("O desvio padrao do Quicksort vale: %f \n",desvio);
#ifdef DEBUG
    exporta_txt(vetor, TAMEXPORTA, "QuickSort.txt");
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
        tempos[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo do IncercaoDireta[%d] %f [s]\n",i+1, tempos[i]);
    }
    media = media_tempos(tempos, VEZORDENACAO);
    printf("Media do IncercaoDireta vale: %f [s]\n",media);
    desvio = desvio_tempos(tempos, media, VEZORDENACAO);
    printf("O desvio padrao da IncercaoDireta vale: %f \n",desvio);
#ifdef DEBUG
    exporta_txt(vetor, TAMEXPORTA, "InsercaoDireta.txt");
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
        tempos[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo da Incercao Binaria[%d] %f [s]\n",i+1, tempos[i]);
    }
    media = media_tempos(tempos, VEZORDENACAO);
    printf("Media da Incercao Binaria vale: %f [s]\n",media);
    desvio = desvio_tempos(tempos, media, VEZORDENACAO);
    printf("O desvio padrao da Incercao Binariaa vale: %f \n",desvio);
#ifdef DEBUG
    exporta_txt(vetor, TAMEXPORTA, "InsercaoBinaria.txt");
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
        tempos[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo da Selecao Direta[%d] %f [s]\n",i+1, tempos[i]);
    }
    media = media_tempos(tempos, VEZORDENACAO);
    printf("Media da Selecao Direta vale: %f [s]\n",media);
    desvio = desvio_tempos(tempos, media, VEZORDENACAO);
    printf("O desvio padrao da Selecao Direta vale: %f \n",desvio);
#ifdef DEBUG
    exporta_txt(vetor, TAMEXPORTA, "SelecaoDireta.txt");
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

        tempos[i] = ((float) fim - (float) inicio ) / CLOCKS_PER_SEC;
        printf("Tempo do HeapSort[%d] %f [s]\n",i+1, tempos[i]);
        free(meu_heap);
    }
    media = media_tempos(tempos, VEZORDENACAO);
    printf("Media do HeapSort vale: %f [s]\n",media);
    desvio = desvio_tempos(tempos, media, VEZORDENACAO);
    printf("O desvio padrao do HeapSort vale: %f \n",desvio);
#ifdef DEBUG
    exporta_txt(vetor, TAMEXPORTA, "SelecaoHeapSort.txt");
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGHEAPSORT

#ifdef DEBUGMERGE //!< MergeSort
    puts("Metodo Merge Sort");
    media = 0;
    for (i=0; i<VEZORDENACAO; i++) {
        randomico(vetor,TAM);
        tempos[i] = merge_primeiro(vetor, TAM);
        printf("Tempo do MergeSort[%d] %f [s]\n",i+1, tempos[i]);
    }
    media = media_tempos(tempos, VEZORDENACAO);
    printf("Media do MergeSort vale: %f [s]\n",media);
    desvio = desvio_tempos(tempos, media, VEZORDENACAO);
    printf("O desvio padrao do MergeSort vale: %f \n",desvio);
#ifdef DEBUG
    exporta_txt(vetor, TAMEXPORTA, "MergeSort.txt");
    imprimi_ordenado(vetor, TAM);
#endif // DEBUG
    puts("---------------------");
#endif // DEBUGMERGE

    free(tempos);
    free(vetor);
    return 0;
}
