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

void geraclauses(TFila* pFila, int C, int N)
{
	int col1, col2, col3, pos1, pos2, pos3;
	int i,j;

	FFVazia(pFila);

	
}

void percorre(TItem* pItem)
{

}
