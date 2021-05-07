#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifndef SORTING_H
#define SORTING_H
#include "cenarios.h"

void swap(long long int* xp, long long int* yp);
//As funcoes precisam ser int para retornar o contador
void bubbleSort(long long int* arr, int n,int flag,int comparacoes[14],int movimentacoes[14],int cenario);
void selectionSort(long long int* arr, int n,int flag,int comparacoes[14],int movimentacoes[14],int cenario);
void insertionSort(long long int* arr, int n,int flag,int comparacoes[14],int movimentacoes[14],int cenario);
void shellSort(long long int* arr, int n,int flag,int comparacoes[14],int movimentacoes[14],int cenario);
int partition(long long int* arr, int low, int high,int comparacoes[14],int movimentacoes[14],int cenario);
void quickSort(long long int* arr, int low, int high,int flag,int comparacoes[14],int movimentacoes[14],int cenario);
void merge(long long int* arr, int l, int m, int r,double *comp,double mov,int flag,int comparacoes[14],int movimentacoes[14],int cenario);
void mergeSort(long long int* arr, int l, int r,int flag,int comparacoes[14],int movimentacoes[14],int cenario);
int getMax(long long int* arr, int n,int comparacoes[14],int cenario);
void countSort(long long int* arr, int n, int exp,int flag,int movimentacoes[14],int cenario);
void radixSort(long long int* arr, int n,int flag,int comparacoes[14],int movimentacoes[14],int cenario);

// Funcao para imprimir um vetor de tamanho n
void printArray(long long int* arr, int n);

#endif
