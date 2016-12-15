#ifndef GLOBAL_USO_H_INCLUDED
#define GLOBAL_USO_H_INCLUDED

void randomico(int *vetor, int TAM);

void imprimi_ordenado(int *vetor, int TAM);

void exporta_txt(int *vetor, int tamExporta, char *nomeArq);

void exportaTempo_txt (char *nomeArq, float media, float desvio, float *tempos, int tamExportaTempo);

int medianaDeTres (int *vetor, int esq, int dir);

void troca (int *vetor, int esq, int dir);

float desvio_tempos(float* tempos, float media, int n);

float media_tempos(float* tempos, int n);

#endif // GLOBAL_USO_H_INCLUDED
