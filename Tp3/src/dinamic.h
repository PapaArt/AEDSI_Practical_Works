#include "sorting.h"
#ifndef DINAMIC_H
#define DINAMIC_H
#define MAX_REG 1000000

typedef struct Registro
{

    int chave;
    char string[10][200];
    float real_value[4];

} Registro;

typedef struct
{

    int inicio, final;
    Registro* registros[MAX_REG];
    int quantidade;

} vetor;

Registro* iniciaReg();
int geraReg(Registro *item,vetor* vet, int pos);
void select_sort(vetor *vet,int flag);

#endif