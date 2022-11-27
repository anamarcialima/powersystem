#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct funcionario{
    char nomeDoFuncionario[200];
    char email[100];
    char senha[10];
    int telefone;
    Data dataNascimento;
    char cargo[15];
}Funcionario;

int opc;

FILE *baseDeDadosFuncionarios;

void menuInicial();
int login();
int cadastrarFuncionario();
void menuPrincipal();
