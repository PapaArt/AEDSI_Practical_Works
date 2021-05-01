#include "cenarios.h"

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

void random_array(int resposta)
{
    int i;
    for (i = 0; i < resposta; i++)
    {
        printf("%d ", rand()%100);
    }
}