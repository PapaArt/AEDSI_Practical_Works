#include "dinamic.h"
Registro *iniciaReg()
{

    Registro *reg;
    reg = (Registro *)malloc(sizeof(reg));
    if (reg != NULL)
    {
        reg->chave = 0;
        reg->real_value[0] = 0;
        reg->real_value[1] = 0;
        reg->real_value[2] = 0;
        reg->real_value[3] = 0;

        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                reg->string[i][j] = 0;
            }
        }
    }
    return reg;
}
vetor* iniciaVet(){

    vetor* vet;
    vet = (vetor*)malloc(sizeof(vet));
    if(vet != NULL){
        vet->inicio = 0;
        vet->final = 0;
        vet->quantidade = 0;
    }

}
int geraReg(Registro *item, vetor* vet, int pos){
    item->chave = rand() % 10001;
    vet->registros[pos] = item->chave;
    //printf("id: %d\n", item->chave);
    int i, j;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 200; j++)
        {
            item->string[i][j] = 'a' + (char)(rand() % 26);
            //printf("%c", item->string[i][j]);
        }
    } //printf("\n");

    for (int i = 0; i < 4; i++)
    {
        item->real_value[i] = (float)rand() / 10001;
        //printf("real value: %f\n", item->real_value[i]);
    }
}
void select_sort(vetor *vet, int flag)
{

    int i, j, min;
    double comp = 0, mov = 0;
    int n = vet->quantidade;
    Registro *aux;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            comp++;
            if (vet->registros[i]->chave < vet->registros[min]->chave)
            {
                min = j;
            }
        }
        mov++;
        aux = vet->registros[min];
        vet->registros[min] = vet->registros[i];
        vet->registros[i] = aux;
    }
    if (flag)
    {
        printf("Comparações iguais a = %lf\n", comp);
        printf("Movimentações iguais a = %lf\n", mov);
    }
}