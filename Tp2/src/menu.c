#include "menu.h"

void menu()
{
    TipoLista lista;
    int N;
    int mat[26][50];

    int escolha[3];
    print_menu1();
    scanf("%d", &escolha[0]);

    switch (escolha[0])
    {
    case 1:
        print_menu3();
        scanf("%d", &escolha[1]);
        break;
    case 2:
        print_menu2();
        scanf("%d", &escolha[2]);
    default:
        break;
    }

    switch (escolha[2])
    {
    case 1:
        N = 6;
        geraclauses(lista, mat, N);
        break;
    case 2:
        N = 20;
        geraclauses(lista, mat, N);
        break;
    case 3:
        N = 30;
        geraclauses(lista, mat, N);
        break;
    case 4:
        N = 40;
        geraclauses(lista, mat, N);
        break;
    default:
        break;
    }
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
    printf("|\n|                           ");
    printf("Digite (1) para entrada manual ou (2) para entrada automatica");
    for (i = 0; i < 25; i++)
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

void print_menu3()
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
    printf("|\n|                                              ");
    printf("Digite a equação booleana:");
    for (i = 0; i < 41; i++)
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