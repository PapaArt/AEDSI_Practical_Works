#include "sorting.h"

// contadores auxiliares para as funcoes recursivas
int quick_swap = 0;
int quick_comp = 0;

int count_swap = 0;

int radix_swap = 0;
int radix_comp = 0;
//Array contador vai ter duas casas, casa 0 e o numero de comparacoes, casa 1 e o numero de trocas;

void swap(long long int *xp, long long int *yp)
{
    long long int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(long long int *arr, int n, int flag, int comparacoes[14], int movimentacoes[14], int cenario)
{
    int i, j;
    int bubble_comp = 0;
    int bubble_swap = 0;

    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            bubble_comp++;
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                bubble_swap++;
            }
        }
    }
    if (flag && cenario == 1)
    {
        comparacoes[0] = bubble_comp;
        movimentacoes[0] = bubble_swap;
        printf("comp: %d", comparacoes[0]);
        printf("mov: %d", movimentacoes[0]);
        arquivoX(comparacoes[14], movimentacoes[14], 1);
    }
    else if (flag && cenario == 2)
    {
        comparacoes[7] = bubble_comp;
        movimentacoes[7] = bubble_swap;
        printf("comp: %d", comparacoes[7]);
        printf("mov: %d", movimentacoes[7]);
    }
}

void selectionSort(long long int *arr, int n, int flag, int comparacoes[14], int movimentacoes[14], int cenario)
{
    int i, j, min_index;
    int selection_comp = 0;
    int selection_swap = 0;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i + 1; j < n; j++)
        {
            selection_comp++;
            if (arr[j] < arr[min_index])
            {
                min_index = j;
                selection_swap++;
            }
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_index], &arr[i]);
        selection_swap++;
    }
    if (cenario == 1)
    {
        comparacoes[1] = selection_comp;
        movimentacoes[1] = selection_swap;
        printf("comp: %d", comparacoes[1]);
        printf("mov: %d", movimentacoes[1]);
    }
    if (cenario == 2)
    {
        comparacoes[8] = selection_comp;
        movimentacoes[8] = selection_swap;
        printf("comp: %d", comparacoes[8]);
        printf("mov: %d", movimentacoes[8]);
    }
    if (flag)
    {
        arquivoX(selection_comp, selection_swap, 2);
    }
}

/*
int * insertionSort(long long int* arr, int n)
{
    int i, key, j;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0...i-1], that are
        //    greater than key, to one position ahead
        //    of their current position

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}
*/

void insertionSort(long long int *arr, int n, int flag, int comparacoes[14], int movimentacoes[14], int cenario)
{
    int i, j;
    int temp;
    int insertion_comp = 0;
    int insertion_swap = 0;

    for (i = 1; i < n; i++)
    {
        j = i;
        insertion_comp++;
        while ((j > 0) && (arr[j - 1] > arr[j]))
        {
            if (arr[j - 1] > arr[j])
            {
                insertion_comp++;
            }
            temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
            insertion_swap++;
        }
    }
    if (cenario == 1)
    {
        comparacoes[2] = insertion_comp;
        movimentacoes[2] = insertion_swap;
        printf("comp: %d", comparacoes[2]);
        printf("mov: %d", movimentacoes[2]);
    }
    if (cenario == 2)
    {
        comparacoes[9] = insertion_comp;
        movimentacoes[9] = insertion_swap;
        printf("comp: %d", comparacoes[9]);
        printf("mov: %d", movimentacoes[9]);
    }
    if (flag)
    {
        arquivoX(insertion_comp, insertion_swap, 3);
    }
}

void shellSort(long long int *arr, int n, int flag, int comparacoes[14], int movimentacoes[14], int cenario)
{
    int i, j, gap;
    int temp;
    int shell_comp = 0;
    int shell_swap = 0;
    // Start with a big gap, then reduce the gap
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (i = gap; i < n; i++)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            temp = arr[i];
            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
                shell_comp++;
                shell_swap++;
            }
            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
            shell_comp++;
        }
    }
    if (cenario == 1)
    {
        comparacoes[3] = shell_comp;
        movimentacoes[3] = shell_swap;
        printf("comp: %d", comparacoes[3]);
        printf("mov: %d", movimentacoes[3]);
    }
    if (cenario == 2)
    {
        comparacoes[10] = shell_comp;
        movimentacoes[10] = shell_swap;
        printf("comp: %d", comparacoes[10]);
        printf("mov: %d", movimentacoes[10]);
    }
    if (flag)
    {
        arquivoX(shell_comp, shell_swap, 4);
    }
}

int partition(long long int *arr, int low, int high, int comparacoes[14], int movimentacoes[14], int cenario)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1);     //Index of smaller element and indicates the right position of pivot found so far
    int j;

    for (j = low; j <= high - 1; j++)
    {
        quick_comp++;
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
            quick_swap++;
        }
    }
    swap(&arr[i + 1], &arr[high]);
    quick_swap++;
    if (cenario == 1)
    {
        comparacoes[4] = quick_comp;
        movimentacoes[4] = quick_swap;
        printf("comp: %d", comparacoes[4]);
        printf("mov: %d", movimentacoes[4]);
    }
    if (cenario == 2)
    {
        comparacoes[11] = quick_comp;
        movimentacoes[11] = quick_swap;
        printf("comp: %d", comparacoes[11]);
        printf("mov: %d", movimentacoes[11]);
    }
    return (i + 1);
}

