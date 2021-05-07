#include "menu.h"

int menu()
{
    int escolha[3];
    int resposta;
    int cenario=0;
    int exec1[14];
    int* comparacoes;
    int* movimentacoes;
    double mediatemp[14];
    double tempo;
    clock_t fim, inicio;
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

            long long int* arr;
            arr = (long long int*)malloc(sizeof(long long int)*resposta);
            random_array(arr, resposta);

            // O vetor ordenado deve ter sua saida no arquivo .txt
            if (escolha[1] == 1)
            {
                inicio = clock();
                bubbleSort(arr, resposta, 1,comparacoes, movimentacoes,cenario);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[0] += 1;

            }
            else if (escolha[1] == 2)
            {
                inicio = clock();
                selectionSort(arr, resposta, 1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[1] += 1;
            }
            else if (escolha[1] == 3)
            {
                inicio = clock();
                insertionSort(arr, resposta, 1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[2] += 1;
            }
            else if (escolha[1] == 4)
            {
                inicio = clock();
                shellSort(arr, resposta, 1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[3] += 1;
            }
            else if (escolha[1] == 5)
            {
                inicio = clock();
                quickSort(arr, 0, resposta - 1, 1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[4] += 1;
            }
            else if (escolha[1] == 6)
            {
                inicio = clock();
                mergeSort(arr, 0, resposta - 1, 1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[5] += 1;
            }
            else if (escolha[1] == 7)
            {
                inicio = clock();
                radixSort(arr, resposta, 1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[6] += 1;
            }

            printArray(arr, resposta);
            printf("Arquivo gerado com sucesso!!!\n\n");
            printf("Tempo gasto: %lf segundos\n", tempo);

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

            long long int* array;
            array = (long long int*)malloc(sizeof(long long int)*resposta);
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
                inicio = clock();
                bubbleSort(array, resposta,1,comparacoes, movimentacoes,cenario);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[7] += 1;
                printf("\n");

            } else if(escolha[1] == 2){
                inicio = clock();
                selectionSort(array, resposta,1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[8] += 1;
                printf("\n");
            } else if(escolha[1] == 3){
                inicio = clock();
                insertionSort(array, resposta,1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[8] += 1;
                printf("\n");
            } else if(escolha[1] == 4){
                inicio = clock();
                shellSort(array, resposta,1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[10] += 1;
            } else if(escolha[1] == 5){
                inicio = clock();
                quickSort(array, 0, resposta - 1,1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[11] += 1;
                printf("\n");
            } else if(escolha[1] == 6){
                inicio = clock();
                mergeSort(array, 0, resposta - 1, 1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[12] += 1;
                printf("\n");
            } else if(escolha[1] == 7){
                inicio = clock();
                radixSort(array, resposta,1);
                fim = clock();
                tempo = ((double)(fim-inicio))/CLOCKS_PER_SEC;
                exec1[13] += 1;
                printf("\n");
            }

            printArray(array, resposta);
            printf("Arquivo gerado com sucesso!!!\n\n");
            printf("Tempo gasto: %lf segundos\n", tempo);

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
