#include "registro.h"
#include "Eventos.h"


int main(){
    
    int a;

    system("cls");
    
    while(1){
        printf("#=============================================================#\n");
        printf("#                                                             #\n");
        printf("#                   1- Recuperar a agenda                     #\n");
        printf("#                                                             #\n");
        printf("#                   2- Inserir Compromisso                    #\n");
        printf("#                                                             #\n");
        printf("#                   3- Remover Compromisso                    #\n");
        printf("#                                                             #\n");
        printf("#                   4- Ver Num. Compromissos                  #\n");
        printf("#                                                             #\n");
        printf("#                   5- Imprimir Agenda                        #\n");
        printf("#                                                             #\n");
        printf("#                   6- Fechar Agenda                          #\n");
        printf("#                                                             #\n");
        printf("#=============================================================#\n\n");
        printf("Escolha uma das opcoes ou pressione esc para encerrar o programa:  \n");

        a = getch();

        if(a == 27){
            system("cls");
            break;
        }else if(a == 49){
            system("cls");
            LeArquivo(1);          
        }else if(a == 50){
            system("cls");
            LeArquivo(2);
        }else if(a == 51){
            system("cls");
            LeArquivo(3);
        }else if(a == 52){
            system("cls");
            LeArquivo(4);
        }else if(a == 53){
            system("cls");
            LeArquivo(5);
        }
        else if(a == 54){
            system("cls");
            LeArquivo(6);
        }
    }
    system("exit");

}