#include "sorting.h"

// contadores auxiliares para as funcoes recursivas
int quick_swap = 0;
int quick_comp = 0;

int count_swap = 0;

int radix_swap = 0;
int radix_comp = 0;
clock_t inicio, fim;
//Array contador vai ter duas casas, casa 0 e o numero de comparacoes, casa 1 e o numero de trocas;

void swap(long long int *xp, long long int *yp)
{
    long long int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(long long int *arr, int n, int flag, int *comparacoes, int *movimentacoes, double* tempo, int cenario, int *exec1)
{
    inicio = clock();
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
    fim = clock();
    if (cenario == 1)
    {
        comparacoes[0] += bubble_comp;
        movimentacoes[0] += bubble_swap;
        tempo[0] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }
    else if (cenario == 2)
    {
        comparacoes[7] += bubble_comp;
        movimentacoes[7] += bubble_swap;
        tempo[7] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }

    if (flag && cenario == 1 && exec1[0] == 5)
    {
        comparacoes[0] = (comparacoes[0] / 5);
        movimentacoes[0] = (movimentacoes[0] / 5);
        arquivoX(comparacoes, movimentacoes, 1);
    }
    else if (flag && cenario == 2 && exec1[7] == 5)
    {
        comparacoes[7] = (comparacoes[7] / 5);
        movimentacoes[7] = (movimentacoes[7] / 5);
        arquivoX(comparacoes, movimentacoes, 8);
    }
    if (flag && cenario == 1 && exec1[0] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[0]));
    }
    else if (flag && cenario == 2 && exec1[7] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[7]));
    }
}

void selectionSort(long long int *arr, int n, int flag, int *comparacoes, int *movimentacoes, double* tempo, int cenario, int *exec1)
{
    inicio = clock();
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
    fim = clock();
    if (cenario == 1)
    {
        comparacoes[1] += selection_comp;
        movimentacoes[1] += selection_swap;
        tempo[1] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }
    else if (cenario == 2)
    {
        comparacoes[8] += selection_comp;
        movimentacoes[8] += selection_swap;
        tempo[8] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }

    if (flag && cenario == 1 && exec1[1] == 5)
    {
        comparacoes[1] = (comparacoes[1] / 5);
        movimentacoes[1] = (movimentacoes[1] / 5);
        arquivoX(comparacoes, movimentacoes, 2);
    }
    else if (flag && cenario == 2 && exec1[8] == 5)
    {
        comparacoes[8] = (comparacoes[8] / 5);
        movimentacoes[8] = (movimentacoes[8] / 5);
        arquivoX(comparacoes, movimentacoes, 9);
    }
    if (flag && cenario == 1 && exec1[1] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[1]));
    }
    else if (flag && cenario == 2 && exec1[8] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[8]));
    }
}

void insertionSort(long long int *arr, int n, int flag, int *comparacoes, int *movimentacoes, double* tempo, int cenario, int *exec1)
{
    inicio = clock();
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
    fim = clock();
    if (cenario == 1)
    {
        comparacoes[2] += insertion_comp;
        movimentacoes[2] += insertion_swap;
        tempo[2] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }
    else if (cenario == 2)
    {
        comparacoes[9] += insertion_comp;
        movimentacoes[9] += insertion_swap;
        tempo[9] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }

    if (flag && cenario == 1 && exec1[2] == 5)
    {
        comparacoes[2] = (comparacoes[2] / 5);
        movimentacoes[2] = (movimentacoes[2] / 5);
        arquivoX(comparacoes, movimentacoes, 3);
    }
    else if (flag && cenario == 2 && exec1[9] == 5)
    {
        comparacoes[9] = (comparacoes[9] / 5);
        movimentacoes[9] = (movimentacoes[9] / 5);
        arquivoX(comparacoes, movimentacoes, 10);
    }
    if (flag && cenario == 1 && exec1[2] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[2]));
    }
    else if (flag && cenario == 2 && exec1[9] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[9]));
    }
}

void shellSort(long long int *arr, int n, int flag, int *comparacoes, int *movimentacoes, double* tempo, int cenario, int *exec1)
{
    inicio = clock();
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
    fim = clock();
    if (cenario == 1)
    {
        comparacoes[3] += shell_comp;
        movimentacoes[3] += shell_swap;
        tempo[3] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }
    else if (cenario == 2)
    {
        comparacoes[10] += shell_comp;
        movimentacoes[10] += shell_swap;
        tempo[10] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }

    if (flag && cenario == 1 && exec1[3] == 5)
    {
        comparacoes[3] = (comparacoes[3] / 5);
        movimentacoes[3] = (movimentacoes[3] / 5);
        arquivoX(comparacoes, movimentacoes, 4);
    }
    else if (flag && cenario == 2 && exec1[10] == 5)
    {
        comparacoes[10] = (comparacoes[10] / 5);
        movimentacoes[10] = (movimentacoes[10] / 5);
        arquivoX(comparacoes, movimentacoes, 11);
    }
    if (flag && cenario == 1 && exec1[3] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[3]));
    }
    else if (flag && cenario == 2 && exec1[10] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[10]));
    }
}

int partition(long long int *arr, int low, int high, int *comparacoes, int *movimentacoes, int cenario)
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
    return (i + 1);
}

