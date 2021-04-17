#include "Manual.h"

void Preenche_Lista()
{
    int N,C;
    int i;
    char aux[50];
    TipoLista ListaManual;
    TipoApontador ListaAux;

    ListaAux = ListaManual.Primeiro;

    FLVazia(&ListaManual);
    
    printf("Por favor insira o número de váriaveis: \n");
    scanf("%d",&N);
    printf("Agora insira o número de cláusulas: \n");
    scanf("%d",&C);

    for(i = 0; i < C; i++ )
    {
        printf("Por favor insira a clausula %d",i);
        gets(aux); //Como a entrada sempre vai ter o mesmo tamanho provavelmente seja uma boa ideia usar o fgets ao invés do gets;

        ListaAux->Item.posicao1 = aux[3];
        ListaAux->Item.valor1 = aux[5];
        
        //Algum mecanismo precisa ser criado pra impedir algum engraçadinho de por como posição algum valor maior que N;

        ListaAux->Item.posicao2 = aux[9];
        ListaAux->Item.valor2 = aux[11];

        ListaAux->Item.posicao3 = aux[15];
        ListaAux->Item.valor3 = aux[17];

        ListaAux = ListaAux->Prox;       
    }
    // A Verifica_Lista vai ser chamada aqui, ela vai por os itens da nossa Lista na Verificanatabela
}


void Verifica_Lista(TipoLista* Plista,int N)
{
    TipoApontador Aux; 
    
    Aux = Plista->Primeiro;

    while(Aux->Prox != NULL)
    {
        verificaNaTabela(&Aux->Item,N);
        Aux = Aux->Prox;
    }
}
