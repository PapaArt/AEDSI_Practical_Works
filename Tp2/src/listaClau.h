#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifndef LISTACLAU_H
#define LISTACLAU_H
#include "sat.h"

typedef struct TItem
{
    int posicao1;
    int posicao2;
    int posicao3;
    int valor1;
    int valor2;
    int valor3;
}TItem; 
// Item da lista, por exemplo: o item m[i][j] da matriz. Ou seja, deve conter o conteúdo.
// No exemplo acima (mat[i][j]) o conteúdo seria : linha, coluna e o valor da posição.


typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula {
  TItem Item;
  TipoApontador Prox;
}TipoCelula;

typedef struct {
  TipoApontador Primeiro,Ultimo;
}TipoLista;

//-----OPERAÇÕES BASICAS TXT DINÂMICO-----
void FLVazia(TipoLista *plv);
void Insere(TItem x, TipoLista *plv);
void Imprime(TipoLista plv);
int Vazia(TipoLista plv);
void geraclauses(TipoLista lista1, int (*mat)[50], int N);
void imprimeItem(TItem* pItem);
#endif