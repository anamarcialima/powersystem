#include "data.h"
#include "funcionario.h"
#include "produto.h" 

void iniciar(){

    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t POWER SYSTEM \n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t OBS: O programa a seguir nao reconhece acentuacao! \n\n");

    int opcao, cont;

   do{
        cont = 0;

        printf("1 - Login | 2 - Fazer cadastro | 3 - Sair do programa \n\nO que você deseja fazer? ");
        scanf("%d%*c", &opcao);

        switch(opcao){
            case 1:
                login();
                system("clear");
                break;
            case 2:
                system("clear");
                cadastrarFuncionario();
                break;
            case 3:
                system("clear");
                exit(0);
                break;
            default:
                printf("\nOpcao invalida!\n\n");
                printf("-----------------------------------------------------------------------------------------------------------\n\n");
                cont++;
        }
    }while(cont != 0);

}