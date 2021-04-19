#include "sat.h"

// Função reponsável por identificar qual o sistema operacional o usuário está utilizando, e adaptar o código para
// melhor utilização deste
void semPreconceito()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}

int truthTable(int n, int leng, TItem *pItem)
{
    long long int* coluna;
    coluna = (long long int*)malloc(sizeof(long long int)*leng);
    int pos = 0;
    int colum = 0;
    int i, j = 0, k = 0, z = 0;
    long long int bit = 1 << leng - 1;
    while (bit)
    {
        coluna[j] = n & bit ? 1 : 0;
        j++;
        bit >>= 1;
    }
    int jP = pItem->posicao1;
    int kP = pItem->posicao2;
    int lP = pItem->posicao3;
    int jV = pItem->valor1;
    int kV = pItem->valor2;
    int lV = pItem->valor3;

    int expressao = 1;
    int claus = 0;
    if (jV == 2 && coluna[jP] == 1)
    {
        claus = 1;
    }
    if (jV == 1 && coluna[jP] == 0)
    {
        claus = 1;
    }
    if (kV == 2 && coluna[kP] == 1)
    {
        claus = 1;
    }
    if (kV == 1 && coluna[kP] == 0)
    {
        claus = 1;
    }
    if (lV == 2 && coluna[lP] == 1)
    {
        claus = 1;
    }
    if (lV == 1 && coluna[lP] == 0)
    {
        claus = 1;
    }

    if (claus == 0)
    {
        expressao = 0;
    }

    if (expressao == 1)
    {
        for (int i = 0; i < leng; i++)
        {
            printf("%lld", coluna[i]);
        }
        printf("\n");
    }
    free(coluna);
}
