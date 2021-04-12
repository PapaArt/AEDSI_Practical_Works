#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "filaClau.h"
#ifndef MATCLAU_H
#define MATCLAU_H

typedef struct Clauses{
    TFila fila;
    int linha;
}Clauses; 

typedef struct CelClauses* Apontador;
typedef struct CelClauses{
    Clauses item;
    struct CelClauses* pProx;
}TCelClauses;

typedef struct TFilaClauses{
    Apontador pFrente;
    Apontador pTras;
}TFilaClauses; 

void FCVazia(TFilaClauses* pFilaClauses);
void FCVazia(TFilaClauses* pFilaClauses);
int CEnfileira(TFilaClauses* pFilaClauses, Clauses* clauses);
int CDesenfileira(TFilaClauses* pFilaClauses, Clauses* clauses);

#endif