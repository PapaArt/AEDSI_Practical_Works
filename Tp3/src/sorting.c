#include "sorting.h"

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int bubbleSort(int* arr, int n)
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

int selectionSort(int* arr, int n)
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

int shellSort(int* arr, int n)
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

int partition(int* arr, int low, int high)
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

int quickSort(int* arr, int low, int high)
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

void heapify(int* arr, int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = (2 * i) + 1; // left = 2*i+1
    int r = (2 * i) + 1; // right = 2*i+1

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

int heapSort(int* arr, int n)
{
    int i;

    // Build heap (rearrange array)
    for (i = (n/2) - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    // One by one extract an element from heap
    for (i = n-1; i > 0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

void  printArray(int* arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}