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

void random_array(long long int *arr, int resposta)
{
    int i;
    for (i = 0; i < resposta; i++)
    {
        arr[i] = rand() % 101;
    }
    // for (i = 0; i < resposta; i++)
    // {
    //     printf("%lld ", arr[i]);
    // }printf("\n");
    
}

void random_id(Registro *item)
{
    srand(time(NULL));
    int a = 0;
    a = rand()%101;
    item->chave = a;
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
    srand((unsigned)time(NULL));
    for (int i = 0; i < 4; i++)
    {
        item->real_value[i] =(float) rand()/101;
    }
}

void geraReg(Registro* item){
    random_id(item);
    printf("id: %d\n", item->chave);
    random_char(item);
    random_realvalue(item);
}