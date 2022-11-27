#include "arquivosCabecalho/data.h"
#include "arquivosCabecalho/funcionario.h"
#include "arquivosCabecalho/produto.h"

int listarProdutos(){

    baseDeDadosProdutos = fopen("baseDeDados/produtos.txt", "a+");

    if(baseDeDadosProdutos == NULL){
        printf("Erro na abertura do arquivo produtos.txt!\n\n");
        return 1;
    }

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t     PRODUTOS EM ESTOQUE \n\n");

    int id = 1; char dados[1001];

    if(fgets(dados, 1001, baseDeDadosProdutos) == NULL){
        printf("Estoque vazio\n\n");
        return 0;
    }else{
        do{
            printf("ID: %d  %s", id, dados);
            ++id;
        }while(fgets(dados, 1001, baseDeDadosProdutos) != NULL);
    }

    fclose(baseDeDadosProdutos);
    return id - 1;
}
