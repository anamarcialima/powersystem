#include "arquivosCabecalho/programa.h"

void validarBaseDeDadosFuncionario(FILE *baseDeDadosFuncionarios){
    
    baseDeDadosFuncionarios = fopen("baseDeDados/funcionarios.txt", "a");

    if(baseDeDadosFuncionarios == NULL){
        printf("Erro na abertura da base de dados dos funcionarios! \n\n");
        exit(0);
    }   
}

void validarBaseDeDadosProdutos(FILE *baseDeDadosProdutos){

    if(baseDeDadosProdutos == NULL){
        printf("Erro na abertura da base de dados dos produtos! \n\n");
        exit(0);
    }   
}
