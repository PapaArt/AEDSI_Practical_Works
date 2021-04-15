#include "sat.h"

void inicializaValor(TItem *item, int linha, int coluna, int valor, int posicao)
{
    item->coluna[0] = coluna;
    item->coluna[1] = coluna;
    item->coluna[2] = coluna;
    item->linha = linha;
    item->valor = valor;
    for (int i = 0; i < 50; i++)
    {
        item->posicao[i] = posicao;
    }
}

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
    if (pNovo == NULL)
        return 0;

    pFila->pTras->pProx = pNovo;
    pFila->pTras = pNovo;
    pNovo->item = *pItem;
    pNovo->pProx = NULL;
    return 1;

} /* FEnfileira */

//criar "percorrer" antes de adaptar a função abaixo
void geraclauses(TCelula* pCell, int (*mat)[50], int N)
{
    int C;
    int randomic1, randomic2, randomic3;
    int i, j;
    C = (N / 3) * 2;

    for (i = 0; i < C; i++)
    {
        for (j = 0; j < N; j++)
            mat[i][j] = 0;
    }

    srand(time(0));
    for (i = 0; i < C; i++)
    {
        pCell->item.coluna[0] = 0;
        pCell->item.coluna[1] = 0;
        pCell->item.coluna[2] = 0;

        randomic1 = rand() % N;
        pCell->item.coluna[0] = rand() % 3;
        if (pCell->item.coluna[0] == 0)
        {
            pCell->item.coluna[0]++;
        }
        mat[i][randomic1] = pCell->item.coluna[0];

        randomic2 = rand() % N;
        pCell->item.coluna[1] = rand() % 3;
        if (pCell->item.coluna[1] == 0)
        {
            pCell->item.coluna[1]++;
        }

        while (randomic2 == randomic1)
        {
            randomic2 = rand() % N;
        }
        mat[i][randomic2] = pCell->item.coluna[1];

        randomic3 = rand() % N;
        pCell->item.coluna[0] = rand() % 3;
        if (pCell->item.coluna[2] == 0)
        {
            pCell->item.coluna[2]++;
        }

        while (randomic3 == randomic2 || randomic3 == randomic1)
        {
            randomic3 = rand() % N;
        }
        mat[i][randomic3] = pCell->item.coluna[2];
        // printf("%d %d %d\n", pCell->item.coluna[0], pCell->item.coluna[1], pCell->item.coluna[2]);
    }
    for(i=0; i<C; i++){
		for(j=0; j<N; j++){
			printf("%d",mat[i][j]);
		}printf("\n");
    }
    percorre(pCell, mat, C, N);
}

int FDesenfileira(TFila *pFila, TItem *pItem)
{
    Apontador pAux;
    if (FEhVazia(pFila))
        return 0;

    pAux = pFila->pFrente;
    pFila->pFrente = pFila->pFrente->pProx;
    *pItem = pFila->pFrente->item;
    free(pAux);

    return 1;
}