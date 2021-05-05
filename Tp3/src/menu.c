#include "menu.h"

int menu()
{
    int escolha[3];
    int resposta;
    print_menu1();
    scanf("%d", &escolha[0]);
    do
    {
        if (escolha[0] == 1)
        {
            // Cenario 1 -> ordenar inteiros
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

            long long int arr[resposta];
            random_array(arr, resposta);

            // O vetor ordenado deve ter sua saida no arquivo .txt
            if (escolha[1] == 1)
            {
                bubbleSort(arr, resposta, 1);
            }
            else if (escolha[1] == 2)
            {
                selectionSort(arr, resposta, 1);
            }
            else if (escolha[1] == 3)
            {
                insertionSort(arr, resposta, 1);
            }
            else if (escolha[1] == 4)
            {
                shellSort(arr, resposta, 1);
            }
            else if (escolha[1] == 5)
            {
                quickSort(arr, 0, resposta - 1, 1);
            }
            else if (escolha[1] == 6)
            {
                mergeSort(arr, 0, resposta - 1, 1);
            }
            else if (escolha[1] == 7)
            {
                radixSort(arr, resposta, 1);
            }

            printArray(arr, resposta);
            printf("Arquivo gerado com sucesso!!!\n");

            print_menu1();
            scanf("%d", &escolha[0]);
        }
        else if (escolha[0] == 2)
        {
            // Cenario 2 -> ordenar registros
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

            long long int array[resposta];
            int pos = 0;
            //srand((unsigned)time(NULL));
            for (int i = 0; i < resposta; i++)
            {
                Registro item;
                geraReg(&item, array, pos);
                pos++;
                //Insere(&item, &lista);
                printf("arr: %lld \n",array[i]);
            }
            

            // if (escolha[1] == 1)
            // {
            //     bubbleSort(arr, resposta);
            // } else if(escolha[1] == 2){
            //     selectionSort(arr, resposta);
            // } else if(escolha[1] == 3){
            //     insertionSort(arr, resposta);
            // } else if(escolha[1] == 4){
            //     shellSort(arr, resposta);
            // } else if(escolha[1] == 5){
            //     quickSort(arr, 0, resposta - 1);
            // } else if(escolha[1] == 6){
            //     mergeSort(arr, 0, resposta - 1, 1);
            // } else if(escolha[1] == 7){
            //     radixSort(arr, resposta);
            // }

            // printArray(arr, resposta);
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
