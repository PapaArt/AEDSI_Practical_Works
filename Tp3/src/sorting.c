#include "sorting.h"

// contadores auxiliares para as funcoes recursivas
int quick_swap = 0;
int quick_comp = 0;

int count_swap = 0;

int radix_swap = 0;
int radix_comp = 0;
//Array contador vai ter duas casas, casa 0 e o numero de comparacoes, casa 1 e o numero de trocas;

void swap(long long int* xp, long long int* yp)
{
    long long int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(long long int* arr, int n, int flag)
{
    int i,j;
    double tempo;
    int bubble_comp = 0;
    int bubble_swap = 0;

    for (i = 0; i < n-1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
        {
            bubble_comp++;
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
                bubble_swap++;
            }
        }
    }
    if (flag)
    {
        arquivoX(bubble_comp, bubble_swap, tempo);
    }
}

void selectionSort(long long int* arr, int n,int flag)
{
    int i, j, min_index;
    double tempo;
    int selection_comp = 0;
    int selection_swap = 0;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i+1; j < n; j++)
        {
            selection_comp++;
            if(arr[j] < arr[min_index])
            {
                min_index = j;
                selection_swap++;
            }
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_index], &arr[i]);
        selection_swap++;
    }
    if (flag)
    {
        arquivoX(selection_comp, selection_swap, tempo);
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

void insertionSort(long long int* arr, int n,int flag)
{
    int i, j;
    int temp;
    double tempo;
    int insertion_comp = 0;
    int insertion_swap = 0;

    for (i = 1; i < n; i++)
    {
        j = i;
        insertion_comp++;
        while ((j > 0) && (arr[j - 1] > arr[j]))
        {
            if(arr[j-1]>arr[j])
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
if (flag)
    {
        arquivoX(insertion_comp, insertion_swap, tempo);
    }
}

void shellSort(long long int* arr, int n,int flag)
{
    int i, j, gap;
    int temp;
    double tempo;
    int shell_comp = 0;
    int shell_swap = 0;
    // Start with a big gap, then reduce the gap
    for (gap = n/2; gap > 0; gap /= 2)
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
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap)
            {
                arr[j] = arr[j-gap];
                shell_comp++;
                shell_swap++;
            }
            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
            shell_comp++;
        }
    }
    if (flag)
    {
        arquivoX(shell_comp, shell_swap, tempo);
    }
}

int partition(long long int* arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); //Index of smaller element and indicates the right position of pivot found so far
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
    swap(&arr[i+1], &arr[high]);
    quick_swap++;
    return (i+1);
}


void quickSort(long long int* arr, int low, int high,int flag)
{
    double tempo;
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1,0);
        quickSort(arr, pi + 1, high,0);
    }
    if (flag)
    {
        arquivoX(quick_comp, quick_swap, tempo);
    }
}

void merge(long long int* arr, int l, int m, int r,double *comp,double mov, int flag)
 {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    // cria vetores temporários /
    int L[1001], R[1001];

    // copia os dados para os vetores  L[] and R[] /
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    // Mesclar as matrizes temporárias novamente te[l..r]/
    i = 0; // index inicial do primeiro subvetor
    j = 0; // index inicial do segundo subvetor
    k = l; // index inicial do terceiro subvetor
    while (i < n1 && j < n2) {
        (comp)++;
        if (L[i]<= R[j]) {
            (mov)++;
            arr[k] = L[i];
            i++;
        }
        else{
            (mov)++;
            arr[k] = R[j];
            j++;
        }k++;
    }

    // Copia os elementos restantes de L [],se houver algum/
    while (i < n1) {
        (mov)++;
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R [],se houver algum/
    while (j < n2) {
        (mov)++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l é para o índice esquerdo e r é o índice direito do subvetor de te[] a ser classificado*/
void mergeSort(long long int* arr, int l, int r,int flag) {
    double comp=0,mov=0, tempo;
    if (l < r) {
        // Igual a (l + r) / 2, mas evita o excesso de
        // amplia l e h
        int m = l+(r-l)/2;

        // Classificar primeira e segunda metades
        mergeSort(arr, l, m,0);
        mergeSort(arr, m+1, r,0);

        merge(arr, l, m, r,&comp,mov,0);
    }
    if(flag){
        arquivoX(comp, mov, tempo);
    }
}


int getMax(long long int* arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        radix_comp++;
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

void countSort(long long int* arr, int n, int exp,int flag)
{
    int output[1001];
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[(arr[i]/exp)%10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i-1];

    // Build the output array
    for (i = n-1; i >= 0; i--)
    {
        output[count[(arr[i]/exp)%10] - 1] = arr[i];
        count[(arr[i]/exp)%10]--;
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
    if (flag)
    {
        printf("\nNao ha comparacoes no count sort \n");
        printf("Numero de trocas: %d \n",count_swap);
    }
}

void radixSort(long long int* arr, int n,int flag)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
    double tempo;
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // wgere i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
    {
        countSort(arr, n, exp,0);
        radix_swap = radix_swap + count_swap;
    }
    if (flag)
    {
        arquivoX(radix_comp, radix_swap, tempo);
    }
}

// Modificar essa funcao para gerar a saida em .txt
void  printArray(long long int* arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%lld ", arr[i]);
    printf("\n");
}
