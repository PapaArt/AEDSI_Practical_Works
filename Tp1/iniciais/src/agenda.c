#include <string.h>
#include "agenda.h"
#include "listacompromisso.h"
#include "listaAgenda.h"

void criaAgenda(Agenda pAgenda, int idProf, int ano, char nomeProf[100])
{
    TLista pListaCompromisso;

    
    pAgenda.idProf = idProf;

    pAgenda.ano = ano;

    strcpy(pAgenda.nomeProf, nomeProf);
    
    
    FLVazia(&pListaCompromisso);
}

int recuperaAgenda(Agenda *pAgenda, int dia, int mes, int ano)
{
    TCelula *iter;
    TCelula *head;
    int counter = 0;

    while (iter != NULL && iter->compromisso.dia != dia && iter->compromisso.mes != mes && iter->compromisso.ano != ano)
    {
        //anterior = iter;
        iter = iter->pProx;
        counter++;
    }
    if (iter == NULL)
    {
        printf("Não ha essa data na agenda.\n");
    }
    else
    {
        counter++;
        printf("Nome do Professor: %s\n", pAgenda->nomeProf);
        printf("Ano: %d\n", pAgenda->ano);
        //printf("Há %d compromissos apos essa data.", ((retornaNCompromissos()) - counter));
    }
}

int insereCompromisso(Compromisso *compromisso, int novaPrioridade, int novoDia, int novoMes,
                      int novoAno, int novaHora, int novoMinuto, int novoMinutoDuracao, char *novaDescricao)
{
    //geraIDcompromisso();
    int x;
    int num;
    num = geraIDcompromisso();
    int novoIdentificador = num;
    // FILE *arq;
    // char Linha[MAXTAM];
    // arq = fopen("randid.txt", "r");
    // if (arq == NULL) // Se houve erro na abertura
    // {
    //     printf("Problemas na abertura do arquivo para leitura de id's\n");
    //     return 0;
    // }
    // if (!feof(arq))
    // {
    //     fscanf(arq, "%d", &novoIdentificador);
    // }
    int novaHoraDuracao;

    if (novoMinutoDuracao > 60)
    {
        novaHora + (novoMinutoDuracao / 60);
        novoMinutoDuracao - (novoMinutoDuracao / 60);
    }
    int horafinal = 0, minutofinal, horafinal1, minutofinal1;
    TCelula celula;
    TLista pListaCompromisso;

    if (novoIdentificador != 0 && novaPrioridade != 0 && novoDia != 0 && novoMes != 0 && novoAno != 0 && novaHora != 0 && novoMinuto != 0 &&
        novoMinutoDuracao != 0 && novaDescricao != "\0")
    {
        inicializaCompromisso((compromisso), novaPrioridade, novoDia, novoMes, novoAno, novaHora, novoMinuto, novoMinutoDuracao, novaDescricao);

        horafinal = 0;
        novaHora += horafinal;
        novaHoraDuracao += horafinal;

        minutofinal = 0;
        novoMinuto += minutofinal;
        novoMinutoDuracao += minutofinal;

        horafinal1 = 0;
        compromisso->hora += horafinal1;
        compromisso->horaDuracao += horafinal1;

        minutofinal1 = 0;
        compromisso->minuto += minutofinal1;
        compromisso->minutoDuracao += minutofinal1;

        while (pListaCompromisso.pPrimeiro->pProx != NULL)
        {
            
            x = temConflito(&compromisso, &(pListaCompromisso.pPrimeiro->pProx->compromisso));
            if (x == 1)
            {
                printf("Compromisso nao pode ser criado, pois ha conflito de horario");
                break;
            }
            else
            {
                pListaCompromisso.pUltimo->compromisso = celula.compromisso;
                printf("Criacao de novo compromisso realizada com sucesso!");
                printf("%d", novoIdentificador);
            }
        }
    }
    else
    {
        printf("Erro na criacao de novo compromisso!");
    }
    //LInsere(pListaCompromisso, &celula);
}

int removeCompromisso(Agenda *pAgenda, int identificador)
{
    TLista *pListaCompromisso;
    Compromisso *compromisso;

    /*
	A ideia aqui é a seguinte, a gente vai acessar a lista de compromissos do usuário através da agenda dele, uma vez na lista de compromissos um while vai navegar por todos os compromissos e vai parar quando a variável 'Tarefa_Completa' for igual a 1 ou quando a lista de compromissos acabar (iter == NULL), dentro desse while a gente vai ficar comparando  o 'identificador' da célula com o 'identificador' fornecido pelo usuario, caso os dois identificadores sejam iguais entraremos em um if aonde removeremos tal compromisso e 'Tarefa_Completa' vai receber 1, encerrando o while.
	*/

    int Tarefa_Completa = 0;
    // typedef struct Pntr* Apontador; // assim a gente pode apontar pra dentro das structs

    TCelula *iter;     // 'iter' vai ser como nós vamos navegar pela lista de compromissos
    TCelula *anterior; //'anterior' vai ser usado na hora de remover a célula
    TCelula *aux;      //'aux' vai segurar o endereco da celula removida pra desalocar ela da memoria

    iter = pAgenda->pListaCompromisso->pPrimeiro; // iter aqui recebe o endereço da primeira celula
    anterior = iter;                              // essa linha vai nos ajudar a eliminar a celula caso ela esteja na primeira celula
  
    while (Tarefa_Completa != 1 && iter->pProx != NULL)
    {      
        if (iter->compromisso.identificador == identificador)
        {
            Tarefa_Completa = 1; //achamos a celula pra remover, 'Tarefa_Completa' recebe 1 pra encerrar o while
            if (iter == anterior)
            {
                LRetira(pListaCompromisso, iter); // 'iter == anterior' significa que temos que remover a primeira celula da lista entao chamamos a 'funcao LRetira'

                return 1;
            }
            else
            {
                Tarefa_Completa = 1;
                aux = iter;
                anterior->pProx = iter->pProx;
                free(aux);
                return 1;
            }
        }
        else
        {
            anterior = iter;    // 'anterior' sempre vai carregar o endereco da celula anterior, mas nao sei se posso fazer anterior receber inter assim
            iter = iter->pProx; // nessa linha avancamos pra proxima celula
        }
    }
}
void imprimeAgenda(Agenda pAgenda)
{
    TLista pListaCompromisso;
    TCelula *iter;

    iter = pListaCompromisso.pPrimeiro;

    Imprime(pListaCompromisso);
}

int retornaNCompromissos(TLista pListaCompromisso)
{
    int contador = 0;
    Apontador aux;
    aux = pListaCompromisso.pPrimeiro->pProx;
    while (aux != NULL)
    {
        contador++;
        aux = aux->pProx;
    }
    return contador;
}

int geraIDcompromisso()
{

    int i;
    FILE *filepointer;
    int count = 0;
    srand(time(NULL));

    filepointer = fopen("randid.txt", "w");
    for (i = 0; i < 100; i++)
    {
        int num = rand() % 10000;
        num = (num * (rand() % 33));
        if (num >= 1000 && num < 10000)
        {
            return num;
            count++;
        }
    }
    fclose(filepointer);
}
