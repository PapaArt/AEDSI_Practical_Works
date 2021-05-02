#include "cenarios.h"

void FLVazia(TipoLista *item)
{
    item->pPrimeiro = (Apontador)malloc(sizeof(TipoCelula));
    item->pUltimo = item->pPrimeiro;
    item->pPrimeiro->pProx = NULL;
}

void Insere(Registro x, TipoLista *item)
{
    item->pUltimo->pProx = (Apontador)malloc(sizeof(TipoCelula));
    item->pUltimo = item->pUltimo->pProx;
    item->pUltimo->registro = x;
    item->pUltimo->pProx = NULL;
}

void random_array(long long int *arr, int resposta)
{
    int i;
    for (i = 0; i < resposta; i++)
    {
        arr[i] = rand() % 101;
    }
}

void random_id(Registro *item)
{
    item->chave = rand() % 101;
}

void random_char(Registro *item)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 200; j++)
        {
            item->string[i][j] = 'a' + (char)(rand() % 26);
        }
    }
}

void random_realvalue(Registro *item)
{
    for (int i = 0; i < 4; i++)
    {
        
    }
}