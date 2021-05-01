#include "cenarios.h"

void FLVazia(TipoLista* item)
{
    item->pPrimeiro = (Apontador)malloc(sizeof(TipoCelula));
    item->pUltimo = item->pPrimeiro;
    item->pPrimeiro->pProx = NULL;
}

void Insere(Registro x, TipoLista* item)
{
    item->pUltimo->pProx = (Apontador)malloc(sizeof(TipoCelula));
    item->pUltimo = item->pUltimo->pProx;
    item->pUltimo->registro = x;
    item->pUltimo->pProx = NULL;
}

void random_array(long long int* arr, int resposta)
{
    int i;
    for (i = 0; i < resposta; i++)
    {
        arr[i] = rand()%101;
    }
    for (i = 0; i < resposta; i++)
    {
        printf("%lld ", arr[i]);
    }printf("\n");
    
}