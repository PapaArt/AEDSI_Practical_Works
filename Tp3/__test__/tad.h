#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Register
{

    int chave;
    char string[10][200];
    float real_value[4];

} Register;

typedef struct
{
    Register registros;
} vetor;

void inicializa(vetor* vet, int tam);
void imprime(vetor* vet, int tam);