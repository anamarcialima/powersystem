#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct data Data;

struct data{
    int dia;
    int mes;
    int ano;
};

struct funcionario{
    char nomeDoFuncionario[200];
    char email[100];
    char senha[10];
    int telefone;
    Data dataNascimento;
    char cargo[15];
}Funcionario;

struct produtos{
    char id;
    char nomeDoProduto[200];
    char categoriaDoProduto[100];
    float quantidade;
    float preco;
    Data dataDeVencimento;
    Data dataDeCadastro;
}Produtos;

int opc;

FILE *database_funcionarios; // base de dados dos funcionarios
FILE *database_produtos; // base de dados dos produtos

void iniciar();
int login();
int cadastrarFuncionario();
void menu();
int verificarData(Data verificando);
int cadastrarProduto();
int removerProdutos();
int atualizarProduto();
int listarProdutos();
