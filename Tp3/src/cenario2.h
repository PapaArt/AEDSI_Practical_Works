#include "sorting.h"
#ifndef CENARIO2_H
#define CENARIO2_H

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

void FLVazia(TipoLista *plv);
void Insere(Registro x, TipoLista *plv);

#endif