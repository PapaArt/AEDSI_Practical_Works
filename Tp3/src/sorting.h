#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifndef SORTING_H
#define SORTING_H
#include "cenarios.h"

void swap(long long int *xp, long long int *yp);
//As funcoes precisam ser int para retornar o contador
void bubbleSort(long long int *arr, int n, int flag, long long int *comparacoes, long long int *movimentacoes, double *tempo, int cenario, int *exec1);
void selectionSort(long long int *arr, int n, int flag, long long int *comparacoes, long long int *movimentacoes, double *tempo, int cenario, int *exec1);
void insertionSort(long long int *arr, int n, int flag, long long int *comparacoes, long long int *movimentacoes, double *tempo, int cenario, int *exec1);
void shellSort(long long int *arr, int n, int flag, long long int *comparacoes, long long int *movimentacoes, double *tempo, int cenario, int *exec1);
// int partition(long long int *arr, int low, int high, long long int *comparacoes, long long int *movimentacoes, int cenario);
// void quickSort(long long int *arr, int low, int high, int flag, long long int *comparacoes, long long int *movimentacoes, double *tempo, int cenario, int *exec1);
void particao(int left, int right, int *i, int *j, long long int *arr, long long int* comparacoes, long long int* movimentacoes, long long int mov, long long int comp, int cenario);
void ordena(int left, int right, long long int* arr, long long int* comparacoes, long long int* movimentacoes, long long int mov, long long int comp, int cenario);
void quickSort(long long int* arr, int n, int flag, long long int* comparacoes, long long int* movimentacoes, int cenario,double *tempo, int* exec1);
void merge(long long int *arr, int l, int m, int r, long long int comp, long long int mov, int flag, long long int *comparacoes, long long int *movimentacoes, int cenario, int *exec1);
void mergeSort(long long int *arr, int l, int r, int flag, long long int *comparacoes, long long int *movimentacoes, double *tempo, int cenario, int *exec1);
int getMax(long long int *arr, int n, long long int comp);
void countSort(long long int *arr, int n, int exp, int flag);
void radixSort(long long int *arr, int n, int flag, long long int *comparacoes, long long int *movimentacoes, double *tempo, int cenario, int *exec1);

// Funcao para imprimir um vetor de tamanho n
void printArray(long long int *arr, int n);

#endif
