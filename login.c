#include "arquivosCabecalho/data.h"
#include "arquivosCabecalho/funcionario.h"
#include "arquivosCabecalho/produto.h"

int login(){

    baseDeDadosFuncionarios = fopen("baseDeDados/funcionarios.txt", "r+");

    if(baseDeDadosFuncionarios == NULL){
        printf("Erro na abertura do arquivo funcionarios.txt!\n\n");
        return 0;
    }

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    LOGIN \n\n");

    char email[100], senha[10];

    printf("E-mail: ");
    scanf("%[^\n]%*c", email);

    printf("Senha: ");
    scanf("%[^\n]%*c", senha);
    
	limpar();
    
	menuPrincipal();

}
