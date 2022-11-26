#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "data.h"

struct funcionario{
    char nomeDoFuncionario[200];
    char email[100];
    char senha[10];
    int telefone;
    Data dataNascimento;
    char cargo[15];
}Funcionario;

int opc;

FILE *database_funcionarios; // base de dados dos funcionarios

void iniciar();
int login();
int cadastrarFuncionario();
void menu();