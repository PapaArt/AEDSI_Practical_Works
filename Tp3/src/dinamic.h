#include "sorting.h"
#ifndef DINAMIC_H
#define DINAMIC_H
#define MAX_REG 1001
#include "cenarios.h"

typedef struct Register
{

    int chave;
    char string[10][200];
    float real_value[4];

} Register;

typedef struct
{

    int inicio, final;
    Registro* registros[MAX_REG];
    int quantidade;

} vetor;

vetor* iniciaVet();
Registro* iniciaReg();
int geraRegistro(Registro *item,vetor* vet, int pos);
void insereRegistro(Registro* item, vetor* vet , int pos);
void select_sort(vetor *vet,int flag);

#endif