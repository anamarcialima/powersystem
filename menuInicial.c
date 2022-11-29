#include "arquivosCabecalho/data.h"
#include "arquivosCabecalho/funcionario.h"
#include "arquivosCabecalho/produto.h"

void menuInicial(){

    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t POWER SYSTEM \n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t OBS: O programa a seguir nao reconhece acentuacao! \n\n");

    int opcao, contador;

   do{
        contador = 0;

        printf("1 - Login | 2 - Fazer cadastro | 3 - Sair do programa \n\nO que voce deseja fazer? ");
        scanf("%d%*c", &opcao);

        switch(opcao){
            case 1:
                login();
                limpar();
                break;
            case 2:
            	cadastrarFuncionario();
                limpar();
                break;
            case 3:
                limpar();
                exit(0);
                break;
            default:
                printf("\nOpcao invalida!\n\n");
                printf("-----------------------------------------------------------------------------------------------------------\n\n");
                contador++;
        }
    }while(contador != 0);

}
