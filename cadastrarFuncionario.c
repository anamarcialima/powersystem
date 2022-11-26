#include "data.h"
#include "funcionario.h"
#include "produto.h"

int cadastrarFuncionario(){

    printf("\n\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t FAZER CADASTRO \n\n");

    database_funcionarios = fopen("arquivos/funcionarios.txt", "a");

    if(database_funcionarios == NULL){
        printf("Erro na abertura do arquivo fucionarios.txt!\n\n");
        return 1;
    }

    printf("E-mail: ");
    scanf("%[^\n]%*c", Funcionario.email);
    fprintf(database_funcionarios, "E-mail: %s  ", Funcionario.email);

    printf("Senha: ");
    scanf("%[^\n]%*c", Funcionario.senha);
    fprintf(database_funcionarios, "Senha: %s  ", Funcionario.senha);

    printf("Nome: ");
    scanf("%[^\n]%*c", Funcionario.nomeDoFuncionario);
    fprintf(database_funcionarios, "Nome: %s  ", Funcionario.nomeDoFuncionario); //ARMAZENAR O DADO NO ARQUIVO

    printf("Telefone: ");
    scanf("%d%*c", &Funcionario.telefone);
    fprintf(database_funcionarios, "Telefone: %d  ", Funcionario.telefone);

    do{
        printf("Data de nascimento: ");
        scanf("%d/%d/%d%*c", &Funcionario.dataNascimento.dia, &Funcionario.dataNascimento.mes, &Funcionario.dataNascimento.ano);
    }while(verificarData(Funcionario.dataNascimento) == 0);

    fprintf(database_funcionarios, "Data de nascimento: %d/%d/%d  ", Funcionario.dataNascimento.dia, Funcionario.dataNascimento.mes,Funcionario.dataNascimento.ano);

    printf("Cargo: ");
    scanf("%[^\n]%*c", Funcionario.cargo);
    fprintf(database_funcionarios, "Cargo: %s\n\n", Funcionario.cargo);

    printf("\nCadastro realizado com sucesso!\n\n");

    fclose(database_funcionarios);

    login();

}