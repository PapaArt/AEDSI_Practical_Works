#include "filaClau.h"

void FFVazia(TFila *pFila)
{
    pFila->pFrente = (Apontador)malloc(sizeof(TCelula));
    pFila->pTras = pFila->pFrente;
    pFila->pFrente->pProx = NULL;
} /* FFVazia */

int FEhVazia(TFila *pFila)
{
    return (pFila->pFrente == pFila->pTras);
} /* FEhVazia */

int FEnfileira(TFila *pFila, TItem *pItem)
{
    Apontador pNovo;
    pNovo = (Apontador)malloc(sizeof(TCelula));
    if (pNovo == NULL) return 0;

    pFila->pTras->pProx = pNovo;
    pFila->pTras = pNovo;
    pNovo->item = *pItem;
    pNovo->pProx = NULL;
    return 1;
} /* FEnfileira */

int fDesenfileira(TFila* pFila, TItem* pItem)
{
    Apontador pAux;
    if (FEhVazia(pFila)) return 0;

    pAux = pFila->pFrente;
    pFila->pFrente = pFila->pFrente->pProx;
    *pItem = pFila->pFrente->item;
    free(pAux);

    return 1;
}