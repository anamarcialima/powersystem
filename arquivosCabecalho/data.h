#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

typedef struct data Data;

struct data{
    int dia;
    int mes;
    int ano;
};

int validarData(Data validando);

#endif