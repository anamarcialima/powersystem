#include "data.h"
#include "funcionario.h"
#include "produto.h" 

int login(){

    database_funcionarios = fopen("arquivos/funcionarios.txt", "r+");

    if(database_funcionarios == NULL){
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
    system("clear");
    menu();

}
