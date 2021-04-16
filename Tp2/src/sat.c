#include "sat.h"

void semPreconceito()
{
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#endif
}

void truthTable(int n, int leng,int posicao1, int posicao2, int posicao3)
{
    int coluna[1001];
    int j=0;
    long long int bit = 1 << leng - 1;
    while (bit)
    {
        printf("%d", n & bit ? 1 : 0);
        coluna[j] = bit;
        j++;
        bit >>= 1;
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


