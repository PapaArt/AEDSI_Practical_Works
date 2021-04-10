#include <string.h>
#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>

#ifndef COMPROMISSO_H
#define COMPROMISSO_H
#define MAXTAM 100

typedef struct Compromisso{
    
    int identificador;
    int prioridade, dia, mes, ano, hora, minuto;
    int horaDuracao, minutoDuracao;    
    char *descricao;

}Compromisso;

void inicializaCompromisso(Compromisso* compromisso,int prioridade, int dia, int mes, int ano, int hora, int minuto,
 int minutoDuracao, char *descricao);

void alteraPrioridade(Compromisso* compromisso, int NovaPrioridade);

void retornaPrioridade(Compromisso compromisso);

int temConflito(Compromisso**compromisso, Compromisso**compromisso1);

void imprimeCompromisso(Compromisso compromisso);



#endif
