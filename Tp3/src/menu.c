#include "menu.h"

int menu()
{
    int escolha[3];
    int resposta;
    int cenario = 0;
    int *exec1;
    exec1 = (int *)malloc(sizeof(int) * 14);
    for (int i = 0; i < 14; i++)
    {
        exec1[i] = 0;
    }
    long long int *comparacoes;
    comparacoes = (long long int *)malloc(sizeof(long long int) * 14);
    for (int i = 0; i < 14; i++)
    {
        comparacoes[i] = 0;
    }
    long long int *movimentacoes;
    movimentacoes = (long long int *)malloc(sizeof(long long int) * 14);
    for (int i = 0; i < 14; i++)
    {
        movimentacoes[i] = 0;
    }
    double mediatemp[14];
    double *tempo;
    tempo = (double *)malloc(sizeof(double) * 14);
    print_menu1();
    scanf("%d", &escolha[0]);
    do
    {
        if (escolha[0] == 1)
        {
            // Cenario 1 -> ordenar inteiros
            cenario = 1;
            print_menu2();
            scanf("%d", &escolha[1]);
            print_menu3();
            scanf("%d", &escolha[2]);

            if (escolha[2] == 1)
            {
                resposta = 1000;
            }
            else if (escolha[2] == 2)
            {
                resposta = 5000;
            }
            else if (escolha[2] == 3)
            {
                resposta = 10000;
            }
            else if (escolha[2] == 4)
            {
                resposta = 50000;
            }
            else if (escolha[2] == 5)
            {
                resposta = 100000;
            }
            else if (escolha[2] == 6)
            {
                resposta = 500000;
            }
            else if (escolha[2] == 7)
            {
                resposta = 1000000;
            }

            long long int *arr;
            arr = (long long int *)malloc(sizeof(long long int) * resposta);
            random_array(arr, resposta);

            // O vetor ordenado deve ter sua saida no arquivo .txt
            if (escolha[1] == 1)
            {
                exec1[0] += 1;
                bubbleSort(arr, resposta, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[0] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[0] = 0;
                }
            }
            else if (escolha[1] == 2)
            {
                exec1[1] += 1;
                selectionSort(arr, resposta, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[1] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[1] = 0;
                }
            }
            else if (escolha[1] == 3)
            {
                exec1[2] += 1;
                insertionSort(arr, resposta, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[2] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[2] = 0;
                }
            }
            else if (escolha[1] == 4)
            {
                exec1[3] += 1;
                shellSort(arr, resposta, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[3] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[3] = 0;
                }
            }
            else if (escolha[1] == 5)
            {
                exec1[4] += 1;
                quickSort(arr, 0, resposta - 1, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[4] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[4] = 0;
                }
            }
            else if (escolha[1] == 6)
            {
                exec1[5] += 1;
                mergeSort(arr, 0, resposta - 1, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[5] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[5] = 0;
                }
            }
            else if (escolha[1] == 7)
            {
                exec1[6] += 1;
                radixSort(arr, resposta, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[7] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[7] = 0;
                }
            }

            printArray(arr, resposta);

            print_menu1();
            scanf("%d", &escolha[0]);
            free(arr);
        }
        else if (escolha[0] == 2)
        {
            // Cenario 2 -> ordenar registros
            cenario = 2;
            TipoLista lista;
            Registro item;
            print_menu2();
            scanf("%d", &escolha[1]);
            print_menu3();
            scanf("%d", &escolha[2]);
            FLVazia(&lista);
            if (escolha[2] == 1)
            {
                resposta = 1000;
            }
            else if (escolha[2] == 2)
            {
                resposta = 5000;
            }
            else if (escolha[2] == 3)
            {
                resposta = 10000;
            }
            else if (escolha[2] == 4)
            {
                resposta = 50000;
            }
            else if (escolha[2] == 5)
            {
                resposta = 100000;
            }
            else if (escolha[2] == 6)
            {
                resposta = 500000;
            }
            else if (escolha[2] == 7)
            {
                resposta = 1000000;
            }

            long long int *array;
            array = (long long int *)malloc(sizeof(long long int) * resposta);
            int pos = 0;
            srand((unsigned)time(NULL));
            for (int i = 0; i < resposta; i++)
            {
                Registro item;
                geraReg(&item, array, pos);
                pos++;
                Insere(&item, &lista);
            }

            if (escolha[1] == 1)
            {
                exec1[7] += 1;
                bubbleSort(array, resposta, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[7] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[7] = 0;
                }
            }
            else if (escolha[1] == 2)
            {
                exec1[8] += 1;
                selectionSort(array, resposta, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[8] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[8] = 0;
                }
            }
            else if (escolha[1] == 3)
            {
                exec1[9] += 1;
                insertionSort(array, resposta, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[9] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[9] = 0;
                }
            }
            else if (escolha[1] == 4)
            {
                exec1[10] += 1;
                shellSort(array, resposta, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[10] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[10] = 0;
                }
            }
            else if (escolha[1] == 5)
            {
                exec1[11] += 1;
                quickSort(array, 0, resposta - 1, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[11] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[11] = 0;
                }
            }
            else if (escolha[1] == 6)
            {
                exec1[12] += 1;
                mergeSort(array, 0, resposta - 1, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[12] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[12] = 0;
                }
            }
            else if (escolha[1] == 7)
            {
                exec1[13] += 1;
                radixSort(array, resposta, 1, comparacoes, movimentacoes, tempo, cenario, exec1);
                if (exec1[13] == 5)
                {
                    printf("Arquivo criado com sucesso!!!\n");
                    exec1[13] = 0;
                }
            }

            printArray(array, resposta);

            print_menu1();
            scanf("%d", &escolha[0]);
            free(array);
        }

    } while (escolha[0] == 1 || escolha[0] == 2);
    printf("Programa encerrado!!!\n");
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
    printf("|\n|                           ");
    for (i = 0; i < 15; i++)
    {
        fputs(" ", stdout);
    }
    printf("Escolha o metodo de ordenacao:");
    for (i = 0; i < 41; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|");
    for (i = 0; i < 3; i++)
    {
        fputs(" ", stdout);
    }
    printf("(1)Bubble Sort (2)Selection Sort (3)Insertion Sort (4)Shell Sort (5)Quick Sort (6)Merge Sort (7)Radix Sort");
    for (i = 0; i < 4; i++)
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
    printf("|\n|        ");
    for (i = 0; i < 105; i++)
    {
        fputs(" ", stdout);
    }
    printf("|\n|                                 ");
    for (i = 0; i < 16; i++)
    {
        fputs(" ", stdout);
    }
    printf("Escolha o cenario:");
    for (i = 0; i < 46; i++)
    {
        fputs(" ", stdout);
    }
    printf("|");

    printf("\n|       ");
    for (i = 0; i < 34; i++)
    {
        fputs(" ", stdout);
    }
    printf("1 - Cenario 1       2 - Cenario 2");
    for (i = 0; i < 39; i++)
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
