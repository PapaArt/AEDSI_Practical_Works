#include "sat.h"

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
    int coluna[40];
    int pos = 0;
    int colum = 0;
    int i,j = 0, k = 0, z = 0;
    long long int bit = 1 << leng - 1;
    while (bit)
    {
        coluna[j] = n & bit ? 1 : 0;
        j++;
        bit >>= 1;
    }
    int jP = (n - 1) - (pItem->posicao1);
    int kP = pItem->posicao2;
    int lP = pItem->posicao3;
    int jV = pItem->valor1;
    int kV = pItem->valor2;
    int lV = pItem->valor3;

    pos = pItem->posicao3;
    colum = (leng - 1) - pos;

    
    
    
    
       
}