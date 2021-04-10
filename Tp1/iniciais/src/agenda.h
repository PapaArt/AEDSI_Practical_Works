#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "compromisso.h"
#include "listacompromisso.h"
#ifndef AGENDA_H
#define AGENDA_H


typedef struct Agenda{
    
    int idProf, ano;
    char nomeProf[100];
    TLista* pListaCompromisso;
}Agenda;

int geraIDcompromisso();

void criaAgenda(Agenda pAgenda, int idProf, int ano, char nome[100]); // deve criar agenda vazia

int recuperaAgenda(Agenda* pAgenda, int dia, int mes, int ano);

int insereCompromisso(Compromisso* compromisso, int prioridade, int novoDia, int novoMes,
 int novoAno, int novaHora, int novoMinuto, int novoMinutoDuracao, char* novaDescricao);

int removeCompromisso(Agenda* pAgenda, int identificador);

void imprimeAgenda(Agenda pAgenda);

int retornaNCompromissos(TLista pListaCompromisso);




#endif
