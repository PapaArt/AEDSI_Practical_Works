#include <stdio.h>
#include <stdlib.h>
#include "listaAgenda.h"

void LEmpty(TList pListaAgenda)
{
    (pListaAgenda).fFirst = (pointer)malloc(sizeof(TCell));
    (pListaAgenda).fLast = (pListaAgenda).fFirst;
    (pListaAgenda).fFirst->prox = NULL;
}

int LIsEmpty(TList* pListaAgenda)
{
    return((pListaAgenda)->fFirst == (pListaAgenda)->fLast);
}

int LInsert(TList** pListaAgenda, TCell** cel)
{
    Agenda* agenda;
    TCell* iter;
    TCell* anterior;
    TCell* aux;
    iter = (*pListaAgenda)->fFirst;
    anterior = aux; 

    while(iter != NULL && (*cel)->agenda->idProf > aux->agenda->idProf){
        
        anterior=iter;
        iter=iter->prox;
    }if(iter= NULL){
        
        anterior->prox = (*cel);

    }
    else{

        anterior->prox->agenda = (*cel)->agenda;
        (*cel)->prox = iter;
    }
    
}

int LRemove(TList* pListaAgenda, Agenda* fItem)
{
    TCell* paux;
    if (LIsEmpty(*(&pListaAgenda)))
    {
        return 0;
    }
    else
    {
        fItem = pListaAgenda->fFirst->prox->agenda;
        paux = pListaAgenda->fFirst;
        pListaAgenda->fFirst = pListaAgenda->fFirst->prox;
        free(paux);
        return 1;
    }
}

void printList(TList* pListaAgenda)
{
    pointer iter = pListaAgenda->fFirst->prox;
    while (iter != NULL)
    {
        printf("%d\n", pListaAgenda->fFirst->agenda->ano);
        pListaAgenda->fFirst = pListaAgenda->fFirst->prox;
        imprimeAgenda(*(iter->agenda));
        iter = iter->prox;
    }
}

void deallocate(TCell* head)
{
    //Função recursiva para desalocar a lista
    TCell* trash;
    trash = head->prox;
    head->prox = trash->prox;
    free(trash);
}