void quickSort(long long int *arr, int low, int high, int flag, int comparacoes[14], int movimentacoes[14], int cenario)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high, comparacoes, movimentacoes, cenario);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1, 0, comparacoes, movimentacoes, cenario);
        quickSort(arr, pi + 1, high, 0, comparacoes, movimentacoes, cenario);
    }
    if (flag)
    {
        arquivoX(quick_comp, quick_swap, 5);
    }
}

void merge(long long int *arr, int l, int m, int r, double *comp, double mov, int flag, int comparacoes[14], int movimentacoes[14], int cenario)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // cria vetores temporários /
    int *L;
    L = (int *)malloc(sizeof(long long int) * n1);
    int *R;
    R = (int *)malloc(sizeof(long long int) * n2);

    // copia os dados para os vetores  L[] and R[] /
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mesclar as matrizes temporárias novamente te[l..r]/
    i = 0; // index inicial do primeiro subvetor
    j = 0; // index inicial do segundo subvetor
    k = l; // index inicial do terceiro subvetor
    while (i < n1 && j < n2)
    {
        (comp)++;
        if (L[i] <= R[j])
        {
            (mov)++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            (mov)++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L [],se houver algum/
    while (i < n1)
    {
        (mov)++;
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R [],se houver algum/
    while (j < n2)
    {
        (mov)++;
        arr[k] = R[j];
        j++;
        k++;
    }
    if (cenario == 1)
    {
        comparacoes[5] = comp;
        movimentacoes[5] = mov;
        printf("comp: %d", comparacoes[5]);
        printf("mov: %d", movimentacoes[5]);
    }
    if (cenario == 2)
    {
        comparacoes[12] = comp;
        movimentacoes[12] = mov;
        printf("comp: %d", comparacoes[12]);
        printf("mov: %d", movimentacoes[12]);
    }
}

/* l é para o índice esquerdo e r é o índice direito do subvetor de te[] a ser classificado*/
void mergeSort(long long int *arr, int l, int r, int flag, int comparacoes[14], int movimentacoes[14], int cenario)
{
    double comp = 0, mov = 0;
    if (l < r)
    {
        // Igual a (l + r) / 2, mas evita o excesso de
        // amplia l e h
        int m = l + (r - l) / 2;

        // Classificar primeira e segunda metades
        if (cenario == 1)
        {
            mergeSort(arr, l, m, 0, comparacoes[5], movimentacoes[5], cenario);
            mergeSort(arr, m + 1, r, 0, comparacoes[5], movimentacoes[5], cenario);
        }
        if (cenario == 2)
        {
            mergeSort(arr, l, m, 0, comparacoes[12], movimentacoes[12], cenario);
            mergeSort(arr, m + 1, r, 0, comparacoes[12], movimentacoes[12], cenario);
        }
        if (cenario == 1)
        {
            merge(arr, l, m, r, &comp, mov, 0, comparacoes[5], movimentacoes[5], cenario);
        }
        if (cenario == 2)
        {
            merge(arr, l, m, r, &comp, mov, 0, comparacoes[12], movimentacoes[12], cenario);
        }
    }
    if (flag)
    {
        arquivoX(comparacoes[14], movimentacoes[14], 6);
    }
}

int getMax(long long int *arr, int n, int comparacoes[14], int cenario)
{
    long long int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        radix_comp++;
        if (arr[i] > mx)
            mx = arr[i];
    }
    if (cenario == 1)
    {
        comparacoes[6] = radix_comp;
        printf("comp: %d", comparacoes[6]);
    }
    if (cenario == 2)
    {
        comparacoes[13] = radix_comp;
        printf("comp: %d", comparacoes[13]);
    }
    return mx;
}

void countSort(long long int *arr, int n, int exp, int flag, int movimentacoes[14], int cenario)
{
    int *output;
    output = (int *)malloc(sizeof(long long int) * n);
    int i, count[10] = {0};
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    //Contando o numero de movimentacoes
    for (i = 0; i < n; i++)
    {
        if (arr[i] != output[i])
        {
            count_swap++;
        }
    }
    if (cenario == 1)
    {
        movimentacoes[6] = count_swap;
        printf("mov: %d", movimentacoes[6]);
    }
    if (cenario == 2)
    {
        movimentacoes[13] = count_swap;
        printf("mov: %d", movimentacoes[13]);
    }
    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(long long int *arr, int n, int flag, int comparacoes[14], int movimentacoes[14], int cenario)
{
    // Find the maximum number to know number of digits
    long long int m;
    if (cenario == 1)
    {
        long long int m = getMax(arr, n, comparacoes[6], cenario);
    }
    if (cenario == 2)
    {
        long long int m = getMax(arr, n, comparacoes[13], cenario);
    }
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // wgere i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        if (cenario == 1)
        {
            countSort(arr, n, exp, 1, movimentacoes[6], cenario);
            radix_swap = radix_swap + count_swap;
        }
        if (cenario == 2)
        {
            countSort(arr, n, exp, 1, movimentacoes[13], cenario);
            radix_swap = radix_swap + count_swap;
        }
    }
    if (flag)
    {
        arquivoX(radix_comp, radix_swap, 7);
    }
}

// Modificar essa funcao para gerar a saida em .txt
void printArray(long long int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%lld ", arr[i]);
    printf("\n");
}
