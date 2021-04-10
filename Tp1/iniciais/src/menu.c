#include "agenda.h"
#include <string.h>
#include "compromisso.h"
#include "menu.h"
#include "listacompromisso.h"
#include "Eventos.h"
#include "registro.h"

//#include <stdio_ext.h>

int menu()
{
    TCelula *cabeca;
    TLista pListaCompromisso;
    Clista eventos;
    TLista *p;
    TListaReg pListareg;
    Agenda pAgenda;
    Compromisso compromisso;
    int menu1, menu2;
    char nome[MAXTAM];
    int resp[2];
    FLVazia(&pListaCompromisso);
    inicializaEventolista(&eventos);
    GeraReg(pListareg);

    while (menu1 != 1)
    {
        menu1 = print_menu1();
        // print_menu1();
        scanf("%d", &resp[0]);

        int idProf, testeidprof, ano;

        switch (resp[0])
        {
        case 1:
            printf("Digite o ID: ");
            scanf("%d", &idProf);
            FILE *arq1;
            int k = 0;
            arq1 = fopen("randidPROF.txt", "r");
            if (arq1 == NULL) // Se houve erro na abertura
            {
                printf("Problemas na abertura do arquivo\n");
                menu1 = 0;
            }
            while (!feof(arq1))
            {

                fscanf(arq1, "%d", &testeidprof);
                while (testeidprof != idProf && k != 100)
                {
                    fscanf(arq1, "%d", &testeidprof);
                    k++;
                }
                if (testeidprof == idProf)
                {
                    printf("Acesso autorizado\n");
                    menu1 = 1;
                    break;
                }
                if (k == 100)
                {
                    //system("cls");

                    printf("--------------------------------Usurario nao encontrado--------------------------------\n");

                    menu1 = 0;
                    print_menu1();
                    break;
                }

                fclose(arq1);
            }
            //system("cls");
            break;

        case 2:

            LeArquivo();
            printf("Leitura por arquivo realizada com sucesso\n");
            //system("pause");
            //system("cls");
            menu1 = 1;
            break;

        case 3:
            printf("Digite o ID: ");
            scanf("%d", &idProf);
            FILE *arqnova;
            int l = 0;
            arqnova = fopen("randidPROF.txt", "r");
            while (!feof(arqnova))
            {

                fscanf(arqnova, "%d", &testeidprof);
                while (testeidprof != idProf && l != 100)
                {
                    fscanf(arq1, "%d", &testeidprof);
                    l++;
                }
                if (testeidprof == idProf)
                {
                    printf("o ID eh valido!");

                    printf("\nDigite o ano: ");
                    scanf("%d", &ano);
                    printf("\nDigite seu nome: ");
                    setbuf(stdin, 0);
                    fgets(nome, 255, stdin);
                    nome[strlen(nome) - 1] = '\0';
                    criaAgenda(pAgenda, idProf, ano, nome);
                    printf("\nAgenda criada com sucesso!!!\n");

                    menu1 = 1;
                    //print_menu2();
                    break;
                }
                if (l == 100)
                {
                    //system("cls");
                    printf("--------------------------------Usurario nao encontrado--------------------------------\n");
                    printf("----------------------Tente novamente Utilizando um usuario Valido---------------------\n");
                    print_menu1();
                    break;
                }

                fclose(arqnova);
            }
            break;
            //system("cls");

        case 4:
            printf("Programa encerrado!!!\n");
            menu1 = 1;
            break;
        default:
            printf("Erro! Codigo não reconhecido!!! Programa não inicializado!\n");
            break;
        }
    }
    int dia, mes, ano;
    int identificador;
    int prioridade;
    int hora, minuto, minutoDuracao;
    char description[MAXTAM];

    if (resp[0] != 3 && resp[0] != 2 && resp[0] != 1)
    {
        return 0;
    }
    else
    {

    LOOP:
        print_menu2();
        scanf("%d", &resp[1]);
        switch (resp[1])
        {
        case 1:
            printf("Digite a data requerida para recuperar a agenda (dd/mm): ");
            scanf("%d/%d", &dia, &mes);
            recuperaAgenda(&pAgenda, dia, mes, ano);
            break;
        case 2:
            printf("Insira a prioridade do compromisso: \n");
            scanf("%d", &prioridade);
            printf("Insira a data do compromisso (dd/mm/ano): \n");
            scanf("%d/%d/%d", &dia, &mes, &ano);
            printf("Insira o horário do compromisso (hh:mm):\n");
            scanf("%d:%d", &hora, &minuto);
            printf("Insira a duracao do compromisso(em minutos): \n");
            scanf("%d", &minutoDuracao);
            printf("Insira uma descricao breve para o compromisso: \n");
            setbuf(stdin, 0);
            fgets(description, 255, stdin);
            description[strlen(description) - 1] = '\0';
            LInsereII(&pListaCompromisso, prioridade, dia, mes, ano, hora, minuto, minutoDuracao, description);
            //system("pause");
            //system("cls");
            goto LOOP;
            break;

            //insereCompromisso(&compromisso, prioridade, dia, mes, ano, hora, minuto, minutoDuracao, description);
        case 3:

            printf("Insira o ID do compromisso a ser removido: ");
            scanf("%d", &identificador);
            removeCompromisso(&pAgenda, identificador);
            printf("Compromisso removido com sucesso!!!\n");
            //system("pause");
            //system("cls");
            goto LOOP;
            break;

        case 4:
            printf("%d\n", retornaNCompromissos(pListaCompromisso));
            //system("pause");
            //system("cls");
            goto LOOP;
            break;
        case 5:
            imprimeAgenda(pAgenda);
            break;
        case 6:
            checareventosmMes(eventos, mes);
            goto LOOP;
            break;
        case 7:
            PrintaReg(&pListareg);
            break;
        default:
            printf("Programa encerrado com sucesso!!!\n");
            break;
        }
    }
}

int print_menu1()
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
    printf("|\n|                                      ");
    printf("Digite (1) para login e (2) para arquivo");
    for (i = 0; i < 35; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|                                     ");
    printf("Digite (3) para nova agenda e (4) para sair");
    for (i = 0; i < 33; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|             ");
    for (i = 0; i < 100; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n");

    printf("|");
    for (i = 0; i < 113; i++)
    {
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("---------->");
    fflush(stdin);
}

int print_menu2()
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
    printf("|\n|          ");
    for (i = 0; i < 15; i++)
    {
        fputs(" ", stdout);
    }
    printf("Digite (1) para recuperar a agenda, (2) para inserir um compromisso");
    for (i = 0; i < 21; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|   ");
    for (i = 0; i < 18; i++)
    {
        fputs(" ", stdout);
    }
    printf("Digite (3) para remover um compromisso, (4) para ver o numero de compromissos");
    for (i = 0; i < 15; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 27; i++)
    {
        fputs(" ", stdout);
    }
    printf("Digite (5) para imprimir a agenda ou (6) para inicializar os eventos");
    for (i = 0; i < 18; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|        ");
    for (i = 0; i < 22; i++)
    {
        fputs(" ", stdout);
    }
    printf("Digite (7) para gerar um registro e (8) para fechar a agenda");
    for (i = 0; i < 23; i++)
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
