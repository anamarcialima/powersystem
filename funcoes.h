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
    char telefone[15];
    Data dataNascimento;
    char cargo[15];

}Funcionario;

struct produtos{
    char nomeDoProduto[200];
    char categoriaDoProduto[100];
    float quantidade;
    float preco;
    Data dataDeVencimento;
    Data dataDeCadastro;
}Produtos;

FILE *database_funcionarios; // cria vari�vel ponteiro para a BASE DE DADOS DOS FUNCION�RIOS
FILE *database_produtos; // cria vari�vel ponteiro para a BASE DE DADOS DOS PRODUTOS

int iniciar();
int menu();
int cadastrarFuncionario(void);
int login(void);
int cadastrarProduto(void);
int listarProdutos(void);
int removerProdutos(void);
int verificarData(int dia, int mes, int ano);