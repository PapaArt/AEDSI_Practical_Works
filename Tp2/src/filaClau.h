#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef FILACLAU_H
#define FILACLAU_H

typedef int TChave;
typedef struct TItem{
    TChave chave;
    int clausula;
}TItem;

typedef struct Celula* Apontador;
typedef struct Celula{
    TItem item;
    struct Celula* pProx;
}TCelula;

typedef struct TFila{
    Apontador pFrente;
    Apontador pTras;
}TFila; 

#endif