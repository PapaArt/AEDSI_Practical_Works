#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
#include "filaClau.h"
#ifndef MATCLAU_H
#define MATCLAU_H

typedef struct Clauses{
    TLista fila;
    int linha;
}Clauses; 

typedef struct CelClauses* Apontador;
typedef struct CelClauses{
    Clauses item;
    struct CelClauses* pProx;
}TCelClauses;

typedef struct TListaClauses{
    Apontador pFrente;
    Apontador pTras;
}TlistaClauses; 

void FCVazia(TListaClauses* pListaClauses);
void FCVazia(TListaClauses* pListaClauses);
int CEnfileira(TListaClauses* pListaClauses, Clauses* clauses);
int CDesenfileira(TListaClauses* pListaClauses, Clauses* clauses);

#endif