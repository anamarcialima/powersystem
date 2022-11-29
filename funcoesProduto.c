#include "arquivosCabecalho/data.h"
#include "arquivosCabecalho/produto.h"
#include "arquivosCabecalho/programa.h"

int cadastrarProduto(){

    baseDeDadosProdutos = fopen("baseDeDados/produtos.txt", "a+");

    validarBaseDeDadosProdutos(baseDeDadosProdutos);

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
    }while(validarData(Produtos.dataDeVencimento) == 0);

    do{
        printf("Data de Cadastro: ");
        scanf("%d/%d/%d%*c", &Produtos.dataDeCadastro.dia, &Produtos.dataDeCadastro.mes, &Produtos.dataDeCadastro.ano);
    }while(validarData(Produtos.dataDeCadastro) == 0);

    fprintf(baseDeDadosProdutos, "Data de vencimento: %d/%d/%d ", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.ano);
    fprintf(baseDeDadosProdutos, "Data de cadastro: %d/%d/%d\n", Produtos.dataDeCadastro.dia,Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);

    fclose(baseDeDadosProdutos);
    
    return 0;
}

int listarProdutos(){

    baseDeDadosProdutos = fopen("baseDeDados/produtos.txt", "a+");

    validarBaseDeDadosProdutos(baseDeDadosProdutos);

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

int atualizarProduto(){

    int id = listarProdutos();

    char buffer[1001];
    int linhaSelecionada, linhaAtual;

    printf("Digite o id do produto para atualizar: ");
    scanf("%d%*c",&linhaSelecionada);

    if(linhaSelecionada > id || linhaSelecionada <= 0){
        printf("Id do produto invalido!\n");
        return 0;
    }

    baseDeDadosProdutos = fopen("baseDeDados/produtos.txt", "r");
    FILE* novaBaseDeDadosProdutos = fopen("baseDeDados/produtosRecentes.txt","w");

    if(baseDeDadosProdutos == NULL || novaBaseDeDadosProdutos == NULL){
        printf("\nErro na abertura da base de dados dos funcionarios! \n");
        return 0;
    }

    linhaAtual = 0;

    while(fgets(buffer, 1001, baseDeDadosProdutos) != NULL){
        
        linhaAtual++;
        
        if(linhaAtual == linhaSelecionada){
            printf("Nome do produto: ");
            scanf("%[^\n]%*c", Produtos.nomeDoProduto);
            fprintf(novaBaseDeDadosProdutos, "Nome do produto: %s ", Produtos.nomeDoProduto);

            printf("Categoria do produto: ");
            scanf("%[^\n]%*c", Produtos.categoriaDoProduto);
            fprintf(novaBaseDeDadosProdutos, "Categoria do produto: %s ", Produtos.categoriaDoProduto);

            printf("Quantidade: ");
            scanf("%f%*c", &Produtos.quantidade);
            fprintf(novaBaseDeDadosProdutos, "Quantidade: %.2f ", Produtos.quantidade);

            printf("Preco/unidade: ");
            scanf("%f%*c", &Produtos.preco);
            fprintf(novaBaseDeDadosProdutos, "Preco: %.2f ", Produtos.preco);

            do{
                printf("Data de vencimento: ");
                scanf("%d/%d/%d%*c", &Produtos.dataDeVencimento.dia, &Produtos.dataDeVencimento.mes, &Produtos.dataDeVencimento.ano);
            }while(validarData(Produtos.dataDeVencimento) == 0);

            do{
                printf("Data de Cadastro: ");
                scanf("%d/%d/%d%*c", &Produtos.dataDeCadastro.dia, &Produtos.dataDeCadastro.mes, &Produtos.dataDeCadastro.ano);
            }while(validarData(Produtos.dataDeCadastro) == 0);

            fprintf(novaBaseDeDadosProdutos, "Data de vencimento: %d/%d/%d ", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.ano);
            fprintf(novaBaseDeDadosProdutos, "Data de cadastro: %d/%d/%d\n", Produtos.dataDeCadastro.dia,Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);

        }else{
            fputs(buffer,novaBaseDeDadosProdutos);
        }
    }

    fclose(baseDeDadosProdutos);
    fclose(novaBaseDeDadosProdutos);

    remove("baseDeDados/produtos.txt");
    rename("baseDeDados/produtosRecentes.txt", "baseDeDados/produtos.txt");
    return 1;
}

int removerProdutos(){

    int id = listarProdutos();

    baseDeDadosProdutos = fopen("baseDeDados/produtos.txt", "r+");
    FILE* novaBaseDeDadosProdutos = fopen("baseDeDados/produtosRecentes.txt","w");

    char buffer[1001];
    unsigned int linhaSelecionada;

    printf("\nDigite o id do produto: ");
    scanf("%u%*c",&linhaSelecionada);
    
    if(linhaSelecionada > id || linhaSelecionada <= 0){
        printf("Id do produto invalido!\n");
        return 0;
    }
    
    unsigned int linhaAtual = 1;

    while(fgets(buffer, 1001, baseDeDadosProdutos) != NULL){
        if(linhaAtual != linhaSelecionada){
            fputs(buffer, novaBaseDeDadosProdutos);
        }
        linhaAtual += 1;
    }

    fclose(baseDeDadosProdutos);
    fclose(novaBaseDeDadosProdutos);

    remove("baseDeDados/produtos.txt");
    rename("baseDeDados/produtosRecentes.txt", "baseDeDados/produtos.txt");
}