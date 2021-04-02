#include "funcoes.h"

int opc = 0;

int iniciar(){

    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t POWER SYSTEM \n");
    printf("-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t OBS: O programa a seguir nao reconhece acentuacao! \n\n");

    int opcao, cont;

    //EQUANDO O USU�RIO N�O DIGITAR UMAS DAS 3 OP��ES, O PROGRAMA IR� MOSTRAR O MENU E SOLICITAR UMA OP��O V�LIDA
    do{
        cont = 0;

        printf("1 - Login | 2 - Fazer cadastro | 3 - Sair do programa \n\nO que voc� deseja fazer? ");
        scanf("%d%*c", &opcao);

        if(opcao == 1){
            login();
        }else if(opcao == 2){
            cadastrarFuncionario();
        }else if(opcao == 3){
            return 0;
        }else{
            printf("\nOp��o inv�lida!\n\n");
            printf("-----------------------------------------------------------------------------------------------------------\n\n");
            cont++;
        }
    }while(cont != 0);

}

int menu(){

    printf("\n\t\t\t\t    OL�, SEJA BEM VINDO AO POWER SYSTEM!\n\n");

    int opcao, cont;

    //PROGRAM EXIBE O MENU ENQUANTO O USU�RIO N�O DIGITAR UM DOS 5 VALORES ABAIXO
    do{
        cont = 0;

        printf("1 - Cadastrar produto | 2 - Atualizar produto | 3 - Deletar produto | 4 - Estoque total | 5 - Logout\n\nO que voc� deseja fazer? ");
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
            */
            case 3:
                removerProdutos();
                break;
            
            case 4:
                listarProdutos();
                break;

            case 5:
                iniciar();
                break;

            default:
                printf("Op��o inv�lida! \n\n");
                cont++;
                printf("\n-----------------------------------------------------------------------------------------------------------\n");
                break;
        }
    }while(cont != 0);

}

int cadastrarFuncionario(void){

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t FAZER CADASTRO \n\n");


    /*================== VERIFICAR SE O EMAIL J� EXISTE ======================*/

    //FAZ A ABERTURA DO ARQUIVO funcionarios.txt PARA A LEITURA DE DADOS
    database_funcionarios = fopen("arquivos/funcionarios.txt", "a+");

    //VERIFICA SE O ARQUIVO FOI ABERTO COM SUCESSO
    if(database_funcionarios == NULL){
        printf("Erro na abertura do arquivo fucionarios.txt!\n\n");
        return 0;
    }

    //VARIAVEIS QUE V�O AUXLIAR NA VERIFICA��O
    char buffer[100]; //GUARDA UMA LINHA DO ARQUIVO POR VEZ
    long int inicioLinha = 0; //INDICA ONDE COME�A A LINHA ANTES DE LER
    inicioLinha = ftell(database_funcionarios); //ftell guarda em inicioLinha quantos bytes tem desde o inicio do arquivo at� o inicio da linha.

    printf("E-mail: ");
    fgets(Funcionario.email,sizeof(Funcionario.email),stdin);


    while(fscanf(database_funcionarios, "%s%*c", buffer) != EOF){ //LER A LINHA E ARMAZENA NO BUFFER
        //COMPARA AS STRINGS DA LINHA COM O EMAIL DIGITADO
        if (strcmp(buffer, Funcionario.email) == 0){
            printf ("\nEmail indispon�vel!\n");
            printf("\n-----------------------------------------------------------------------------------------------------------\n");
            return 0;
        }
        inicioLinha = ftell(database_funcionarios);
    }

    //FECHA O ARQUIVO QUE FOI ABERTO EM FORMA DE LEITURA
    fclose(database_funcionarios);


    /*================== VISTO EMAIL N�O EXISTE NO ARQUIVO, AGORA OS OUTROS DADOS SER�O SOLICITADOS AO USU�RIO E ARMAZENADO NO ARQUIVO ======================*/

    //FAZ A ABERTURA DO ARQUIVO "FUNCION�RIOS" PARA A INSER��O DE DADOS
    database_funcionarios = fopen("arquivos/funcionarios.txt", "a");

    //VERIFICA SE O ARQUIVO FOI ABERTO COM SUCESSO
    if(database_funcionarios == NULL){
        printf("Erro na abertura do arquivo fucionarios.txt!\n\n");
        return 1;
    }

    fprintf(database_funcionarios, "E-mail: %s  ", Funcionario.email);

    printf("Senha: ");
    fgets(Funcionario.senha,sizeof(Funcionario.senha),stdin);
    fprintf(database_funcionarios, "Senha: %s  ", Funcionario.senha);

    printf("Nome: ");
    fgets(Funcionario.nomeDoFuncionario,sizeof(Funcionario.nomeDoFuncionario),stdin);
    fprintf(database_funcionarios, "Nome: %s  ", Funcionario.nomeDoFuncionario); //ARMAZENAR O DADO NO ARQUIVO

    printf("Telefone: ");
    fgets(Funcionario.telefone,sizeof(Funcionario.telefone),stdin);
    fprintf(database_funcionarios, "Telefone: %s  ", Funcionario.telefone);

    do{
        printf("Data de nascimento: ");
        scanf("%d/%d/%d", &Funcionario.dataNascimento.dia, &Funcionario.dataNascimento.mes, &Funcionario.dataNascimento.ano);
        opc = verificarData(Funcionario.dataNascimento.dia, Funcionario.dataNascimento.mes,Funcionario.dataNascimento.ano);
    }while(opc != 1);
    
    fprintf(database_funcionarios, "Data de nascimento: %d/%d/%d  ", Funcionario.dataNascimento.dia, Funcionario.dataNascimento.mes,Funcionario.dataNascimento.ano);
    
    printf("Cargo: ");
    fgets(Funcionario.cargo,sizeof(Funcionario.cargo),stdin);
    fprintf(database_funcionarios, "Cargo: %s\n\n", Funcionario.cargo);

    printf("\nCadastro realizado com sucesso!\n\n");

    //FECHA O ARQUIVO
    fclose(database_funcionarios);

    //DEPOIS DE FAZER O CADASTRO O PROGRAMA ENCAMINHA O USU�RIO PARA A SE��O SE LOGIN
    login();

}

