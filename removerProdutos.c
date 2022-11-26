#include "funcoes.h"

int removerProdutos(){

        int id = listarProdutos();

        database_produtos = fopen("arquivos/produtos.txt", "r+");
        FILE* new_databaseProdutos = fopen("arquivos/ProdutosRecent.txt","w");

        char buffer[1001];
        unsigned int linha_selecionada;

        printf("\nDigite o id do produto: ");
        scanf("%u%*c",&linha_selecionada);
        if(linha_selecionada > id || linha_selecionada <= 0){
            printf("id do produto invalido!\n");
            return 0;
        }
        unsigned int linha_atual = 1;

        while(fgets(buffer, 1001, database_produtos) != NULL){
            if(linha_atual != linha_selecionada){
                fputs(buffer, new_databaseProdutos);
            }
            linha_atual += 1;
        }

        fclose(database_produtos);
        fclose(new_databaseProdutos);

        remove("arquivos/produtos.txt");
        rename("arquivos/ProdutosRecent.txt", "arquivos/produtos.txt");
}