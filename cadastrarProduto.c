#include "funcoes.h"

int cadastrarProduto(){

    database_produtos = fopen("arquivos/produtos.txt", "a");

    if(database_produtos == NULL){
        printf("Erro na abertura do arquivo produtos.txt!\n\n");
        return 1;
    }
    
    printf("Nome do produto: ");
    scanf("%[^\n]%*c", Produtos.nomeDoProduto);
    fprintf(database_produtos, "Nome do produto: %s ", Produtos.nomeDoProduto);

    printf("Categoria do produto: ");
    scanf("%[^\n]%*c", Produtos.categoriaDoProduto);
    fprintf(database_produtos, "Categoria do produto: %s ", Produtos.categoriaDoProduto);

    printf("Quantidade: ");
    scanf("%f%*c", &Produtos.quantidade);
    fprintf(database_produtos, "Quantidade: %.2f ", Produtos.quantidade);

    printf("Preco/unidade: ");
    scanf("%f%*c", &Produtos.preco);
    fprintf(database_produtos, "Preco: %.2f ", Produtos.preco);

    do{
        printf("Data de vencimento: ");
        scanf("%d/%d/%d%*c", &Produtos.dataDeVencimento.dia, &Produtos.dataDeVencimento.mes, &Produtos.dataDeVencimento.ano);
    }while(verificarData(Produtos.dataDeVencimento) == 0);
    
    do{
        printf("Data de Cadastro: ");
        scanf("%d/%d/%d%*c", &Produtos.dataDeCadastro.dia, &Produtos.dataDeCadastro.mes, &Produtos.dataDeCadastro.ano);
    }while(verificarData(Produtos.dataDeCadastro) == 0);

    fprintf(database_produtos, "Data de vencimento: %d/%d/%d ", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.ano);
    fprintf(database_produtos, "Data de cadastro: %d/%d/%d\n", Produtos.dataDeCadastro.dia,Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);
    
    fclose(database_produtos);
    return 0;
}