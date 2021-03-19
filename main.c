#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//DADOS DO FUNCIONÁRIO
struct funcionario{
    char nomeDoFuncionario[200];
    char email[100];
    char senha[10];
    char telefone[15];
    char dataNascimento[10];
    char cargo[15];
}Funcionario;

//DADOS DO PRODUTO
struct produtos{
    char nomeDoProduto[200];
    char categoriaDoProduto[100];
    float quantidade;
    float preco;
    char dataDeVencimento[10];
    char dataDeCadastro[10];
}Produtos;


FILE *database_funcionarios; // cria variável ponteiro para a BASE DE DADOS DOS FUNCIONÁRIOS
FILE *database_produtos; // cria variável ponteiro para a BASE DE DADOS DOS PRODUTOS

void iniciar(void){

    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t POWER SYSTEM \n");
    printf("-----------------------------------------------------------------------------------------------------------\n");

    int opcao, cont;

    //EQUANDO O USUÁRIO NÃO DIGITAR UMAS DAS 3 OPÇÕES, O PROGRAMA IRÁ MOSTRAR O MENU E SOLICITAR UMA OPÇÃO VÁLIDA
    do{
        cont = 0;

        printf("1 - Login | 2 - Fazer cadastro | 3 - Sair do programa \n\nO que você deseja fazer? ");
        scanf("%d%*c", &opcao);

        if(opcao == 1){
            login();
        }else if(opcao == 2){
            cadastrarFuncionario();
        }else if(opcao == 3){
            return 0;
        }else{
            printf("\nOpção inválida!\n\n");
            printf("-----------------------------------------------------------------------------------------------------------\n\n");
            cont++;
        }
    }while(cont != 0);

}

void cadastrarFuncionario(void){

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t FAZER CADASTRO \n\n");


    /*================== VERIFICAR SE O EMAIL JÁ EXISTE ======================*/

    //FAZ A ABERTURA DO ARQUIVO funcionarios.txt PARA A LEITURA DE DADOS
    database_funcionarios = fopen("arquivos/funcionarios.txt", "r");

    //VERIFICA SE O ARQUIVO FOI ABERTO COM SUCESSO
    if(database_funcionarios == NULL){
        printf("Erro na abertura do arquivo fucionarios.txt!\n\n");
        return 0;
    }

    //VARIAVEIS QUE VÃO AUXLIAR NA VERIFICAÇÃO
    char buffer[100]; //GUARDA UMA LINHA DO ARQUIVO POR VEZ
    long int inicioLinha = 0; //INDICA ONDE COMEÇA A LINHA ANTES DE LER
    inicioLinha = ftell(database_funcionarios); //ftell guarda em inicioLinha quantos bytes tem desde o inicio do arquivo até o inicio da linha.

    printf("E-mail: ");
    gets(Funcionario.email);


    while(fscanf(database_funcionarios, "%s%*c", buffer) != EOF){ //LER A LINHA E ARMAZENA NO BUFFER
        //COMPARA AS STRINGS DA LINHA COM O EMAIL DIGITADO
        if (strcmp(buffer, Funcionario.email) == 0){
            printf ("\nEmail indisponível!\n");
            printf("\n-----------------------------------------------------------------------------------------------------------\n");
            return 0;
        }
        inicioLinha = ftell(database_funcionarios);
    }

    //FECHA O ARQUIVO QUE FOI ABERTO EM FORMA DE LEITURA
    fclose(database_funcionarios);


    /*================== VISTO EMAIL NÃO EXISTE NO ARQUIVO, AGORA OS OUTROS DADOS SERÃO SOLICITADOS AO USUÁRIO E ARMAZENADO NO ARQUIVO ======================*/

    //FAZ A ABERTURA DO ARQUIVO "FUNCIONÁRIOS" PARA A INSERÇÃO DE DADOS
    database_funcionarios = fopen("arquivos/funcionarios.txt", "a");

    //VERIFICA SE O ARQUIVO FOI ABERTO COM SUCESSO
    if(database_funcionarios == NULL){
        printf("Erro na abertura do arquivo fucionarios.txt!\n\n");
        return 1;
    }

    fprintf(database_funcionarios, "E-mail: %s  ", Funcionario.email);

    printf("Senha: ");
    gets(Funcionario.senha);
    fprintf(database_funcionarios, "Senha: %s  ", Funcionario.senha);

    printf("Nome: ");
    gets(Funcionario.nomeDoFuncionario);
    fprintf(database_funcionarios, "Nome: %s  ", Funcionario.nomeDoFuncionario); //ARMAZENAR O DADO NO ARQUIVO

    printf("Telefone: ");
    gets(Funcionario.telefone);
    fprintf(database_funcionarios, "Telefone: %s  ", Funcionario.telefone);

    printf("Data de nascimento: ");
    gets(Funcionario.dataNascimento);
    fprintf(database_funcionarios, "Data de nascimento: %s  ", Funcionario.dataNascimento);

    printf("Cargo: ");
    gets(Funcionario.cargo);
    fprintf(database_funcionarios, "Cargo: %s\n\n", Funcionario.cargo);

    printf("\nCadastro realizado com sucesso!\n\n");

    //FECHA O ARQUIVO
    fclose(database_funcionarios);

    //DEPOIS DE FAZER O CADASTRO O PROGRAMA ENCAMINHA O USUÁRIO PARA A SEÇÃO SE LOGIN
    login();

}

