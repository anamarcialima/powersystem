#include "arquivosCabecalho/data.h"
#include "arquivosCabecalho/funcionario.h"
#include "arquivosCabecalho/produto.h"

int removerProdutos(){

    int id = listarProdutos();

    baseDeDadosProdutos = fopen("baseDeDados/produtos.txt", "r+");
    FILE* novaBaseDeDadosProdutos = fopen("baseDeDados/ProdutosRecentes.txt","w");

    char buffer[1001];
    unsigned int linha_selecionada;

    printf("\nDigite o id do produto: ");
    scanf("%u%*c",&linha_selecionada);
    if(linha_selecionada > id || linha_selecionada <= 0){
        printf("id do produto invalido!\n");
        return 0;
    }
    unsigned int linha_atual = 1;

    while(fgets(buffer, 1001, baseDeDadosProdutos) != NULL){
        if(linha_atual != linha_selecionada){
            fputs(buffer, novaBaseDeDadosProdutos);
        }
        linha_atual += 1;
    }

    fclose(baseDeDadosProdutos);
    fclose(novaBaseDeDadosProdutos);

    remove("baseDeDados/produtos.txt");
    rename("baseDeDados/ProdutosRecentes.txt", "baseDeDados/produtos.txt");

}
