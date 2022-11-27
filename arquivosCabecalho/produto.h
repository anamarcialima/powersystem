#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct produtos{
    char id;
    char nomeDoProduto[200];
    char categoriaDoProduto[100];
    float quantidade;
    float preco;
    Data dataDeVencimento;
    Data dataDeCadastro;
}Produtos;

FILE *baseDeDadosProdutos;

int cadastrarProduto();
int removerProdutos();
int atualizarProduto();
int listarProdutos();
