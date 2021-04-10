#include <stdio.h>
#include <stdlib.h>
typedef int TipoChave;
typedef struct {
    TipoChave Chave;
    /* outros componentes */
} TItem;
typedef struct Celula* Apontador;
typedef struct Celula {
    TItem Item;
    struct Celula* pProx; /* Apontador pProx; */
} TCelula;
typedef struct {
    Apontador pPrimeiro;
    Apontador pUltimo;
} TLista;

void Inverte(TLista* lista){

    TCelula* elemento;
    TCelula* anterior;

    while(elemento->pProx != NULL){
        elemento->pProx = anterior;
    }
    TCelula* aux = lista->pPrimeiro;
    lista->pPrimeiro = lista -> pUltimo;
    lista->pUltimo = aux;


}

int main(){
    
    TLista* lista;
    Inverte(&lista);

}
