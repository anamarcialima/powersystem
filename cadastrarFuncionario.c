#include "arquivosCabecalho/data.h"
#include "arquivosCabecalho/funcionario.h"
#include "arquivosCabecalho/produto.h"

int cadastrarFuncionario(){

    printf("\n\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t FAZER CADASTRO \n\n");

    baseDeDadosFuncionarios = fopen("baseDeDados/funcionarios.txt", "a");

    if(baseDeDadosFuncionarios == NULL){
        printf("Erro na abertura do arquivo fucionarios.txt!\n\n");
        return 1;
    }

    printf("E-mail: ");
    scanf("%[^\n]%*c", Funcionario.email);
    fprintf(baseDeDadosFuncionarios, "E-mail: %s  ", Funcionario.email);

    printf("Senha: ");
    scanf("%[^\n]%*c", Funcionario.senha);
    fprintf(baseDeDadosFuncionarios, "Senha: %s  ", Funcionario.senha);

    printf("Nome: ");
    scanf("%[^\n]%*c", Funcionario.nomeDoFuncionario);
    fprintf(baseDeDadosFuncionarios, "Nome: %s  ", Funcionario.nomeDoFuncionario); //ARMAZENAR O DADO NO ARQUIVO

    printf("Telefone: ");
    scanf("%d%*c", &Funcionario.telefone);
    fprintf(baseDeDadosFuncionarios, "Telefone: %d  ", Funcionario.telefone);

    do{
        printf("Data de nascimento: ");
        scanf("%d/%d/%d%*c", &Funcionario.dataNascimento.dia, &Funcionario.dataNascimento.mes, &Funcionario.dataNascimento.ano);
    }while(verificarData(Funcionario.dataNascimento) == 0);

    fprintf(baseDeDadosFuncionarios, "Data de nascimento: %d/%d/%d  ", Funcionario.dataNascimento.dia, Funcionario.dataNascimento.mes,Funcionario.dataNascimento.ano);

    printf("Cargo: ");
    scanf("%[^\n]%*c", Funcionario.cargo);
    fprintf(baseDeDadosFuncionarios, "Cargo: %s\n\n", Funcionario.cargo);

    printf("\nCadastro realizado com sucesso!\n\n");

    fclose(baseDeDadosFuncionarios);

    login();

}
