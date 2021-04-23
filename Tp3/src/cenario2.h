#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#ifndef CENARIO2_H
#define CENARIO2_H

typedef struct Registro{
    
    int id;
    char string1[200],string2[200],string3[200],string4[200],string5[200]
        ,string6[200],string7[200],string8[200],string9[200],string10[200];
    int real_value1, real_value2, real_value3, real_value4;

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

void FLVazia(TipoLista *plv);
void Insere(Registro x, TipoLista *plv);

#endif