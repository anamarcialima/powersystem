#include "funcoes.h"

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
                printf("Opcao invalida! \n\n");
                cont++;
                printf("\n-----------------------------------------------------------------------------------------------------------\n");
                break;
        }
    }while(cont != 0);

}

int verificarData(Data verificando){

    if (verificando.ano >= 1900 && verificando.ano <= 9999){
        if (verificando.mes >= 1 && verificando.mes <= 12){
            if ((verificando.dia >= 1 && verificando.dia <= 31) && (verificando.mes == 1 || verificando.mes == 3 || verificando.mes == 5 || verificando.mes == 7 || verificando.mes == 8 || verificando.mes == 10 || verificando.mes == 12)){
            }else if ((verificando.dia >= 1 && verificando.dia <= 30) && (verificando.mes == 4 || verificando.mes == 6 || verificando.mes == 9 || verificando.mes == 11)){
                return 1;
            }else if ((verificando.dia >= 1 && verificando.dia <= 28) && (verificando.mes == 2)){
                return 1;
            }else if (verificando.dia == 29 && verificando.mes == 2 && (verificando.ano % 400 == 0 || (verificando.ano % 4 == 0 && verificando.ano % 100 != 0))){
                return 1;
            }else{
                printf("\nDia invalido! Digite novamente!\n\n");
                return 0;
            }
        }else{
            printf("Mes invalido! Digite novamente!\n\n");
            return 0;
        }
    }else{
        printf("Ano invalido! Digite novamente!\n\n");
        return 0;
    }
}

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

int cadastrarProduto(){

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
    }while(verificarData(Produtos.dataDeVencimento) == 0);
    
    do{
        printf("Data de Cadastro: ");
        scanf("%d/%d/%d%*c", &Produtos.dataDeCadastro.dia, &Produtos.dataDeCadastro.mes, &Produtos.dataDeCadastro.ano);
    }while(verificarData(Produtos.dataDeCadastro) == 0);

    fprintf(database_produtos, "Data de vencimento: %d/%d/%d ", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.ano);
    fprintf(database_produtos, "Data de cadastro: %d/%d/%d\n", Produtos.dataDeCadastro.dia,Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);
    
    fclose(database_produtos);
    return 0;
}

int listarProdutos(){
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
        return 0;
    }else{
        do{
            printf("ID: %d  %s", id, dados);
            ++id;
        }while(fgets(dados, 1001, database_produtos) != NULL);
    }
    
    fclose(database_produtos);
    return id - 1;
}

int removerProdutos(){

        int id = listarProdutos();

        database_produtos = fopen("arquivos/produtos.txt", "r+");
        FILE* new_databaseProdutos = fopen("arquivos/ProdutosRecent.txt","w");

        char buffer[1001];
        unsigned int linha_selecionada;

        printf("\nDigite o id do produto: ");
        scanf("%u%*c",&linha_selecionada);
        if(linha_selecionada > id || linha_selecionada <= 0){
            printf("id do produto invalido!\n");
            return 0;
        }
        unsigned int linha_atual = 1;

        while(fgets(buffer, 1001, database_produtos) != NULL){
            if(linha_atual != linha_selecionada){
                fputs(buffer, new_databaseProdutos);
            }
            linha_atual += 1;
        }

        fclose(database_produtos);
        fclose(new_databaseProdutos);

        remove("arquivos/produtos.txt");
        rename("arquivos/ProdutosRecent.txt", "arquivos/produtos.txt");
}

int atualizarProduto(){
        int id = listarProdutos();

        char buffer[1001];
        int linha_selecionada,linha_atual;

        printf("Digite o id do produto para atualizar: ");
        scanf("%d%*c",&linha_selecionada);
        
        if(linha_selecionada > id || linha_selecionada <= 0){
            printf("id do produto invalido!\n");
            return 0;
        }
        
        database_produtos = fopen("arquivos/produtos.txt", "r");
        FILE* new_databaseProdutos = fopen("arquivos/ProdutosRecent.txt","w");

        if(database_produtos == NULL || new_databaseProdutos == NULL){
            printf("\nUnable to open file.\n");
            printf("Please check whether file exists and you have read/write privilege.\n");
            return 0;
        }

        linha_atual = 0;
        while(fgets(buffer,1001,database_produtos) != NULL){
            linha_atual++;
            if(linha_atual == linha_selecionada){
                printf("Nome do produto: ");
                scanf("%[^\n]%*c", Produtos.nomeDoProduto);
                fprintf(new_databaseProdutos, "Nome do produto: %s ", Produtos.nomeDoProduto);

                printf("Categoria do produto: ");
                scanf("%[^\n]%*c", Produtos.categoriaDoProduto);
                fprintf(new_databaseProdutos, "Categoria do produto: %s ", Produtos.categoriaDoProduto);

                printf("Quantidade: ");
                scanf("%f%*c", &Produtos.quantidade);
                fprintf(new_databaseProdutos, "Quantidade: %.2f ", Produtos.quantidade);

                printf("Preco/unidade: ");
                scanf("%f%*c", &Produtos.preco);
                fprintf(new_databaseProdutos, "Preco: %.2f ", Produtos.preco);

                do{
                    printf("Data de vencimento: ");
                    scanf("%d/%d/%d%*c", &Produtos.dataDeVencimento.dia, &Produtos.dataDeVencimento.mes, &Produtos.dataDeVencimento.ano);
                }while(verificarData(Produtos.dataDeVencimento) == 0);
    
                do{
                    printf("Data de Cadastro: ");
                    scanf("%d/%d/%d%*c", &Produtos.dataDeCadastro.dia, &Produtos.dataDeCadastro.mes, &Produtos.dataDeCadastro.ano);
                }while(verificarData(Produtos.dataDeCadastro) == 0);

                fprintf(new_databaseProdutos, "Data de vencimento: %d/%d/%d ", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.ano);
                fprintf(new_databaseProdutos, "Data de cadastro: %d/%d/%d\n", Produtos.dataDeCadastro.dia,Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);
    
            }else{
                fputs(buffer,new_databaseProdutos);
            }
        }
        
        fclose(database_produtos);
        fclose(new_databaseProdutos);

        remove("arquivos/produtos.txt");
        rename("arquivos/ProdutosRecent.txt", "arquivos/produtos.txt");
        return 1;
}

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
