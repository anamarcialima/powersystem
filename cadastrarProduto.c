#include "arquivosCabecalho/data.h"
#include "arquivosCabecalho/funcionario.h"
#include "arquivosCabecalho/produto.h"

int cadastrarProduto(){

    baseDeDadosProdutos = fopen("baseDeDados/produtos.txt", "a");

    if(baseDeDadosProdutos == NULL){
        printf("Erro na abertura do arquivo produtos.txt!\n\n");
        return 1;
    }

    printf("Nome do produto: ");
    scanf("%[^\n]%*c", Produtos.nomeDoProduto);
    fprintf(baseDeDadosProdutos, "Nome do produto: %s ", Produtos.nomeDoProduto);

    printf("Categoria do produto: ");
    scanf("%[^\n]%*c", Produtos.categoriaDoProduto);
    fprintf(baseDeDadosProdutos, "Categoria do produto: %s ", Produtos.categoriaDoProduto);

    printf("Quantidade: ");
    scanf("%f%*c", &Produtos.quantidade);
    fprintf(baseDeDadosProdutos, "Quantidade: %.2f ", Produtos.quantidade);

    printf("Preco/unidade: ");
    scanf("%f%*c", &Produtos.preco);
    fprintf(baseDeDadosProdutos, "Preco: %.2f ", Produtos.preco);

    do{
        printf("Data de vencimento: ");
        scanf("%d/%d/%d%*c", &Produtos.dataDeVencimento.dia, &Produtos.dataDeVencimento.mes, &Produtos.dataDeVencimento.ano);
    }while(verificarData(Produtos.dataDeVencimento) == 0);

    do{
        printf("Data de Cadastro: ");
        scanf("%d/%d/%d%*c", &Produtos.dataDeCadastro.dia, &Produtos.dataDeCadastro.mes, &Produtos.dataDeCadastro.ano);
    }while(verificarData(Produtos.dataDeCadastro) == 0);

    fprintf(baseDeDadosProdutos, "Data de vencimento: %d/%d/%d ", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.ano);
    fprintf(baseDeDadosProdutos, "Data de cadastro: %d/%d/%d\n", Produtos.dataDeCadastro.dia,Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);

    fclose(baseDeDadosProdutos);
    return 0;

}
