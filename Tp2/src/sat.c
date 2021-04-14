#include "sat.h"

void semPreconceito()
{
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#endif
}

void truthTable(int n, int leng)
{
	TItem pItem;
    pItem.linha = 1 << leng - 1;
    while (pItem.linha)
    {
        printf("%d", n & pItem.linha ? 1 : 0);
        pItem.linha >>= 1;
    }
    printf("\n");
}

int verifica(TFila* pFila)
{
	Apontador iter;
	int flag;

	iter = pFila->pFrente;
	flag = 0;

	while (iter != pFila->pTras)
	{
		if (iter->item.valor == 2)
		 		{
					flag = 1;
				}		
		iter = iter->pProx;	
	}
	return flag;
}

void percorre(TItem* pItem)
{

}
