#include "filaClau.h"

void inicializaValor(TItem *item, int linha, int coluna, int valor)
{

    item->coluna = coluna;
    item->linha = linha;
    item->valor = valor;
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

int FEnfileira(TFila *pFila, TItem *pItem, int coluna)
{
    Apontador pNovo;
    pNovo = (Apontador)malloc(sizeof(TCelula));
    if (pNovo == NULL)
        return 0;

    pFila->pTras->pProx = pNovo;
    pFila->pTras = pNovo;
    pNovo->item = *pItem;
    pNovo->item.coluna = coluna;
    pNovo->pProx = NULL;
    return 1;

} /* FEnfileira */

void valorRand(TFila *pFila, int N, int C, int coluna)
{
    TFila *aux;
    aux = pFila->pFrente;
    int valor;
    while ((aux->pFrente->item.coluna) != coluna)
    {
        aux = aux->pFrente->pProx;
    }
    if ((aux->pFrente->item.coluna) != coluna)
    {
        valor = rand() % 3;
        if (valor == 0)
        {
            valor++;
        }
        aux->pFrente->item.valor = valor;
    }
}
//criar "percorrer" antes de adaptar a função abaixo
void geraclauses(int (*mat)[50], int N)
{

    int C;
    int randomic1, randomic2, randomic3, test1, test2, test3;
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
        int test1 = 0;
        int test2 = 0;
        int test3 = 0;

        randomic1 = rand() % N;
        // test1 = rand() % 3;
        // if (test1 == 0)
        // {
        //     test1++;
        // }
        mat[i][randomic1] = test1;

        randomic2 = rand() % N;

        // test2 = rand() % 3;

        // if (test2 == 0)
        // {
        //     test2++;
        // }
        while (randomic2 == randomic1)
        {
            randomic2 = rand() % N;
        }

        mat[i][randomic2] = test2;

        randomic3 = rand() % N;

        // test3 = rand() % 3;
        // if (test3 == 0)
        // {
        //     test3++;
        // }

        while (randomic3 == randomic2 || randomic3 == randomic1)
        {
            randomic3 = rand() % N;
        }
        mat[i][randomic3] = test3;
    }
    //percorrer(mat, N, 2, N, C);
    //printa tabela geral
    // for(i=0; i<C; i++){
    // 	for(j=0; j<N; j++){
    // 		printf("%d",mat[i][j]);

    // 	}printf("\n");
    // }
}

int fDesenfileira(TFila *pFila, TItem *pItem)
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