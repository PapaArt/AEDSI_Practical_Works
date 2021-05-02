#include "sorting.h"

void swap(long long int* xp, long long int* yp)
{
    long long int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int bubbleSort(long long int* arr, int n)
{
    int i,j;
    for (i = 0; i < n-1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int selectionSort(long long int* arr, int n)
{
    int i, j, min_index;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_index = i;
        for (j = i+1; j < n; j++)
        {
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        // Swap the found minimum element with the first element
        swap(&arr[min_index], &arr[i]);
    }
}

int insertionSort(long long int* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0...i-1], that are
            greater than key, to one position ahead
            of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int shellSort(long long int* arr, int n)
{
    int i, j, gap;
    int temp;

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
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap)
            {
                arr[j] = arr[j-gap];
            }
            // put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }     
    }
    return 0;
}

int partition(long long int* arr, int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); //Index of smaller element and indicates the right position of pivot found so far
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);    
}

int quickSort(long long int* arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(long long int* arr, int l, int m, int r,double *comp,double mov,int flag) { 
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
    double comp=0,mov=0;
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
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);
    }

}

int getMax(long long int* arr, int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > mx)
            mx = arr[i];
    }
    return mx;
}

void countSort(long long int* arr, int n, int exp)
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
    
    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

int radixSort(long long int* arr, int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // wgere i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// Modificar essa funcao para gerar a saida em .txt
void  printArray(long long int* arr, int n)
{
    FILE* pFile;
    pFile = fopen("../out/Cenario1.txt", "w+");
    for (int i = 0; i < n; i++)
        fprintf(pFile, "%lld ", arr[i]);
    fputs("\n", pFile);
    fclose(pFile);
    printf("Arquivo gerado com sucesso!!!\n");
}