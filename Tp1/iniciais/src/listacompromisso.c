#include "listacompromisso.h"

void FLVazia(TLista *pListaCompromisso)
{
    
    pListaCompromisso->pPrimeiro = (Apontador)malloc(sizeof(TCelula));
    pListaCompromisso->pUltimo = pListaCompromisso->pPrimeiro;
    pListaCompromisso->pPrimeiro->pProx = NULL;
    
}

int LEhVazia(TLista *pListaCompromisso)
{
    return (pListaCompromisso->pPrimeiro == pListaCompromisso->pUltimo);
}

// void LInsere(TLista pListaCompromisso, TCelula* celula){
//     TCelula* iter;
//     TCelula* anterior;
//     iter = pListaCompromisso.pPrimeiro;
//     anterior = iter;

//     while(iter != NULL && celula->compromisso->prioridade > 1){

//         anterior = iter;
//         iter = iter->pProx;

//      }
//     if(iter == NULL){
//         anterior->pProx->compromisso = celula->compromisso;
//     }
//     else{
//         printf("ronaldo pilantra\n");
//         anterior->pProx->compromisso = celula->compromisso;
//         celula->pProx = iter;
//     }

// }

void LInsereII(TLista *pListaCompromisso, int prioridade, int dia, int mes, int ano, int hora, int minuto,
               int minutoDuracao, char *descricao)
{
    Compromisso compromisso1;
    inicializaCompromisso(&compromisso1, prioridade, dia, mes, ano, hora, minuto, minutoDuracao, descricao);
    imprimeCompromisso(compromisso1);
    pListaCompromisso->pUltimo->pProx = (Apontador)malloc(sizeof(TCelula));
    pListaCompromisso->pUltimo = pListaCompromisso->pUltimo->pProx;
    pListaCompromisso->pUltimo->compromisso = compromisso1;
    pListaCompromisso->pUltimo->pProx = NULL;
}

int LRetira(TLista *pListaCompromisso, TCelula *pItem)
{

    TCelula *pAux;
    if (LEhVazia(pListaCompromisso)){
        return 0;
    }
    pItem->compromisso = pListaCompromisso->pPrimeiro->pProx->compromisso;
    pAux = pListaCompromisso->pPrimeiro;
    pListaCompromisso->pPrimeiro = pListaCompromisso->pPrimeiro->pProx;
    free(pAux);
    return 1;
}

void Imprime(TLista pListaCompromisso)
{

    Apontador pAux;
    pAux = pListaCompromisso.pPrimeiro->pProx;
    while (pAux != NULL)
    {

        imprimeCompromisso(pAux->compromisso);
    }
}

void desaloca(TCelula *cabeca)
{
    //Função recursiva para desalocar a lista
    TCelula *lixo;
    lixo = cabeca->pProx;
    cabeca->pProx = lixo->pProx;
    free(lixo);
}
