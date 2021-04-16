#include "sat.h"

void semPreconceito()
{
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#endif
}

void truthTable(int n, int leng, TItem* pItem)
{
    int coluna[40];
    int j = 0, k = 0, z = 0;
    long long int bit = 1 << leng - 1;
    while (bit)
    {
        coluna[j] = n & bit ? 1 : 0;
        j++;
        bit >>= 1;
    }
    j = pItem->posicao1;
    if (pItem->valor1 == 1)
    {

    }
    
    printf("\n");
}

// int verifica(TFila* pFila)
// {
// 	Apontador iter;
// 	int flag;

// 	iter = pFila->pFrente;
// 	flag = 0;

// 	while (iter != pFila->pTras)
// 	{
// 		if (iter->item.valor == 2)
// 		{
// 			flag = 1;
// 		}		
// 		iter = iter->pProx;	
// 	}
// 	return flag;
// }


