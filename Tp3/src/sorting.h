#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#ifndef SORTING_H
#define SORTING_H

void swap(int* xp, int* yp);
//As funcoes precisam ser int para retornar o contador
int bubbleSort(int* arr, int n);
int selectionSort(int* arr, int n);
int shellSort(int* arr, int n);
int partition(int* arr, int low, int high);
int quickSort(int* arr, int low, int high);
void merge(int* arr, int l, int m, int r);
int mergeSort(int* arr, int l, int r);
int getMax(int* arr, int n);
void countSort(int* arr, int n, int exp);
int radixSort(int* arr, int n);

// Funcao para imprimir um vetor de tamanho n
void printArray(int* arr, int n);

#endif