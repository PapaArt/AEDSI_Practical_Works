#include "sat.h"

void semPreconceito()
{
	#ifdef _WIN32
		system("cls");
	#elif __linux__
		system("clear");
	#endif
}

int truthTable(int n, int leng, TItem* pItem)
{
    int coluna[40];
    int pos = 0 ;
    int colum = 0;
    int j = 0, k = 0, z = 0;
    long long int bit = 1 << leng - 1;
    while (bit)
    {
        coluna[j] = n & bit ? 1 : 0;
        j++;
        bit >>= 1;
    }
    int jP = (n-1)-(pItem->posicao1);
    int kP = pItem->posicao2;
    int lP= pItem->posicao3;
    int jV = pItem->valor1;
    int kV = pItem->valor2;
    int lV= pItem->valor3;

    int expressao = 1 ;
    int claus = 0;
    if(jV == 2 && coluna[jP]==1){
        claus = 1;
    }if(jV == 1 && coluna[jP] == 0 ){
        claus = 1;
    }if(kV == 2 && coluna[kP]==1){
        claus = 1;
    }if(kV == 1 && coluna[kP] == 0 ){
        claus = 1;
    }if(lV == 2 && coluna[lP]==1){
        claus = 1;
    }if(lV == 1 && coluna[lP] == 0 ){
        claus = 1;
    }

    if(claus == 0){
        expressao = 0;
    }

    if(expressao == 1){
        for(int i=0; i<leng;i++){
            printf("%d",coluna[i]);
        }printf("\n");
    }
    if((jV == 2 && coluna[jP] == 1) || (kV == 2 && coluna[kP] == 1) || (lV == 2 && coluna[lP] == 1) ||
     (jV == 1 && coluna[jP] == 0) || (kV == 1 && coluna[kP] == 0) || (lV ==1 && coluna[lP] == 0)){
        if(coluna[jP] == 0){
            printf("( %sx%d |",(jV == 2 ? "" : "!"),(jP));
        }if(coluna[jP]==1){
            printf("( %sx%d |",(jV == 1 ? "" : "!"),(jP));
        }if(coluna[kP] == 0){
            printf(" %sx%d |",(kV == 2 ? "" : "!"),(kP));
        }if(coluna[kP]==1){
            printf(" %sx%d |",(kV == 1 ? "" : "!"),(kP));
        }if(coluna[lP] == 0){
            printf(" %sx%d ) & ",(lV == 2 ? "" : "!"),(lP));
        }if(coluna[lP]==1){
            printf(" %sx%d ) & ",(lV == 1 ? "" : "!"),(lP));
        } 
    }
    printf("Valor na tabela verdade e coluna: %d %d\n", coluna[jP], jP);
    printf("Valor na tabela verdade e coluna: %d %d\n", coluna[kP], kP);
    printf("Valor na tabela verdade e coluna: %d %d\n", coluna[lP], lP);
    printf("Valor da clausula: %d\n", jV);
    printf("Valor da clausula: %d\n", kV);
    printf("Valor da clausula: %d\n", lV);
    
}

  