int login(void){

    //BRINDO O ARQUIVO "produtos.txt" SOMENTE PARA LEITURA
    database_funcionarios = fopen("arquivos/funcionarios.txt", "r+");

    //VERIFICA SE O ARQUIVO FOI ABERTO COM SUCESSO
    if(database_funcionarios == NULL){
        printf("Erro na abertura do arquivo funcionarios.txt!\n\n");
        return 0;
    }

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\t    LOGIN \n\n");




    //VARIAVEIS QUE V�O AUXLIAR NA VERIFICA��O
    char buffer[100]; //GUARDA UMA LINHA DO ARQUIVO POR VEZ
    long int inicioLinha = 0; //INDICA ONDE COME�A A LINHA ANTES DE LER
    inicioLinha = ftell(database_funcionarios); //ftell guarda em inicioLinha quantos bytes tem desde o inicio do arquivo at� o inicio da linha.

    char email[100], senha[10];

    printf("E-mail: ");
    fgets(email, 100, stdin);

    printf("Senha: ");
    fgets(senha, 100, stdin);

    menu();

}

int cadastrarProduto(void){

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t     CADASTRAR PRODUTO \n\n");


    /*================== VERIFICA SE O PRODUTO J� EXISTE ======================*/

    //FAZ A ABERTURA DO ARQUIVO "FUNCION�RIOS" PARA A LEITURA DE DADOS
    database_produtos = fopen("arquivos/produtos.txt", "a+");

    //VERIFICA SE O ARQUIVO FOI ABERTO COM SUCESSO
    if(database_produtos == NULL){
        printf("Erro na abertura do arquivo produtos.txt!\n\n");
        return 0;
    }

    //VARIAVEIS QUE V�O AUXLIAR NA VERIFICA��O
    char buffer[100]; //GUARDA UMA LINHA DO ARQUIVO POR VEZ
    long int inicioLinha = 0; //INDICA ONDE COME�A A LINHA ANTES DE LER
    inicioLinha = ftell(database_produtos); //ftell guarda em inicioLinha quantos bytes tem desde o inicio do arquivo at� o inicio da linha.

    printf("Nome do produto: ");
    fgets(Produtos.nomeDoProduto,sizeof(Produtos.nomeDoProduto),stdin);


    while (fscanf(database_produtos, "%s%*c", buffer) != EOF){
        //COMPARA AS STRINGS DO ARQUIVO COM O EMAIL DIGITADO
        if (strcmp(buffer, Produtos.nomeDoProduto) == 0){
            printf ("\nProduto j� cadastrado!\n");
            printf("\n-----------------------------------------------------------------------------------------------------------\n");
            menu();
        }
        inicioLinha = ftell(database_produtos);
    }

    //FECHA O ARQUIVO
    fclose(database_produtos);


    /*================== PRODUTO AINDA N�O FOI CADASTRADO, AGORA OS OUTROS DADOS SER�O SOLICITADOS AO USU�RIO E ARMAZENADO NO ARQUIVO ======================*/

    //FAZ A ABERTURA DO ARQUIVO "FUNCION�RIOS" PARA A INSER��O DE DADOS
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

    printf("Pre�o: ");
    scanf("%f%*c", &Produtos.preco);
    fprintf(database_produtos, "Pre�o: %.2f  ", Produtos.preco);
    
    do{    
        printf("Data de vencimento: ");
        scanf("%d/%d/%d", &Produtos.dataDeVencimento.dia, &Produtos.dataDeVencimento.mes, &Produtos.dataDeVencimento.ano);
        opc = verificarData(Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.ano);
    }while(opc != 1);

    fprintf(database_produtos, "Data de vencimento: %d/%d/%d  ", Produtos.dataDeVencimento.dia, Produtos.dataDeVencimento.mes,Produtos.dataDeVencimento.dia);

    do{    
        printf("Data de Cadastro: ");
        scanf("%d/%d/%d", &Produtos.dataDeCadastro.dia, &Produtos.dataDeCadastro.mes, &Produtos.dataDeCadastro.ano);
        opc = verificarData(Produtos.dataDeCadastro.dia, Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);
    }while(opc != 1);

    fprintf(database_produtos, "Data de cadastro: %d/%d/%d\n", Produtos.dataDeCadastro.dia,Produtos.dataDeCadastro.mes,Produtos.dataDeCadastro.ano);

    printf("\nProduto cadastrado com sucesso!\n\n");
    printf("\n-----------------------------------------------------------------------------------------------------------\n");

    //FECHA O ARQUIVO
    fclose(database_produtos);

    //AP�S FAZER O CADASTRO O PROGRAMA MOSTRA O MENU
    menu();

}

