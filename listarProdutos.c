#include "data.h"
#include "funcionario.h"
#include "produto.h" 

int listarProdutos(){
    database_produtos = fopen("arquivos/produtos.txt", "a+");

    if(database_produtos == NULL){
        printf("Erro na abertura do arquivo produtos.txt!\n\n");
        return 1;
    }

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t     PRODUTOS EM ESTOQUE \n\n");

    int id = 1; char dados[1001];

    if(fgets(dados, 1001, database_produtos) == NULL){
        printf("Estoque vazio\n\n");
        return 0;
    }else{
        do{
            printf("ID: %d  %s", id, dados);
            ++id;
        }while(fgets(dados, 1001, database_produtos) != NULL);
    }
    
    fclose(database_produtos);
    return id - 1;
}