void login(void){

    //BRINDO O ARQUIVO "produtos.txt" SOMENTE PARA LEITURA
    database_funcionarios = fopen("arquivos/funcionarios.txt", "r");

    //VERIFICA SE O ARQUIVO FOI ABERTO COM SUCESSO
    if(database_funcionarios == NULL){
        printf("Erro na abertura do arquivo funcionarios.txt!\n\n");
        return 0;
    }

    char email[100], senha[10];

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    LOGIN \n\n");

    printf("E-mail: ");
    gets(email);

    printf("Senha: ");
    gets(senha);

    //FECHA O ARQUIVO
    fclose(database_funcionarios);

    printf("\n-----------------------------------------------------------------------------------------------------------\n");

    //DEPOIS DE FAZER O LOGIN O PROGRAMA ENCAMINHA O USUÁRIO PARA DENTRO SISTEMA
    menu();

}

void menu(void){

    printf("\n\t\t\t\t    OLÁ, SEJA BEM VINDO AO POWER SYSTEM!\n\n");

    int opcao, cont;

    //PROGRAM EXIBE O MENU ENQUANTO O USUÁRIO NÃO DIGITAR UM DOS 5 VALORES ABAIXO
    do{
        cont = 0;

        printf("1 - Cadastrar produto | 2 - Atualizar produto | 3 - Deletar produto | 4 - Estoque total | 5 - Logout\n\nO que você deseja fazer? ");
        scanf("%d%*c", &opcao);
        printf("\n");

        switch(opcao){
            case 1:
                cadastrarProduto();
                break;
            /*
            case 2:
                atualizarProduto();
                break;

            case 3:
                deletarProduto();
                break;
            */
            case 4:
                listarProdutos();
                break;

            case 5:
                iniciar();
                break;

            default:
                printf("Opção inválida! \n\n");
                cont++;
                printf("\n-----------------------------------------------------------------------------------------------------------\n");
                break;
        }
    }while(cont != 0);

}

