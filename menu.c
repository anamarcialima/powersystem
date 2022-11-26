#include "data.h"
#include "funcionario.h"
#include "produto.h" 

void menu(){
    printf("-----------------------------------------------------------------------------------------------------------\n\n");
    printf("\n\t\t\t\t    OLA, SEJA BEM VINDO AO POWER SYSTEM!\n\n");

    int opcao, cont;

    do{
        cont = 0;

        printf("1 - Cadastrar produto | 2 - Atualizar produto | 3 - Deletar produto | 4 - Estoque total | 5 - Logout\n\nO que voce deseja fazer? ");
        scanf("%d%*c", &opcao);
        printf("\n");
        system("clear");
        switch(opcao){
            case 1:
                printf("\n-----------------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\t\t     CADASTRAR PRODUTO \n\n");
                if(cadastrarProduto() == 0){
                    printf("Produto cadastrado com sucesso!\n");
                }else{
                    printf("Erro ao cadastrar o produto");
                }
                menu();
                break;
            case 2:
                system("clear");
                atualizarProduto();
                menu();
                break;
            case 3:
                system("clear");
                removerProdutos();
                menu();
                break;

            case 4:
                system("clear");
                listarProdutos();
                menu();
                break;

            case 5:
                system("clear");
                iniciar();
                break;

            default:
                printf("Opcao invalida! \n\n");
                cont++;
                printf("\n-----------------------------------------------------------------------------------------------------------\n");
                break;
        }
    }while(cont != 0);

}