void quickSort(long long int *arr, int low, int high, int flag, int *comparacoes, int *movimentacoes, double* tempo, int cenario, int *exec1)
{
    inicio = clock();
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high, comparacoes, movimentacoes, cenario);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1, 0, comparacoes, movimentacoes, tempo, cenario,exec1);
        quickSort(arr, pi + 1, high, 0, comparacoes, movimentacoes, tempo, cenario,exec1);
    }
    fim = clock();
    if (cenario == 1)
    {
        comparacoes[4] += quick_comp;
        movimentacoes[4] += quick_swap;
        tempo[4] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }else if (cenario == 2){
        comparacoes[11] += quick_comp;
        movimentacoes[11] += quick_swap;
        tempo[11] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }

    if (flag && cenario == 1 && exec1[4] == 5)
    {
        comparacoes[4] = (comparacoes[4] / 5);
        movimentacoes[4] = (movimentacoes[4] / 5);
        arquivoX(comparacoes, movimentacoes, 5);
    }
    else if (flag && cenario == 2 && exec1[11] == 5)
    {
        comparacoes[11] = (comparacoes[11] / 5);
        movimentacoes[11] = (movimentacoes[11] / 5);
        arquivoX(comparacoes, movimentacoes, 12);
    }
    if (flag && cenario == 1 && exec1[4] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[4]));
    }
    else if (flag && cenario == 2 && exec1[11] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[11]));
    }
}

void merge(long long int *arr, int l, int m, int r, int comp, int mov, int flag, int *comparacoes, int *movimentacoes, int cenario, int *exec1)
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
            (comp)++;
            (mov)++;
            arr[k] = L[i];
            i++;
        }
        else
        {
            (comp)++;
            (mov)++;
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L [],se houver algum/
    while (i < n1)
    {
        (comp)++;
        (mov)++;
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R [],se houver algum/
    while (j < n2)
    {
        (comp)++;
        (mov)++;
        arr[k] = R[j];
        j++;
        k++;
    }
    if (cenario == 1)
    {
        comparacoes[5] += (comp);
        movimentacoes[5] += mov;
    }
    else if (cenario == 2)
    {
        comparacoes[12] += (comp);
        movimentacoes[12] += mov;
    }
}

/* l é para o índice esquerdo e r é o índice direito do subvetor de te[] a ser classificado*/
void mergeSort(long long int *arr, int l, int r, int flag, int *comparacoes, int *movimentacoes, double* tempo, int cenario, int *exec1)
{
    inicio = clock();
    int comp = 0, mov = 0;
    if (l < r)
    {
        // Igual a (l + r) / 2, mas evita o excesso de
        // amplia l e h
        int m = l + (r - l) / 2;

        // Classificar primeira e segunda metades
        mergeSort(arr, l, m, 0, comparacoes, movimentacoes, tempo, cenario,exec1);
        mergeSort(arr, m + 1, r, 0, comparacoes, movimentacoes, tempo, cenario, exec1);

        merge(arr, l, m, r, comp, mov, 0, comparacoes, movimentacoes, cenario,exec1);
    }
    fim = clock();

    if (flag && cenario == 1 && exec1[5] == 5)
    {
        comparacoes[5] = (comparacoes[5] / 5);
        movimentacoes[5] = (movimentacoes[5] / 5);
        tempo[5] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
        arquivoX(comparacoes, movimentacoes, 6);
    }
    else if (flag && cenario == 2 && exec1[12] == 5)
    {
        comparacoes[12] = (comparacoes[12] / 5);
        movimentacoes[12] = (movimentacoes[12] / 5);
        tempo[12] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
        arquivoX(comparacoes, movimentacoes, 13);
    }
    if (flag && cenario == 1 && exec1[5] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[5]));
    }
    else if (flag && cenario == 2 && exec1[12] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[12]));
    }
}

int getMax(long long int *arr, int n)
{
    long long int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        radix_comp++;
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

void countSort(long long int *arr, int n, int exp, int flag)
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

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(long long int *arr, int n, int flag, int *comparacoes, int *movimentacoes, double* tempo, int cenario, int *exec1)
{
    inicio = clock();
    // Find the maximum number to know number of digits
    long long int m = getMax(arr, n);
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // wgere i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp, 1);
        radix_swap = radix_swap + count_swap;
    }
    fim = clock();

    if (cenario == 1)
    {
        comparacoes[6] += radix_comp;
        movimentacoes[6] += radix_swap;
        tempo[6] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }
    else if (cenario == 2)
    {
        comparacoes[13] += radix_comp;
        movimentacoes[13] += radix_swap;
        tempo[13] += ((double)(fim-inicio))/CLOCKS_PER_SEC;
    }

    if (flag && cenario == 1 && exec1[6] == 5)
    {
        comparacoes[6] = (comparacoes[6] / 5);
        movimentacoes[6] = (movimentacoes[6] / 5);
        arquivoX(comparacoes, movimentacoes, 7);
    }
    else if (flag && cenario == 2 && exec1[13] == 5)
    {
        comparacoes[13] = (comparacoes[13] / 5);
        movimentacoes[13] = (movimentacoes[13] / 5);
        arquivoX(comparacoes, movimentacoes, 14);
    }
    if (flag && cenario == 1 && exec1[6] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[6]));
    }
    else if (flag && cenario == 2 && exec1[13] < 5)
    {
        printf("Execute o algoritmo mais %d vezes para obter o arquivo de medias!\n", (5 - exec1[13]));
    }
}

// Modificar essa funcao para gerar a saida em .txt
void printArray(long long int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%lld ", arr[i]);
    printf("\n");
}