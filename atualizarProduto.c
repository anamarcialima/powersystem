#include "arquivosCabecalho/data.h"
#include "arquivosCabecalho/funcionario.h"
#include "arquivosCabecalho/produto.h"

int atualizarProduto(){

    int id = listarProdutos();

    char buffer[1001];
    int linha_selecionada,linha_atual;

    printf("Digite o id do produto para atualizar: ");
    scanf("%d%*c",&linha_selecionada);

    if(linha_selecionada > id || linha_selecionada <= 0){
        printf("id do produto invalido!\n");
        return 0;
    }

    baseDeDadosProdutos = fopen("baseDeDados/produtos.txt", "r");
    FILE* novaBaseDeDadosProdutos = fopen("baseDeDados/ProdutosRecent.txt","w");

    if(baseDeDadosProdutos == NULL || novaBaseDeDadosProdutos == NULL){
        printf("\n [ERRO]: Nao foi possivel abrir o arquivo\n");
        return 0;
    }

    linha_atual = 0;
    while(fgets(buffer,1001,baseDeDadosProdutos) != NULL){
        linha_atual++;
        if(linha_atual == linha_selecionada){
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
            }while(verificarData(Produtos.dataDeVencimento) == 0);

            do{
                printf("Data de Cadastro: ");
                scanf("%d/%d/%d%*c", &Produtos.dataDeCadastro.dia, &Produtos.dataDeCadastro.mes, &Produtos.dataDeCadastro.ano);
            }while(verificarData(Produtos.dataDeCadastro) == 0);

            fprintf(novaBaseDeDadosProdutos, "Data de vencimento: %d/%d/%d ", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.ano);
            fprintf(novaBaseDeDadosProdutos, "Data de cadastro: %d/%d/%d\n", Produtos.dataDeCadastro.dia,Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);

        }else{
            fputs(buffer,novaBaseDeDadosProdutos);
        }
    }

    fclose(baseDeDadosProdutos);
    fclose(novaBaseDeDadosProdutos);

    remove("baseDeDados/produtos.txt");
    rename("baseDeDados/ProdutosRecent.txt", "baseDeDados/produtos.txt");
    return 1;

}
