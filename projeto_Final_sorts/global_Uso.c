#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <process.h>
#include <time.h>
#include <windows.h>
#include <math.h>

//#define DEBUG

void randomico(int *vetor, int TAM){
    int x;
#ifdef DEBUG
    puts("Vetor desordenado vale:");
#endif // DEBUG
    for (x=0; x<TAM; x++){
        vetor[x] = rand() + rand();
#ifdef DEBUG
        printf("%d\n",vetor[x]);
#endif // DEBUG
    }
}

void imprimi_ordenado(int *vetor, int TAM){

    int x;
    puts("O vetor ordenado vale:");
    for (x=0; x<TAM; x++){
        printf("%d\n",vetor[x]);
    }
}

void troca (int *vetor, int esq, int dir){ //!< Realiza a troca de dois elementos
    int ant_arry;

    ant_arry  = vetor[esq];
    vetor[esq] = vetor[dir];
    vetor[dir] = ant_arry;

#ifdef DEBUG
    printf("troca\n");
#endif // DEBUG
}

int medianaDeTres (int *vetor, int esq, int dir){ //!< Realiza a operação de Três


    int med = (esq + dir) / 2;

    if (vetor[dir] < vetor[esq])
        troca(vetor, esq, dir);

    if (vetor[med] < vetor[esq])
        troca(vetor, med, esq);

    if (vetor[dir] < vetor[med])
        troca(vetor, dir, med);

#ifdef DEBUG
    printf("medianaDeTres\n");
    printf("A posicao da med e: %d\n",med);
#endif // DEBUG

    return med;
}

void exporta_txt(int *vetor, int tamExporta, char *nomeArq){
     int x;
#ifdef DEBUG
    puts("Exporta_txt");
#endif // DEBUG

     FILE *fp = fopen(nomeArq,"w");

     if (fp == NULL){
          perror("Erro ao criar arquivo");
          exit(EXIT_FAILURE);
     }

     fprintf(fp,"%s\n",nomeArq);
     for(x=0; x<tamExporta; x++){
          fprintf(fp, "%d\n",vetor[x]);
     }

     fclose(fp);
}

float desvio_tempos(float* tempos, float media, int n){
    int k;
    float soma_desvios = 0;
    float desvio = 0;

    for(k=0; k<n; k++)
        soma_desvios += pow(tempos[k] - media,2);

    desvio = sqrt(soma_desvios/(n-1));

#ifdef DEBUG
    printf("\n desvio = %.8f s\n",desvio);
#endif // DEBUG
    return desvio;
}

float media_tempos(float* tempos, int n){
    int k;
    float soma_tempos = 0;
    float media = 0;

    for(k=0; k<n ;k++)
        soma_tempos += tempos[k];

    media = soma_tempos/n;
#ifdef DEBUG
    printf("\n media = %.8f s", media);
#endif // DEBUG

    return media;
}
