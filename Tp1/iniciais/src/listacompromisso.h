#ifndef LISTACOMPROMISSO_H
#define LISTACOMPROMISSO_H
#include "compromisso.h"


typedef struct Celula* Apontador;
typedef struct Celula{

    Compromisso compromisso;
    Apontador pProx;

}TCelula;

typedef struct{

    Apontador pPrimeiro;
    Apontador pUltimo;

}TLista;


void FLVazia(TLista* pListaCompromisso);

int LEhVazia(TLista* pListaCompromisso);

//void LInsere(TLista pListaCompromisso, TCelula* celula);

void LInsereII(TLista* pListaCompromisso, int prioridade, int dia, int mes, int ano, int hora, int minuto,
 int minutoDuracao, char *descricao);

int LRetira(TLista* pListaCompromisso, TCelula *pItem);

void Imprime(TLista pListaCompromisso);

void desaloca(TCelula* cabeca);









#endif
