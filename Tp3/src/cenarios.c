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

int geraReg(Registro* item, long long int* arr, int pos){
    item->chave = rand()%10001;
    arr[pos] = item->chave;
    //printf("id: %d\n", item->chave);
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 200; j++)
        {
            item->string[i][j] = 'a' + (char)(rand() % 26);
            //printf("%c", item->string[i][j]);
        }
    }//printf("\n");

    for (int i = 0; i < 4; i++)
    {
        item->real_value[i] =(float) rand()/10001;
        //printf("real value: %f\n", item->real_value[i]);
    }
}

// Funcao para coletar os dados
void arquivoX(int comparacoes, int movimentacoes, int valor)
{
    FILE* pFile;
    switch (valor)
    {
    case 1:
        pFile = fopen("../out/Cenario1.txt", "w+");
        fprintf(pFile, "Bubble Sort -> Cenario 1\n");
        fprintf(pFile, "Numero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes, movimentacoes);
        fclose(pFile);
        break;
    case 2:
        pFile = fopen("../out/Cenario1.txt", "w+");
        fprintf(pFile, "Selection Sort -> Cenario 1\n");
        fprintf(pFile, "Numero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes, movimentacoes);
        fclose(pFile);
        break;
    case 3:
        pFile = fopen("../out/Cenario1.txt", "w+");
        fprintf(pFile, "Insertion Sort -> Cenario 1\n");
        fprintf(pFile, "Numero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes, movimentacoes);
        fclose(pFile);
        break;
    case 4:
        pFile = fopen("../out/Cenario1.txt", "w+");
        fprintf(pFile, "Shell Sort -> Cenario 1\n");
        fprintf(pFile, "Numero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes, movimentacoes);
        fclose(pFile);
        break;
    case 5:
        pFile = fopen("../out/Cenario1.txt", "w+");
        fprintf(pFile, "Quick Sort -> Cenario 1\n");
        fprintf(pFile, "Numero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes, movimentacoes);
        fclose(pFile);
        break;
    case 6:
        pFile = fopen("../out/Cenario1.txt", "w+");
        fprintf(pFile, "Merge Sort -> Cenario 1\n");
        fprintf(pFile, "Numero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes, movimentacoes);
        fclose(pFile);
        break;
    case 7:
        pFile = fopen("../out/Cenario1.txt", "w+");
        fprintf(pFile, "Radix Sort -> Cenario 1\n");
        fprintf(pFile, "Numero de comparacoes: %d\nNumero de movimentacoes: %d\n", comparacoes, movimentacoes);
        fclose(pFile);
        break;
    default:
        break;
    }
}