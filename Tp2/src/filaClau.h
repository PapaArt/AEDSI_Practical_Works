#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#ifndef FILACLAU_H
#define FILACLAU_H
#define MaxTam 1000

//typedef int TChave;
typedef struct TItem{
    //TChave chave;
    int linha;
    int coluna;
    int valor;
}TItem; 
// é o item da lista, por exemplo: o item m[i][j] da matriz. Ou seja, deve conter o conteúdo.
// No exemplo acima (mat[i][j]) o conteúdo seria : linha, coluna e o valor da posição.

typedef struct Celula* Apontador;
typedef struct Celula{
    TItem item;
    struct Celula* pProx;
}TCelula;
// tem como principal função "encapsular" o item, e gerar o apontador pro proximo item.

typedef struct TFila{
    TItem vItem[MaxTam+1];
    Apontador pFrente;
    Apontador pTras;
}TFila; 

void FFVazia(TFila* pFila);
int FEhVazia(TFila* pFila);
int FEnfileira(TFila* pFila,TItem* pItem);
int FDesenfileira(TFila* pFila,TItem* pItem);

#endif