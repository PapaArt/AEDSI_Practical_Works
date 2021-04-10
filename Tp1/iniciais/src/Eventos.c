#include "Eventos.h"

void inicializaEventolista(Clista* pListaEvento){

    pListaEvento->pPrimeiro = (Apointer) malloc(sizeof(CelulaEvento));
    pListaEvento->pUltimo = pListaEvento->pPrimeiro;
    pListaEvento->pPrimeiro->pProxC=NULL;
}

void ChecarEventolista(Clista* pListaEvento){
    if(pListaEvento->pPrimeiro->pProxC != NULL){
        inicializaEventolista(pListaEvento);
    }
}

void criaEvento (Evento* Evento, int diainicial, int diafinal, int mesinicial, int mesfinal, int anoinicial, int anofinal, int horainicial, int minutoinicial, int horafinal,
 int minutofinal,int duracao, char* descricao ){


    Evento->diainicial = diainicial;

    Evento->diafinal = diafinal;

    Evento->mesinicial = mesinicial;

    Evento->mesfinal = mesfinal;

    Evento->anoinicial = anoinicial;

    Evento->anofinal = anofinal;

    Evento->horainicial = horainicial;

    Evento->minutoinicial = minutoinicial;

    Evento->horafinal = horafinal;

    Evento->minutofinal = minutofinal;
;
    Evento->duracao = duracao;
    (Evento->descricao)=(char *) malloc(sizeof(char)*100);
    strcpy(Evento->descricao,descricao);

}
void criasemanaEvento (Evento* Evento,int diainicial,int diafinal,int mesinicial,int mesfinal,int ano,int horainicial,int minutoinicial
,int horafinal,int minutofinal,int duracao,char *descricao){
    int iter = diainicial;
    while(iter != diafinal+1 && mesinicial!=mesfinal){
        criaEvento(Evento,iter,diafinal,mesinicial,mesfinal,ano,ano,horainicial,minutoinicial,horafinal,minutofinal,duracao,descricao);
        iter = iter+1;
        if(iter = 29 && (mesinicial = 2 && ano%4 == 0 && (ano%400 == 0 || ano%100 != 0))){
            iter = 0;
            mesinicial = mesinicial+1;
        }
        if(iter = 28 && (mesinicial = 2 && (mesinicial%4 !=0))){
            iter = 0;
            mesinicial = mesinicial+1;
        }
        if(iter==30 && (mesinicial==4 || mesinicial== 6 || mesinicial== 9 || mesinicial== 11)){
            iter = 0;
            mesinicial = mesinicial+1;
        }
        if(iter==31){
            iter = 0;
            mesinicial = mesinicial+1;
        }
   }
}

void checareventosmMes(Clista listaevento, int mes){
    Apointer iter;
    iter = listaevento.pPrimeiro;
    int contador = 1;

    while(iter->pProxC != NULL){
        if (iter->evento.mesinicial == mes){
            printf("////////// Evento nº: %d //////////",contador);
            printf("Descrição: %s \n", iter->evento.descricao);
            printf("Data do evento: %d / %d / %d \n",iter->evento.diainicial, iter->evento.mesinicial, iter->evento.anoinicial);
            printf("Hora do evento: %d : %d \n", iter->evento.horainicial, iter->evento.minutoinicial);
            printf("//////////////////////////////////");
            contador = contador + 1;
        }
        iter = iter->pProxC;
    }
}
