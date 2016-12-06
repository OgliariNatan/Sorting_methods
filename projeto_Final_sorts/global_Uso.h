#ifndef GLOBAL_USO_H_INCLUDED
#define GLOBAL_USO_H_INCLUDED

void randomico(int *vetor, int TAM);

void imprimi_ordenado(int *vetor, int TAM);

void exporta_txt(int *vetor, int tamExporta, char *nomeArq, float *med);

int medianaDeTres (int *vetor, int esq, int dir);//!<return "int med"

void troca (int *vetor, int esq, int dir);//!< return "NADA"

#endif // GLOBAL_USO_H_INCLUDED
