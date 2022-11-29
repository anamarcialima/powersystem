#include "arquivosCabecalho/data.h"
#include "arquivosCabecalho/funcionario.h"
#include "arquivosCabecalho/produto.h"

void menuPrincipal(){

    printf("-----------------------------------------------------------------------------------------------------------\n\n");
    printf("\n\t\t\t\t    OLA, SEJA BEM VINDO AO POWER SYSTEM!\n\n");

    int opcao, contador;

    do{
        contador = 0;

        printf("1 - Cadastrar produto | 2 - Atualizar produto | 3 - Deletar produto | 4 - Estoque total | 5 - Logout\n\nO que voce deseja fazer? ");
        scanf("%d%*c", &opcao);
        
		printf("\n");
        
		limpar();
        switch(opcao){
            case 1:
                printf("\n-----------------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\t\t     CADASTRAR PRODUTO \n\n");
                if(cadastrarProduto() == 0){
                    printf("Produto cadastrado com sucesso!\n");
                }else{
                    printf("Erro ao cadastrar o produto");
                }
                menuPrincipal();
                break;
            case 2:
                limpar();
                atualizarProduto();
                menuPrincipal();
                break;
            case 3:
                limpar();
                removerProdutos();
                menuPrincipal();
                break;

            case 4:
                limpar();
                listarProdutos();
                menuPrincipal();
                break;

            case 5:
                limpar();
                menuInicial();
                break;

            default:
                printf("Opcao invalida! \n\n");
                contador++;
                printf("\n-----------------------------------------------------------------------------------------------------------\n");
                break;
        }
    }while(contador != 0);

}
