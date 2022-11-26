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

int verificarData(Data verificando);