#include "cenarios.h"
#include "time.h"

void FLVazia(TipoLista *item)
{
    item->pPrimeiro = (Apontador)malloc(sizeof(TipoCelula));
    item->pUltimo = item->pPrimeiro;
    item->pPrimeiro->pProx = NULL;
}

void Insere(Registro *x, TipoLista *item)
{
    item->pUltimo->pProx = (Apontador)malloc(sizeof(TipoCelula));
    item->pUltimo = item->pUltimo->pProx;
    item->pUltimo->registro = *x;
    item->pUltimo->pProx = NULL;
}

void Imprime(TipoLista item)
{
    Apontador Aux;
    Aux = item.pPrimeiro->pProx;
    while (Aux != NULL)
    {
        printf("%d ", Aux->registro.chave);
        Aux = Aux->pProx;
    }
    printf("\n");
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
    }
    printf("\n");
}

void random_realvalue(Registro *item)
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 4; i++)
    {
        item->real_value[i] = (float)rand() / 101;
    }
}

int geraReg(Registro *item, long long int *arr, int pos)
{
    item->chave = rand() % 10001;
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
    } //printf("\n");

    for (int i = 0; i < 4; i++)
    {
        item->real_value[i] = (float)rand() / 10001;
        //printf("real value: %f\n", item->real_value[i]);
    }
}

// Funcao para coletar os dados
void arquivoX(int *comparacoes, int *movimentacoes, double* tempo, int valor)
{
    FILE *pFile;
    switch (valor)
    {
    case 1:
        pFile = fopen("../out/BubbleSort_Cenario1.txt", "w+");
        fprintf(pFile, "Bubble Sort -> Cenario 1\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[0], movimentacoes[0], tempo[0]);
        fclose(pFile);
        break;
    case 2:
        pFile = fopen("../out/SelectionSort_Cenario1.txt", "w+");
        fprintf(pFile, "Selection Sort -> Cenario 1\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[1], movimentacoes[1], tempo[1]);
        fclose(pFile);
        break;
    case 3:
        pFile = fopen("../out/InsertionSort_Cenario1.txt", "w+");
        fprintf(pFile, "Insertion Sort -> Cenario 1\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[2], movimentacoes[2], tempo[2]);
        fclose(pFile);
        break;
    case 4:
        pFile = fopen("../out/ShellSort_Cenario1.txt", "w+");
        fprintf(pFile, "Shell Sort -> Cenario 1\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[3], movimentacoes[3], tempo[3]);
        fclose(pFile);
        break;
    case 5:
        pFile = fopen("../out/QuickSort_Cenario1.txt", "w+");
        fprintf(pFile, "Quick Sort -> Cenario 1\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[4], movimentacoes[4], tempo[4]);
        fclose(pFile);
        break;
    case 6:
        pFile = fopen("../out/MergeSort_Cenario1.txt", "w+");
        fprintf(pFile, "Merge Sort -> Cenario 1\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[5], movimentacoes[5], tempo[5]);
        fclose(pFile);
        break;
    case 7:
        pFile = fopen("../out/RadixSort_Cenario1.txt", "w+");
        fprintf(pFile, "Radix Sort -> Cenario 1\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[6], movimentacoes[6], tempo[6]);
        fclose(pFile);
        break;
    case 8:
        pFile = fopen("../out/BubbleSort_Cenario2.txt", "w+");
        fprintf(pFile, "Bubble Sort -> Cenario 2\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[7], movimentacoes[7], tempo[7]);
        fclose(pFile);
        break;
    case 9:
        pFile = fopen("../out/SelectionSort_Cenario2.txt", "w+");
        fprintf(pFile, "Selection Sort -> Cenario 2\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[8], movimentacoes[8], tempo[8]);
        fclose(pFile);
        break;
    case 10:
        pFile = fopen("../out/InsertionSort_Cenario2.txt", "w+");
        fprintf(pFile, "Insertion Sort -> Cenario 2\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[9], movimentacoes[9], tempo[9]);
        fclose(pFile);
        break;
    case 11:
        pFile = fopen("../out/ShellSort_Cenario2.txt", "w+");
        fprintf(pFile, "Shell Sort -> Cenario 2\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[10], movimentacoes[10], tempo[10]);
        fclose(pFile);
        break;
    case 12:
        pFile = fopen("../out/QuickSort_Cenario2.txt", "w+");
        fprintf(pFile, "Quick Sort -> Cenario 2\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[11], movimentacoes[11], tempo[11]);
        fclose(pFile);
        break;
    case 13:
        pFile = fopen("../out/MergeSort_Cenario2.txt", "w+");
        fprintf(pFile, "Merge Sort -> Cenario 2\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[12], movimentacoes[12], tempo[12]);
        fclose(pFile);
        break;
    case 14:
        pFile = fopen("../out/RadixSort_Cenario2.txt", "w+");
        fprintf(pFile, "Radix Sort -> Cenario 2\n");
        fprintf(pFile, "Media das comparacoes: %d\nMedia das movimentacoes: %d\nMedia do tempo: %lf segundos\n", comparacoes[13], movimentacoes[13], tempo[13]);
        fclose(pFile);
        break;
    }
}