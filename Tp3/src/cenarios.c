#include "cenarios.h"
#include "time.h"

void FLVazia(TipoLista *item)
{
    item->pPrimeiro = (Apontador)malloc(sizeof(TipoCelula));
    item->pUltimo = item->pPrimeiro;
    item->pPrimeiro->pProx = NULL;
}

void Insere(Registro* x, TipoLista *item)
{
    item->pUltimo->pProx = (Apontador)malloc(sizeof(TipoCelula));
    item->pUltimo = item->pUltimo->pProx;
    item->pUltimo->registro = *x;
    item->pUltimo->pProx = NULL;
}

void Imprime(TipoLista item){ 
    Apontador Aux;
    Aux = item.pPrimeiro->pProx;
    while (Aux != NULL) { 
        printf("%d ", Aux->registro.chave);
        Aux = Aux->pProx;
    }printf("\n");
}

void random_array(long long int *arr, int resposta)
{
    int i;
    for (i = 0; i < resposta; i++)
    {
        arr[i] = rand() % 101;
    }
}

void random_char(Registro *item)
{
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 200; j++)
        {
            item->string[i][j] = 'a' + (char)(rand() % 26);
            printf("%c", item->string[i][j]);
        }
    }printf("\n");
}

void random_realvalue(Registro *item)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 4; i++)
    {
        item->real_value[i] =(float) rand()/101;
    }
}

void geraReg(Registro* item){
    // random_id(item);
    // printf("id: %d\n", item->chave);
    // random_char(item);
    // random_realvalue(item);
    item->chave = rand()%101;
    printf("id: %d\n", item->chave);
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 200; j++)
        {
            item->string[i][j] = 'a' + (char)(rand() % 26);
            printf("%c", item->string[i][j]);
        }
    }printf("\n");

    for (int i = 0; i < 4; i++)
    {
        item->real_value[i] =(float) rand()/101;
        printf("real value: %f\n", item->real_value[i]);
    }
}

// Funcao para coletar os dados
void arquivoX(int* contador, double tempo)
{
    FILE* pFile;
    pFile = fopen("../out/Cenario1.txt", "w+");
    fprintf(pFile, "Numero de comparacoes: %d\nNumero de movimentacoes: %d\nTempo de execucao: %lf\n", contador[0], contador[1], tempo);
    fclose(pFile);
}