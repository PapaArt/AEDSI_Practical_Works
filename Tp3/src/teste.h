#include "sorting.h"
#ifndef TESTE_H
#define TESTE_H
#define MAX_REG 1000000

typedef struct Registro
{

    int chave;
    char string[10][200];
    float real_value[4];

} Registro;

typedef struct Celula *Apontador;
typedef struct Celula
{

    Registro registro;
    Apontador pProx;

} TipoCelula;

typedef struct
{

    Apontador pPrimeiro;
    Apontador pUltimo;

} TipoLista;

typedef struct
{

    int inicio, final;
    Registro* registros[MAX_REG];
    int quantidade;

} vetor;


void FLVazia(TipoLista *item);
void Insere(Registro *x, TipoLista *item);
void Imprime(TipoLista item);
void select_sort(vetor *vet,int flag);

#endif