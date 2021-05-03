#include "sorting.h"
#ifndef CENARIOS_H
#define CENARIOS_H

typedef struct Registro{
    
    int chave;
    char string[10][200];
    float real_value[4];

}Registro;

typedef struct Celula* Apontador;
typedef struct Celula{

    Registro registro;
    Apontador pProx;

}TipoCelula;

typedef struct{

    Apontador pPrimeiro;
    Apontador pUltimo;

}TipoLista;

void FLVazia(TipoLista *item);
void Insere(Registro* x, TipoLista *item);
void Imprime(TipoLista item);
void random_array(long long int* arr, int resposta);
void random_id(Registro item);
void random_char(Registro* item);
void random_realvalue(Registro* item);
void geraReg(Registro item);

#endif