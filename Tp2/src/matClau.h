#include "filaClau.h"
#ifndef MATCLAU_H
#define MATCLAU_H

typedef struct Clauses
{
    TFila fila;
    int linha;
} Clauses;

typedef struct CelClauses *Apontador;
typedef struct CelClauses
{
    Clauses item;
    struct CelClauses *pProx;
} TCelClauses;

typedef struct TListaClauses
{
    Apontador pFrente;
    Apontador pTras;
} TlistaClauses;

void FCVazia(TlistaClauses *pListaClauses);
void FCVazia(TlistaClauses *pListaClauses);
int CEnfileira(TlistaClauses *pListaClauses, Clauses *clauses);
int CDesenfileira(TlistaClauses *pListaClauses, Clauses *clauses);

#endif