void cadastrarProduto(void){

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t     CADASTRAR PRODUTO \n\n");


    /*================== VERIFICA SE O PRODUTO JÁ EXISTE ======================*/

    //FAZ A ABERTURA DO ARQUIVO "FUNCIONÁRIOS" PARA A LEITURA DE DADOS
    database_produtos = fopen("arquivos/produtos.txt", "r");

    //VERIFICA SE O ARQUIVO FOI ABERTO COM SUCESSO
    if(database_produtos == NULL){
        printf("Erro na abertura do arquivo produtos.txt!\n\n");
        return 0;
    }

    //VARIAVEIS QUE VÃO AUXLIAR NA VERIFICAÇÃO
    char buffer[100]; //GUARDA UMA LINHA DO ARQUIVO POR VEZ
    long int inicioLinha = 0; //INDICA ONDE COMEÇA A LINHA ANTES DE LER
    inicioLinha = ftell(database_produtos); //ftell guarda em inicioLinha quantos bytes tem desde o inicio do arquivo até o inicio da linha.

    printf("Nome do produto: ");
    gets(Produtos.nomeDoProduto);


    while (fscanf(database_produtos, "%s%*c", buffer) != EOF){
        //COMPARA AS STRINGS DO ARQUIVO COM O EMAIL DIGITADO
        if (strcmp(buffer, Produtos.nomeDoProduto) == 0){
            printf ("\nProduto já cadastrado!\n");
            printf("\n-----------------------------------------------------------------------------------------------------------\n");
            menu();
        }
        inicioLinha = ftell(database_produtos);
    }

    //FECHA O ARQUIVO
    fclose(database_produtos);


    /*================== PRODUTO AINDA NÃO FOI CADASTRADO, AGORA OS OUTROS DADOS SERÃO SOLICITADOS AO USUÁRIO E ARMAZENADO NO ARQUIVO ======================*/

    //FAZ A ABERTURA DO ARQUIVO "FUNCIONÁRIOS" PARA A INSERÇÃO DE DADOS
    database_produtos = fopen("arquivos/produtos.txt", "a");

    //VERIFICA SE O ARQUIVO FOI ABERTO COM SUCESSO
    if(database_produtos == NULL){
        printf("Erro na abertura do arquivo produtos.txt!\n\n");
        return 0;
    }

    fprintf(database_produtos, "Nome do produto: %s  ", Produtos.nomeDoProduto);

    printf("Categoria do produto: ");
    scanf("%[^\n]%*c", Produtos.categoriaDoProduto);
    fprintf(database_produtos, "Categoria do produto: %s  ", Produtos.categoriaDoProduto);

    printf("Quantidade: ");
    scanf("%f%*c", &Produtos.quantidade);
    fprintf(database_produtos, "Quantidade: %.2f  ", Produtos.quantidade);

    printf("Preço: ");
    scanf("%f%*c", &Produtos.preco);
    fprintf(database_produtos, "Preço: %.2f  ", Produtos.preco);

    printf("Data de vencimento: ");
    scanf("%[^\n]%*c", Produtos.dataDeVencimento);
    fprintf(database_produtos, "Data de vencimento: %s  ", Produtos.dataDeVencimento);

    printf("Data de cadastro: ");
    scanf("%[^\n]%*c", Produtos.dataDeCadastro);
    fprintf(database_produtos, "Data de cadastro: %s\n", Produtos.dataDeCadastro);

    printf("\nProduto cadastrado com sucesso!\n\n");
    printf("\n-----------------------------------------------------------------------------------------------------------\n");

    //FECHA O ARQUIVO
    fclose(database_produtos);

    //APÓS FAZER O CADASTRO O PROGRAMA MOSTRA O MENU
    menu();

}

void listarProdutos(void){

    //BRINDO O ARQUIVO "produtos.txt" SOMENTE PARA LEITURA
    database_produtos = fopen("arquivos/produtos.txt", "r");

    //VERIFICA SE O ARQUIVO FOI ABERTO COM SUCESSO
    if(database_produtos == NULL){
        printf("Erro na abertura do arquivo produtos.txt!\n\n");
        return 1;
    }

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t     PRODUTOS EM ESTOQUE \n\n");

    char dados[200];

    //FARÁ A LEITURA DE TODOS OS DADOS DO ARQUIVO
    if(fgets(dados, 200, database_produtos) == NULL){
        printf("Estoque vazio\n");
    }else{
        while(fgets(dados, 200, database_produtos) != NULL){
            printf("%s", dados);
        }
    }

    printf("\n-----------------------------------------------------------------------------------------------------------\n");

    //FECHAR ARQUIVO
    fclose(database_produtos);

    //APÓS FAZER O CADASTRO O PROGRAMA MOSTRA O MENU
    menu();

}

int main(void){

    setlocale(LC_ALL,"");
    iniciar();

    return 0;
}
