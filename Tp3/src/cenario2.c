#include "cenario2.h"

void FLVazia(TipoLista* plv)
{
    plv->pPrimeiro = (Apontador)malloc(sizeof(TipoCelula));
    plv->pUltimo = plv->pPrimeiro;
    plv->pPrimeiro->pProx = NULL;
}

void Insere(Registro x, TipoLista* plv)
{
    plv->pUltimo->pProx = (Apontador)malloc(sizeof(TipoCelula));
    plv->pUltimo = plv->pUltimo->pProx;
    plv->pUltimo->registro = x;
    plv->pUltimo->pProx = NULL;
}