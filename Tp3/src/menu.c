#include "menu.h"

void menu()
{    
    int escolha;
    int resposta;
    Registro item;
    print_menu1();
    scanf("%d", &escolha);

    if (escolha == 1)
    {
       resposta = 1000;
    } else if(escolha == 2){
        resposta = 5000;
    } else if(escolha == 3){
        resposta = 10000;
    } else if(escolha == 4){
        resposta = 50000;
    } else if(escolha == 5){
        resposta = 100000;
    } else if(escolha == 6){
        resposta = 500000;
    } else if(escolha == 7){
        resposta = 1000000;
    }
    
    long long int arr[resposta];
    random_array(arr, resposta);
    bubbleSort(arr, resposta);
    printf("Sorted array: \n");
    printArray(arr, resposta);

}



void print_menu1()
{
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 113; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 56; i++)
    {
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 53; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 113; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|                                            ");
    printf("Escolha o tamanho da entrada:");
    for (i = 0; i < 40; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|                      ");
    printf("(1)1000 (2)5000 (3)10.000 (4)50.000 (5)100.000 (6)500.000 (7)1.000.000");
    for (i = 0; i < 21; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("---------->");
    fflush(stdin);
}

void print_menu2()
{
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 113; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 56; i++)
    {
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 53; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("|\n|        ");
    for (i = 0; i < 105; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|                                 ");
    for (i = 0; i < 15; i++)
    {
        fputs(" ", stdout);
    }
    printf("Digite o valor de N:");
    for (i = 0; i < 45; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 34; i++)
    {
        fputs(" ", stdout);
    }
    printf("(1) para 15  (2) para 20  (3) para 30  (4) para 40");
    for (i = 0; i < 29; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("---------->");
    fflush(stdin);
}
