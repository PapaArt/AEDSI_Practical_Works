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
        printf("\n Por favor insira a primeira variavel da clausula %d :",i);
        scanf("%s",ListaAux->Item.posicao1); 
        printf("\n Por favor insira o estado da variavel :");
        scanf("%s",ListaAux->Item.valor1);
        printf("\n Por favor insira a segunda variavel da clausula %d :",i);
        scanf("%s",ListaAux->Item.posicao2);
        printf("\n Por favor insira o estado da variavel :");
        scanf("%s",ListaAux->Item.valor2);
        printf("\n Por favor insira a terceira variavel da clausula %d :",i);
        scanf("%s",ListaAux->Item.posicao3);
        printf("\n Por favor insira o estado da variavel :");
        scanf("%s",ListaAux->Item.valor3);

        ListaAux = ListaAux->Prox;         
    }
    Verifica_Lista(&ListaManual,N);
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
