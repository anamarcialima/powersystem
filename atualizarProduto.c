#include "data.h"
#include "funcionario.h"
#include "produto.h" 

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
        
        database_produtos = fopen("arquivos/produtos.txt", "r");
        FILE* new_databaseProdutos = fopen("arquivos/ProdutosRecent.txt","w");

        if(database_produtos == NULL || new_databaseProdutos == NULL){
            printf("\n [ERRO]: Nao foi possivel abrir o arquivo\n");
            return 0;
        }

        linha_atual = 0;
        while(fgets(buffer,1001,database_produtos) != NULL){
            linha_atual++;
            if(linha_atual == linha_selecionada){
                printf("Nome do produto: ");
                scanf("%[^\n]%*c", Produtos.nomeDoProduto);
                fprintf(new_databaseProdutos, "Nome do produto: %s ", Produtos.nomeDoProduto);

                printf("Categoria do produto: ");
                scanf("%[^\n]%*c", Produtos.categoriaDoProduto);
                fprintf(new_databaseProdutos, "Categoria do produto: %s ", Produtos.categoriaDoProduto);

                printf("Quantidade: ");
                scanf("%f%*c", &Produtos.quantidade);
                fprintf(new_databaseProdutos, "Quantidade: %.2f ", Produtos.quantidade);

                printf("Preco/unidade: ");
                scanf("%f%*c", &Produtos.preco);
                fprintf(new_databaseProdutos, "Preco: %.2f ", Produtos.preco);

                do{
                    printf("Data de vencimento: ");
                    scanf("%d/%d/%d%*c", &Produtos.dataDeVencimento.dia, &Produtos.dataDeVencimento.mes, &Produtos.dataDeVencimento.ano);
                }while(verificarData(Produtos.dataDeVencimento) == 0);
    
                do{
                    printf("Data de Cadastro: ");
                    scanf("%d/%d/%d%*c", &Produtos.dataDeCadastro.dia, &Produtos.dataDeCadastro.mes, &Produtos.dataDeCadastro.ano);
                }while(verificarData(Produtos.dataDeCadastro) == 0);

                fprintf(new_databaseProdutos, "Data de vencimento: %d/%d/%d ", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.ano);
                fprintf(new_databaseProdutos, "Data de cadastro: %d/%d/%d\n", Produtos.dataDeCadastro.dia,Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);
    
            }else{
                fputs(buffer,new_databaseProdutos);
            }
        }
        
        fclose(database_produtos);
        fclose(new_databaseProdutos);

        remove("arquivos/produtos.txt");
        rename("arquivos/ProdutosRecent.txt", "arquivos/produtos.txt");
        return 1;
}