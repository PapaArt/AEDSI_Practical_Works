#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifndef SORTING_H
#define SORTING_H
#include "cenarios.h"

void swap(long long int* xp, long long int* yp);
//As funcoes precisam ser int para retornar o contador
void bubbleSort(long long int* arr, int n,int flag);
void selectionSort(long long int* arr, int n,int flag);
void insertionSort(long long int* arr, int n,int flag);
void shellSort(long long int* arr, int n,int flag);
int partition(long long int* arr, int low, int high);
void quickSort(long long int* arr, int low, int high,int flag);
void merge(long long int* arr, int l, int m, int r,int *comp,int mov,int flag);
void mergeSort(long long int* arr, int l, int r,int flag);
int getMax(long long int* arr, int n);
void countSort(long long int* arr, int n, int exp,int flag);
void radixSort(long long int* arr, int n,int flag);

// Funcao para imprimir um vetor de tamanho n
void printArray(long long int* arr, int n);

#endif
