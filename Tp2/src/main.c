#include "sat.h"
#include "menu.h"

int main()
{
    // double tempo;
    // clock_t fim,inicio;

    // long long int n = 1 << 4, i;
 
    // inicio=clock(); 
    // for(i = 0; i < n; i++)
    //     truthTable(i, 4);
    // fim=clock();
    // tempo=((double)(fim-inicio))/CLOCKS_PER_SEC; 
    // printf("Tempo Gasto = %lf segundos\n\n\n",tempo);
    TipoLista lista1;
    int mat[10][50];
    geraclauses(lista1, mat, 4);
    return 0;
}