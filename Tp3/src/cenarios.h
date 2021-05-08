#include "sorting.h"
#ifndef CENARIOS_H
#define CENARIOS_H

typedef struct Registro
{

    int chave;
    char string[10][200];
    float real_value[4];

} Registro;

typedef struct
{
    Registro registros;
} vetor;

void inicializa(vetor* vet, int tam);
void imprime(vetor* vet, int tam);
void arquivoX(long long int *comparacoes, long long int *movimentacoes, double* tempo, int valor);

#endif