#include "arquivosCabecalho/programa.h"

int login(){

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    LOGIN \n\n");

    char email[100], senha[10];

    printf("E-mail: ");
    scanf("%[^\n]%*c", email);

    printf("Senha: ");
    scanf("%[^\n]%*c", senha);
    
	limparTerminal();
    
	menuPrincipal();
}
