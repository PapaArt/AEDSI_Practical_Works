#include "tad.h"

void inicializa(vetor *vet, int tam)
{
    int i, j, k, l;
    srand(time(NULL));
    for (i = 0; i < tam; i++)
    {
        vet[i].registros.chave = rand()%101;

        for (l = 0; l < 10; l++)
        {
            for (k = 0; k < 200; k++)
            {
                vet[i].registros.string[l][k] = 'a' + (char)(rand() % 26);
            }
        }
    
        for (j = 0; j < 4; j++)
        {
            vet[i].registros.real_value[j] = (float)(10.0 * rand() / 1001);
        }
   
    }
    
}

void imprime(vetor *vet, int tam)
{
    int i, j, l, k;
    for (i = 0; i < tam; i++)
    {
        printf("Chave \n");
        printf("%d\n", vet[i].registros.chave);
        
        printf("Matriz de char \n");
        for (l = 0; l < 10; l++)
        {
            for (k = 0; k < 200; k++)
            {
                printf("%c", vet[i].registros.string[l][k]);
            }
        }printf("\n");

        printf("Vetor de float \n");
        for (j = 0; j < 4; j++)
        {
            printf("%f\n", vet[i].registros.real_value[j]);
        }printf("\n\n");
    }
}
