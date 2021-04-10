#include "compromisso.h"
#include "listacompromisso.h"

void inicializaCompromisso(Compromisso* compromisso,int prioridade, int dia, int mes, int ano, int hora, int minuto,
 int minutoDuracao, char *descricao){
    TLista pListaCompromisso;
    TCelula celula;
    int identificador = 0;
    int horaDuracao = 0;
    int i;

    for (i = 0; i < 1000; i++)
    {
        int num = rand() % 10000;
        num = (num*(rand() % 33));
        if (num >= 1000 && num < 10000)
        {
            identificador = num;
        }
    }
    (compromisso)->identificador = identificador;
    (compromisso)->prioridade = prioridade;

    (compromisso)->dia = dia;

    (compromisso)->mes = mes;
 
    (compromisso)->ano = ano;

    (compromisso)->hora = hora;

    (compromisso)->minuto = minuto;

    (compromisso)->horaDuracao = horaDuracao;

    (compromisso)->minutoDuracao = minutoDuracao;
    
    ((compromisso)->descricao) = (char*) malloc(sizeof(char)*MAXTAM);
    
    strcpy((compromisso)->descricao,descricao);
    
    //LInsere(pListaCompromisso,&celula);
    

}

void alteraPrioridade(Compromisso*compromisso, int NovaPrioridade){

    compromisso->prioridade = NovaPrioridade;

}

void retornaPrioridade(Compromisso compromisso){

    printf("Prioridade desse compromisso:%d\n", compromisso.prioridade);

}

int temConflito(Compromisso**compromisso, Compromisso**compromisso1){
    int horaFinal, minutoFinal, horaFinal1, minutoFinal1;
    horaFinal = 0;
    horaFinal1 = 0;

    minutoFinal = 0;
    minutoFinal1 = 0;
    
    (*compromisso)->hora += horaFinal;
    (*compromisso)->horaDuracao += horaFinal;
    (*compromisso)->minuto += minutoFinal;
    (*compromisso)->minutoDuracao += minutoFinal;

    (*compromisso1)->hora += horaFinal1;
    (*compromisso1)->horaDuracao += horaFinal1;
    (*compromisso1)->minuto += minutoFinal1;
    (*compromisso1)->minutoDuracao += minutoFinal1;

    while (((*compromisso)->dia == (*compromisso1)->dia) && ((*compromisso)->mes == (*compromisso1)->mes) && ((*compromisso)->ano == (*compromisso1)->ano)){
        
        if(((*compromisso)->hora == (*compromisso1)->hora) && ((*compromisso)->minuto == (*compromisso1)->minuto)){
            
            printf("Há conflito entre os 2 compromissos");
            return 1;

        }else if (((*compromisso)->hora < (*compromisso1)->hora) && ((*compromisso)->minuto < (*compromisso1)->minuto)){
            if((horaFinal > (*compromisso1)->hora) && (minutoFinal > (*compromisso1)->minuto)){
                printf("Há conflito entre os 2 compromissos");
                return 1;
            }
        }else if (((*compromisso1)->hora < (*compromisso)->hora) && ((*compromisso1)->minuto < (*compromisso)->minuto)){
            if((horaFinal1 > (*compromisso)->hora) && (minutoFinal1 > (*compromisso)->minuto)){
                printf("Há conflito entre os 2 compromissos");
                return 1;
            }

        }else {
        
            printf("Não há conflito entre os compromissos");
            return 0;

        }
        
    }
    

}

void imprimeCompromisso(Compromisso compromisso){

    printf("----------------------------------------------------------------------------------------------------\n");
    printf("Identificador do compromisso: %d \n", compromisso.identificador);
    printf("Prioridade do compromisso: %d \n", compromisso.prioridade);
    printf("Data do compromisso: %d / %d / %d \n",compromisso.dia, compromisso.mes, compromisso.ano);
    printf("Hora do compromisso: %d : %d \n", compromisso.hora, compromisso.minuto);
    printf("Duracao: %d : %d horas \n", compromisso.horaDuracao, compromisso.minutoDuracao);
    printf("Descricao: %s \n", compromisso.descricao);
}
