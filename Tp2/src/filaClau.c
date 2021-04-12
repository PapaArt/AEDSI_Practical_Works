#include "filaClau.h"

void FFVazia(TFila *pFila)
{
    pFila->pFrente = 0;
    pFila->pTras = pFila->pFrente;
} /* FFVazia */

int FEhVazia(TFila *pFila)
{
    return (pFila->pFrente == pFila->pTras);
} /* FEhVazia */

int FEnfileira(TFila *pFila, TItem *pItem)
{
    if (((pFila->pTras + 1) % (MaxTam + 1)) == pFila->pFrente)
        return 0; /* fila cheia */
    pFila->vItem[pFila->pTras] = *pItem;
    pFila->pTras = (pFila->pTras + 1) % (MaxTam + 1);
    /*
 if (pFila->iTras == MaxTam) pFila->iTras = 0;
 else pFila->iTras++;
*/
    return 1;
} /* FEnfileira */
