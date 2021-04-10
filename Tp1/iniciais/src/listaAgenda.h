#include <stdio.h>
#include <stdlib.h>
#include "agenda.h"
#ifndef LISTAAGENDA_H
#define LISTAAGENDA_H
//Para diferenciar da lista de compromissos fiz algumas declarações em inglês

typedef struct Cell* pointer;
typedef struct Cell
{
    Agenda* agenda;
    struct Cell* prox;
}TCell;

typedef struct 
{
    pointer fFirst;
    pointer fLast;
}TList;

void LEmpty(TList pListaAgenda);
int LIsEmpty(TList* pListaAgenda);
int LInsert(TList** pListaAgenda, TCell** cel);
int LRemove(TList* pListaAgenda, Agenda* fItem);
void printList(TList* pListaAgenda);
void deallocate(TCell* head);

#endif