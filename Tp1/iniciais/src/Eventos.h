//Cabe�alho das Fun��es
#include "compromisso.h"

typedef struct {

    int mesinicial,diainicial,anoinicial, diafinal, mesfinal, anofinal,horainicial,minutoinicial,horafinal, minutofinal, duracao;
    char* descricao;

} Evento;

typedef struct Cel* Apointer;

typedef struct Cel {
    Evento evento;
    Apointer pProxC;
}CelulaEvento;

typedef struct {
 Apointer pPrimeiro;
 Apointer pUltimo;
}Clista;

void inicializaEventolista(Clista* pListaEvento);

void ChecarEventolista(Clista* pListaEvento);

void criaEvento(Evento* Evento, int diainicial, int diafinal, int mesinicial, int mesfinal, int anoinicial, int anofinal, int horainicial, int minutoinicial, int horafinal,
 int minutofinal,int duracao, char* descricao );
// no come�o eu n�o pensava em deixar um professor criar um evento, mas seria uma op��o interessante
// a gente tbm podia s� copi... digo reciclar o c�digo da fun��o criacompromisso aqui j� que os parametros s�o parecidos
void criasemanaEvento(Evento* Evento,int diainicial,int diafinal,int mesinicial,int mesfinal,int ano,int horainicial,int minutoinicial,int horafinal,int minutofinal,int duracao,char *descricao);
// se um evento durar mais de um dia basta pegar o dia final e o inicial e definir tudo no meio como um evento...
//... pregui�oso ? Talvez, mas n�o tive outras ideias de como implementar isso sem criar outra estrutura.
void checareventosmMes(Clista listaevento, int mes);
//a ideia aqui � que a gente crie 12 listas encadeadas, cada uma associada a um m�s do ano.
// a gente pegaria o m�s fornecido no param�tro e listaria os compromissos do m�s


/*Pra implementar as fun��es a gente criaria 12 listas encadeadas como descrito anteriormente
e preencheria elas com os eventos fornecidos pelo usu�rio, alguns eventos j� estariam l� por default, esses seriam os feriados
Por motivos de simplicidade vamos s� pegar alguns deles pra implementar eles, talvez uns 3 feriados
e dois eventos que durem mais de um dia, como a secom e o carnaval j� � o sufuciente na minha opini�o
Caso todos concordem com essa linha de racicionio algu�m vai ter que lembrar de p�r isso na documenta��o
*/

