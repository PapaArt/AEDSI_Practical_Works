#include "sorting.h"
// Arquivo feito para testar os algoritmos de ordenacao
int main()
{
    int i, j, n = 500;
    int arr[n];
    srand(time(0));
    for (i = 0; i < n; i++)
    {
        arr[i] = rand()%101;
    }

    printf("Given an random array: \n");
    printArray(arr, n);
    // Mudar a funcao abaixo para o algoritmo de ordenacao que deseja ser testado
    mergeSort(arr, 0, n - 1, 1);
    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}