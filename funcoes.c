#include "funcoes.h"

int login(void){

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

void iniciar(){

    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t POWER SYSTEM \n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t OBS: O programa a seguir nao reconhece acentuacao! \n\n");

    int opcao, cont;

   do{
        cont = 0;

        printf("1 - Login | 2 - Fazer cadastro | 3 - Sair do programa \n\nO que você deseja fazer? ");
        scanf("%d%*c", &opcao);

        switch(opcao){
            case 1:
                login();
                system("clear");
                break;
            case 2:
                system("clear");
                cadastrarFuncionario();
                break;
            case 3:
                system("clear");
                exit(0);
                break;
            default:
                printf("\nOpcao invalida!\n\n");
                printf("-----------------------------------------------------------------------------------------------------------\n\n");
                cont++;
        }
    }while(cont != 0);

}

void menu(){
    system("clear");
    printf("-----------------------------------------------------------------------------------------------------------\n\n");
    printf("\n\t\t\t\t    OLA, SEJA BEM VINDO AO POWER SYSTEM!\n\n");

    int opcao, cont;

    do{
        cont = 0;

        printf("1 - Cadastrar produto | 2 - Atualizar produto | 3 - Deletar produto | 4 - Estoque total | 5 - Logout\n\nO que voce deseja fazer? ");
        scanf("%d%*c", &opcao);
        printf("\n");
        system("clear");
        switch(opcao){
            case 1:
                printf("\n-----------------------------------------------------------------------------------------------------------\n");
                printf("\t\t\t\t\t     CADASTRAR PRODUTO \n\n");
                if(cadastrarProduto() == 0){
                    printf("Produto cadastrado com sucesso!\n");
                }else{
                    printf("Erro ao cadastrar o produto");
                }
                menu();
                break;
            case 2:
                system("clear");
                atualizarProduto();
                menu();
                break;
            case 3:
                system("clear");
                removerProdutos();
                menu();
                break;

            case 4:
                system("clear");
                listarProdutos();
                menu();
                break;

            case 5:
                system("clear");
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

int verificarData(int dia, int mes, int ano){

    if (ano >= 1900 && ano <= 9999){
        if (mes >= 1 && mes <= 12){
            if ((dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)){
                return 1;
            }else if ((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)){
                return 1;
            }else if ((dia >= 1 && dia <= 28) && (mes == 2)){
                return 1;
            }else if (dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0))){
                return 1;
            }else{
                printf("\nDia invalido! Digite novamente!\n");
                return 0;
            }
        }else{
            printf("Mes invalido! Digite novamente!\n");
            return 0;
        }
    }else{
        printf("Ano invalido! Digite novamente!\n");
        return 0;
    }
}

int cadastrarFuncionario(void){

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
        opc = verificarData(Funcionario.dataNascimento.dia, Funcionario.dataNascimento.mes,Funcionario.dataNascimento.ano);
    }while(opc != 1);

    fprintf(database_funcionarios, "Data de nascimento: %d/%d/%d  ", Funcionario.dataNascimento.dia, Funcionario.dataNascimento.mes,Funcionario.dataNascimento.ano);


    printf("Cargo: ");
    scanf("%[^\n]%*c", Funcionario.cargo);
    fprintf(database_funcionarios, "Cargo: %s\n\n", Funcionario.cargo);

    printf("\nCadastro realizado com sucesso!\n\n");

    fclose(database_funcionarios);

    login();

}

int cadastrarProduto(void){

    database_produtos = fopen("arquivos/produtos.txt", "a");

    if(database_produtos == NULL){
        printf("Erro na abertura do arquivo produtos.txt!\n\n");
        return 1;
    }
    
    printf("Nome do produto: ");
    scanf("%[^\n]%*c", Produtos.nomeDoProduto);
    fprintf(database_produtos, "Nome do produto: %s ", Produtos.nomeDoProduto);

    printf("Categoria do produto: ");
    scanf("%[^\n]%*c", Produtos.categoriaDoProduto);
    fprintf(database_produtos, "Categoria do produto: %s ", Produtos.categoriaDoProduto);

    printf("Quantidade: ");
    scanf("%f%*c", &Produtos.quantidade);
    fprintf(database_produtos, "Quantidade: %.2f ", Produtos.quantidade);

    printf("Preco/unidade: ");
    scanf("%f%*c", &Produtos.preco);
    fprintf(database_produtos, "Preco: %.2f ", Produtos.preco);

    do{
        printf("Data de vencimento: ");
        scanf("%d/%d/%d%*c", &Produtos.dataDeVencimento.dia, &Produtos.dataDeVencimento.mes, &Produtos.dataDeVencimento.ano);
        opc = verificarData(Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.ano);
    }while(opc != 1);

    fprintf(database_produtos, "Data de vencimento: %d/%d/%d ", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.dia);

    do{
        printf("Data de Cadastro: ");
        scanf("%d/%d/%d%*c", &Produtos.dataDeCadastro.dia, &Produtos.dataDeCadastro.mes, &Produtos.dataDeCadastro.ano);
        opc = verificarData(Produtos.dataDeCadastro.dia, Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);
    }while(opc != 1);

    fprintf(database_produtos, "Data de cadastro: %d/%d/%d\n", Produtos.dataDeCadastro.dia,Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);

    fclose(database_produtos);
    return 0;
}

int listarProdutos(void){

    database_produtos = fopen("arquivos/produtos.txt", "a+");

    if(database_produtos == NULL){
        printf("Erro na abertura do arquivo produtos.txt!\n\n");
        return 1;
    }

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t     PRODUTOS EM ESTOQUE \n\n");

    int id = 1; char dados[1001];

    if(fgets(dados, 1001, database_produtos) == NULL){
        printf("Estoque vazio\n\n");
        menu();
    }else{
        do{
            printf("Codigo do produto: %d  %s", id, dados);
            ++id;
        }while(fgets(dados, 1001, database_produtos) != NULL);
    }
    
    fclose(database_produtos);
    return id - 1;
}

int removerProdutos(){

        int id = listarProdutos();
        printf("o ID total -> %d\n",id);

        database_produtos = fopen("arquivos/produtos.txt", "r");
        FILE* new_databaseProdutos = fopen("arquivos/ProdutosRecent.txt","w");

        char texto[1001];
        unsigned int linha_selecionada;

        printf("\nDigite o id do produto: ");
        scanf("%u%*c",&linha_selecionada);
        if(linha_selecionada > id || linha_selecionada <= 0){
            printf("produto invalido!\n");
            return 0;
        }
        unsigned int linha_atual = 1;

        while(fgets(texto, 1001, database_produtos) != NULL){
            if(linha_atual != linha_selecionada){
                fputs(texto, new_databaseProdutos);
            }
            linha_atual += 1;
        }

        fclose(database_produtos);
        fclose(new_databaseProdutos);

        remove("arquivos/produtos.txt");
        rename("arquivos/ProdutosRecent.txt", "arquivos/produtos.txt");
}

void atualizarProduto(){
    removerProdutos();
    system("clear");
    if( cadastrarProduto() == 0){
        printf("Produto atualizado com sucesso!\n");
    }else{
        printf("Erro ao atualizar o produto\n");
    }
}