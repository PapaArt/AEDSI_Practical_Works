#include "registro.h"
#include <string.h>

void GeraReg(TListaReg pListaReg){

    (pListaReg).fFirstReg = (pointerReg)malloc(sizeof(TCelulaReg));
    (pListaReg).fLastReg = (pListaReg).fFirstReg;
    (pListaReg).fFirstReg->prox = NULL;

}

int InsereReg(TListaReg** pListaReg, TCelulaReg** celReg){
    Registro* reg;

    TCelulaReg* iter;
    TCelulaReg* anterior;
    TCelulaReg* aux;
    iter = (*pListaReg)->fFirstReg;
    anterior = aux; 

    while(iter != NULL && (*celReg)->registro->numAgendas > aux->registro->numAgendas){
        
        anterior=iter;
        iter=iter->prox;
    }if(iter= NULL){
        
        anterior->prox = (*celReg);

    }
    else{

        anterior->prox->registro = (*celReg)->registro;
        (*celReg)->prox = iter;
    }
}

int RemoveReg(TListaReg* pListaReg, Registro* pItem){
    TList* list;
    list->fFirst = pListaReg->fFirstReg->registro->pListAgenda->fFirst;
    TCelulaReg* paux;
    if (LIsEmpty(list))
    {
        return 0;
    }
    else
    {
        pItem = pListaReg->fFirstReg->prox->registro;
        paux = pListaReg->fFirstReg;
        pListaReg->fFirstReg = pListaReg->fFirstReg->prox;
        free(paux);
        return 1;
    }

}

void PrintaReg(TListaReg* pListaReg){
    
    pointerReg iter = pListaReg->fFirstReg->prox;
    while (iter != NULL)
    {
        printf("%d\n", pListaReg->fFirstReg->registro->ano);
        printf("%s\n", pListaReg->fFirstReg->registro->instituicao);
        printf("%d\n", pListaReg->fFirstReg->registro->numAgendas);
        pListaReg->fFirstReg = pListaReg->fFirstReg->prox;
        printList(iter->registro->pListAgenda);
        iter = iter->prox;
    }
    
}

void criaRegistro(Registro** registro, int numAgendas, int ano, char* instituicao){
    Agenda* item;
    TList pListaAgenda;
    
    (*registro)->numAgendas = numAgendas;
    (*registro)->ano = ano;

    ((*registro)->instituicao)=(char *) malloc(sizeof(char)*100);
    strcpy((*registro)->instituicao,instituicao);
    while (numAgendas!=0){
        LEmpty(pListaAgenda);
        numAgendas = numAgendas-1;
    }
    
}

char retornaNomeInst(Registro* registro){

    printf("%s", registro->instituicao);

}

int retornaNumDeAgendas(TCelulaReg* head){
    int count = 0;
    TCelulaReg* current = head;
    while (current != NULL)
    {
        count++;
        current = head->prox;
    }
    return count;
}

void LeArquivo(){
    Registro** registro;
    TCelula* celula;
    TCelulaReg** celReg;
    Agenda fItem;
    TLista pListaCompromisso;
    TListaReg ListRegistro;
    TListaReg** pListaReg;
    TList* pListaAgenda;
    FILE *arq;
    
    char Linha[100];
    char *result;
    char desc[100];
    int i, j, prio, day, month, year, hour, min, minD, numprof;
    int numCompromissos = 0;
    int comp = 0;
    // Abre um arquivo TEXTO para LEITURA
    arq = fopen("arqteste.txt", "r");
    if (arq == NULL)  // Se houve erro na abertura
    {
        printf("Problemas na abertura do arquivo\n");
        return;
    }
    
    int idprof = 0;
    char nomeprof[100] ; 
    int anoagendaprof = 0;
    

    while (!feof(arq))
    {
        
        fscanf(arq,"%d",&numprof);
        GeraReg(ListRegistro);
        //InsereReg(pListaReg, celReg);
        // printf("Insira o nome da Instituição: %s");
        // scanf("%s",&registro->instituicao);
        //criaRegistro(registro, numprof, 2021, "UFV");
        for (i = 0; i < numprof; i++)
        {
            
            fscanf(arq,"%d",&numCompromissos);
            
            fscanf(arq,"%d",&idprof);
            
            fscanf(arq,"%s",nomeprof);
            
            fscanf(arq,"%d",&anoagendaprof);
            
            criaAgenda(fItem,idprof,anoagendaprof,nomeprof);

            for (j = 0; j < numCompromissos; j++)
            {
                
                fscanf(arq,"%d",&prio);
                
                fscanf(arq,"%d",&day);
                
                fscanf(arq,"%d",&month);
                
                fscanf(arq,"%d",&year);
                
                fscanf(arq,"%d",&hour);
                
                fscanf(arq,"%d",&min);
                
                fscanf(arq,"%d",&minD);
                
                fscanf(arq,"%s",desc);
                
                LInsereII(&pListaCompromisso,prio,day,month,year,hour,min,minD,desc);
                
                //inicializaCompromisso(&((*registro)->CelulaAgenda->agenda->compromisso),prio,day,month,year,hour,min,minD,desc); 
            }
        }
        
    }
    fclose(arq);

}