#include "sat.h"

void verificaNaTabela(TItem *pItem, int N)
{
    long long int n = 1 << N, i;
    long long int table[26][40];
    for (i = 0; i < n; i++)
        truthTable(i, N, pItem);
}
void imprimeItem(TItem *pItem, int N)
{
    printf("\nClausula: \n");
    //printf("%d %d %d\n", pItem->posicao1, pItem->posicao2, pItem->posicao3);
    printf("%d %d %d\n", pItem->valor1, pItem->valor2, pItem->valor3);
    verificaNaTabela(pItem, N);
}

void FLVazia(TipoLista *plv)
{
    plv->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    plv->Ultimo = plv->Primeiro;
    plv->Primeiro->Prox = NULL;
}

void Imprime(TipoLista plv, int N)
{
    TipoApontador Aux;
    Aux = plv.Primeiro->Prox;
    double tempo;
    clock_t fim, inicio;
    inicio = clock();

    while (Aux != NULL)
    {
        imprimeItem(&Aux->Item, N);
        Aux = Aux->Prox;
    }

    fim = clock();
    tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("\nTempo Gasto = %lf segundos\n\n\n", tempo);
}

void Insere(TItem x, TipoLista *plv)
{
    plv->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    plv->Ultimo = plv->Ultimo->Prox;
    plv->Ultimo->Item = x;
    plv->Ultimo->Prox = NULL;
}

//criar "percorrer" antes de adaptar a função abaixo
void geraclauses(TipoLista lista1, int (*mat)[50], int N)
{
    TItem registro1;
    FLVazia(&lista1);
    int C;
    int randomic1, randomic2, randomic3, test1, test2, test3;
    int aux;
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

        randomic1 = rand() % N;
        test1 = rand() % 3;
        if (test1 == 0)
        {
            test1++;
        }
        //mat[i][randomic1] = test1;

        randomic2 = rand() % N;
        test2 = rand() % 3;
        if (test2 == 0)
        {
            test2++;
        }

        while (randomic2 == randomic1)
        {
            randomic2 = rand() % N;
        }
        //mat[i][randomic2] = test2;

        randomic3 = rand() % N;
        test3 = rand() % 3;
        if (test3 == 0)
        {
            test3++;
        }

        while (randomic3 == randomic2 || randomic3 == randomic1)
        {
            randomic3 = rand() % N;
        }
        //mat[i][randomic3] = test3;

        if (randomic1 > randomic2)
        {
            aux = randomic1;
            randomic1 = randomic2;
            randomic2 = aux;
        }
        if (randomic1 > randomic3)
        {
            aux = randomic1;
            randomic1 = randomic3;
            randomic3 = aux;
        }
        if (randomic2 > randomic3)
        {
            aux = randomic2;
            randomic2 = randomic3;
            randomic3 = aux;
        }
        printf("Posicao ordenada: %d %d %d\n", randomic1, randomic2, randomic3);

        registro1.posicao1 = randomic1;
        registro1.posicao2 = randomic2;
        registro1.posicao3 = randomic3;
        registro1.valor1 = test1;
        registro1.valor2 = test2;
        registro1.valor3 = test3;
        Insere(registro1, &lista1);
    }
    printf("Imprimindo a lista...\n");
    //Imprime(lista1, N);
}
