#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void main()
{
    int i;
    FILE *filepointer;
    int count = 0;
    int identificador;
    srand(time(NULL));

    filepointer = fopen("randid.txt", "w");
    for (i = 0; i < 1000; i++)
    {
        int num = rand() % 10000;
        num = (num*(rand() % 33));
        if (num >= 1000 && num < 10000)
        {
            identificador = num;
        }
    }
    fclose(filepointer);
    printf("ID's gerados com sucesso!!!\nNúmeros gerados: %d\n", count);
}
