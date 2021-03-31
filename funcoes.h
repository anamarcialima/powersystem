#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//DADOS DO FUNCIONÁRIO
struct funcionario{
    char nomeDoFuncionario[200];
    char email[100];
    char senha[10];
    char telefone[15];
    char dataNascimento[10];
    char cargo[15];
}Funcionario;

//DADOS DO PRODUTO
struct produtos{
    char nomeDoProduto[200];
    char categoriaDoProduto[100];
    float quantidade;
    float preco;
    char dataDeVencimento[10];
    char dataDeCadastro[10];
}Produtos;

FILE *database_funcionarios; // cria variável ponteiro para a BASE DE DADOS DOS FUNCIONÁRIOS
FILE *database_produtos; // cria variável ponteiro para a BASE DE DADOS DOS PRODUTOS

int iniciar();
int menu();
int cadastrarFuncionario(void);
int login(void);
int cadastrarProduto(void);
int listarProdutos(void);
int removerProdutos(void);
