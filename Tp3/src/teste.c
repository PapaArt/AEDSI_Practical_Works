#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define RAND_MAX 101



typedef struct Registro{
    
    int chave;
    char string[10][200];
    float real_value[4];

}Registro;

void random_realvalue(Registro *item)
{
    for (int i = 0; i < 4; i++)
    {
        item->real_value[i] = (float)rand()/101;
    }
}

int main(){
    Registro* item;
    random_realvalue(item);
    for (int i = 0; i < 4; i++)
    {
        printf("%.3f\n",item->real_value[i]);
    }
}