int listarProdutos(void){

    //BRINDO O ARQUIVO "produtos.txt" SOMENTE PARA LEITURA
    database_produtos = fopen("arquivos/produtos.txt", "a+");

    //VERIFICA SE O ARQUIVO FOI ABERTO COM SUCESSO
    if(database_produtos == NULL){
        printf("Erro na abertura do arquivo produtos.txt!\n\n");
        return 1;
    }

    printf("\n-----------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t     PRODUTOS EM ESTOQUE \n\n");

    char dados[200];

    //FAR� A LEITURA DE TODOS OS DADOS DO ARQUIVO
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

    //AP�S FAZER O CADASTRO O PROGRAMA MOSTRA O MENU
    menu();

}

int removerProdutos(){
    database_produtos = fopen("arquivos/produtos.txt", "r");
    FILE* new_databaseProdutos = fopen("arquivos/ProdutosRecent.txt","w");
    
    char texto[1001];
    unsigned int linha_selecionada;

    printf("Digite o id do produto: ");
    scanf("%u",&linha_selecionada);

    unsigned int linha_atual = 1;

    while(fgets(texto, 1001, database_produtos) != NULL){
        if(linha_atual != linha_selecionada){
            fputs(texto, new_databaseProdutos);
        }
        memset(texto, 0, sizeof(texto));
        linha_atual += 1;
    }

    fclose(database_produtos);
    fclose(new_databaseProdutos);

    remove("arquivos/produtos.txt");
    rename("arquivos/ProdutosRecent.txt", "arquivos/produtos.txt");

    return 0;
}

int verificarData(int dia, int mes, int ano){
    if (ano >= 1900 && ano <= 9999)
    {
        //check month
        if (mes >= 1 && mes <= 12)
        {
            //check days
            if ((dia >= 1 && dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12))
                return 1;
            else if ((dia >= 1 && dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11))
                return 1;
            else if ((dia >= 1 && dia <= 28) && (mes == 2))
                return 1;
            else if (dia == 29 && mes == 2 && (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0)))
                return 1;
            else
                printf("Dia invalido! Digite novamente!\n");
                return 0;
        }
        else
        {
            printf("Mes invalido! Digite novamente!\n");
            return 0;
        }
    }
    else
    {
        printf("Ano invalido! Digite novamente!\n");
        return 0;
    }
}
