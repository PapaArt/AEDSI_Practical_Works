#include "teste.h"
Registro* iniciaReg(){

    Registro *reg;
    reg = (Registro*)malloc(sizeof(reg));
    if(reg != NULL){
        reg->chave = 0;
        reg->real_value[0] = 0;
        reg->real_value[1] = 0;
        reg->real_value[2] = 0;
        reg->real_value[3] = 0;
    }
    return reg;

}
void FLVazia(TipoLista *item)
{
    item->pPrimeiro = (Apontador)malloc(sizeof(TipoCelula));
    item->pUltimo = item->pPrimeiro;
    item->pPrimeiro->pProx = NULL;
}

void Insere(Registro *x, TipoLista *item)
{
    item->pUltimo->pProx = (Apontador)malloc(sizeof(TipoCelula));
    item->pUltimo = item->pUltimo->pProx;
    item->pUltimo->registro = *x;
    item->pUltimo->pProx = NULL;
}

void Imprime(TipoLista item)
{
    Apontador Aux;
    Aux = item.pPrimeiro->pProx;
    while (Aux != NULL)
    {
        printf("%d ", Aux->registro.chave);
        Aux = Aux->pProx;
    }
    printf("\n");
}

void select_sort(vetor *vet,int flag){

    int i, j,min;
    double comp=0,mov=0;
    int n= vet->quantidade ;
    Registro* aux;
    for(i = 0; i< n-1 ;i++){
        min = i;
        for (j = i + 1; j < n ; j++){
            comp++;
            if(vet->registros[i]->chave < vet->registros[min]->chave){ 
                min = j ;  
            } 
        }
        mov++;
        aux = vet->registros[min];
        vet->registros[min]= vet->registros[i];
        vet->registros[i] = aux;
    }
    if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);

    }

}