#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef REGISTRO_H
#define REGISTRO_H
#include "listaAgenda.h"

typedef struct registro
{
    int numAgendas;
    int ano;
    char* instituicao;
    TCell* CelulaAgenda;
    TList* pListAgenda;
}Registro;


typedef struct CelulaReg* pointerReg;
typedef struct CelulaReg
{
    Registro* registro;
    struct CelulaReg* prox;
}TCelulaReg;

typedef struct
{
    pointerReg fFirstReg;
    pointerReg fLastReg;
}TListaReg;


void GeraReg(TListaReg pListaReg);
int InsereReg(TListaReg** pListaReg, TCelulaReg** celReg);
int RemoveReg(TListaReg* pListaReg, Registro* pItem);
void PrintaReg(TListaReg* pListaReg);
void criaRegistro(Registro** registro, int numAgendas, int ano, char* instituicao);
char retornaNomeInst(Registro* registro);
int retornaNumDeAgendas(TCelulaReg* head);
void LeArquivo();


#endif
