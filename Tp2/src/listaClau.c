#include "sat.h"

// A funçao abaixo realiza as comparações utilizando a tabela verdade
// a cláusula é passada como parâmetro para verificação e para é testada em cada linha da tebela verdade
// dentro da função truthTable
void verificaNaTabela(TItem *pItem, int N)
{
    long long int n = 1 << N, i;
    long long int table[26][40];
    for (i = 0; i < n; i++)
        truthTable(i, N, pItem);
}

// É reponsável por imprimir a cláusula gerada e chamar a função de verificação
void imprimeItem(TItem *pItem, int N)
{
    //getchar();
    printf("\nClausula: \n");
    printf("( %sx%d | %sx%d | %sx%d )\n", (pItem->valor1 == 1 ? "!" : ""), pItem->posicao1, (pItem->valor2 == 1 ? "!" : ""), pItem->posicao2, (pItem->valor3 == 1 ? "!" : ""), pItem->posicao3);
    //printf("Pressione Enter para visualizar os valores booleanos que satisfazem a clausula.");
    //getchar();
    verificaNaTabela(pItem, N);
    //printf("\nPressione Enter para visualizar a proxima clausula.");
}

// Gera Lista vazia
void FLVazia(TipoLista *plv)
{
    plv->Primeiro = (TipoApontador)malloc(sizeof(TipoCelula));
    plv->Ultimo = plv->Primeiro;
    plv->Primeiro->Prox = NULL;
}

// Essa função é reponsável por medir o tempo de execução ao imprimir item por item da lista encadeada
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

// Função responsável por inserir os itens na lista encadeada
void Insere(TItem x, TipoLista *plv)
{
    plv->Ultimo->Prox = (TipoApontador)malloc(sizeof(TipoCelula));
    plv->Ultimo = plv->Ultimo->Prox;
    plv->Ultimo->Item = x;
    plv->Ultimo->Prox = NULL;
}

// Principal função do tp, reponsável por gerar a lista encadeada vazia, gerar randomicamente as colunas para geração
// das cláusulas, inserílas na lista e chamar a função imprime
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

        registro1.posicao1 = randomic1;
        registro1.posicao2 = randomic2;
        registro1.posicao3 = randomic3;
        registro1.valor1 = test1;
        registro1.valor2 = test2;
        registro1.valor3 = test3;
        Insere(registro1, &lista1);
    }
    Imprime(lista1, N);
}

void manual()
{
    int C = 0;
    int N = 0;
    printf("Insira o Numero C de cláusulas: ");
    scanf("%d\n", C);
    printf("Insira o Numero N de variáveis: ");
    scanf("%d\n", N);

    TipoLista lista2;
    TItem registro2;
    FLVazia(&lista2);
    int variavel1, variavel2, variavel3;
    int estado1, estado2, estado3;
    for (int i = 0; i < C; i++)
    {
        printf("Digite a cláusula: {(a,b),(c,d)(e,f)}\n Sendo, a/c/e numero da variável, e b/d/f o estado dela.\n");
        scanf("{(%d,%d),(%d,%d)(%d,%d)}", &variavel1, &estado1, &variavel1, &estado2, &variavel3, &estado3);
        if ((variavel1 = (int)variavel1) && (estado1 = (int)estado1) && (variavel2 = (int)variavel2) && (estado2 = (int)estado2) && (variavel3 = (int)variavel3) && (estado3 = (int)estado3))
        {
            registro2.posicao1 = variavel1;
            registro2.posicao2 = variavel2;
            registro2.posicao3 = variavel3;

            registro2.valor1 = estado1;
            registro2.valor2 = estado2;
            registro2.valor3 = estado3;

            Insere(registro2, &lista2);
            Imprime(lista2, N);
        }
        else
        {
            printf("Houve algum erro.");
        }
    }
}