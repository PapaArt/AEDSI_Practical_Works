#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void main()
{
    int i;
    FILE *filepointer;
    int count = 0;
    srand(time(NULL));

    filepointer = fopen("randidPROF.txt", "w");
    for (i = 0; i < 1000; i++)
    {
        int num = rand() % 10000;
        num = (num*(rand() % 33));
        if (num >= 1000 && num < 10000)
        {
            fprintf(filepointer, "%d\n", (num));
            count++;
        }
    }
    fclose(filepointer);
    printf("ID's gerados com sucesso!!!\nNúmeros gerados: %d\n", count);
}
