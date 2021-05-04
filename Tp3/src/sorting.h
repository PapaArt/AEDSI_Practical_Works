#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifndef SORTING_H
#define SORTING_H
#include "cenarios.h"

void swap(long long int* xp, long long int* yp);
//As funcoes precisam ser int para retornar o contador
int* bubbleSort(long long int* arr, int n);
int* selectionSort(long long int* arr, int n);
int* insertionSort(long long int* arr, int n);
int* shellSort(long long int* arr, int n);
int partition(long long int* arr, int low, int high);
int quickSort(long long int* arr, int low, int high);
void merge(long long int* arr, int l, int m, int r,double *comp,double mov,int flag);
void mergeSort(long long int* arr, int l, int r,int flag);
int getMax(long long int* arr, int n);
void countSort(long long int* arr, int n, int exp);
int radixSort(long long int* arr, int n);

// Funcao para imprimir um vetor de tamanho n
void printArray(long long int* arr, int n);

#endif