#include<stdio.h>
#include <locale.h>
#include <string.h>


int main(void){
    setlocale(LC_ALL, "portuguese-brazilian");

    //abrimos o arquivo e comprovamos se foi aberto
    FILE *file = fopen("prova.txt", "r+");
    if( !file ){
        perror("Erro: ");
        getchar();
        return 1;
    }

    //variaveis que vamos usar
    char buffer[1204]; //Buffer que vai guardar uma linha do arquivo por vez
    char pesquisa[100] = "linha2";  //O que pretendo buscar no arquivo
    long int inicioLinha = 0;        //variavel que vai indicar onde começa a linha antes de ler

    inicioLinha = ftell( file ); //preste atenção. Antes de ler uma linha devemos anotar o primeiro caractere da linha, isso é o que faz essa linha, ftell guarda em inicioLinha quantos bytes tem desde o inicio do arquivo até o inicio da linha.
    while ( fscanf(file, "%s%*c", buffer) != EOF ){ // Como o programa começa na linha zero inicioLinha começa sendo 0, agora fscanf le a linha e o que foi lido vai parar no buffer. O fscanf para na seguinte linha antes de uma nova leitura, porém devemos comprovar primeiro se o que tem na linha é o que andamos buscando.

        //Comparamos o que foi lido com o objetovo da pesquisa
        if ( strcmp( buffer, pesquisa ) == 0  ){
            // Se entramos aqui é por que buffer é igual a pesquisa
            printf ("Encontrado!\n");

            //Agora nesse ponto devemos fazer o que queremos... borrar o conteudo.
            printf("No buffer tem: %d letras.\n", strlen(buffer)); //Para borrar o conteudo devemos primeiro saber quantas letras tem
            int TAM = strlen(buffer); //guardamos o tamanho em uma variavel.

            //Agora preste atenção novamente devemos voltar ao inicio da linha para poder borrar TAM letras. Para isso usamos fseek
            fseek(file/*no arquivo...*/, inicioLinha/*queremos ir ao inicio da linha...*/, SEEK_SET/*e queremos fazer desde o inicio para o fim*/); // fseek bota o ponteiro X bytes desde o inicio do arquivo e para direitinho ao inicio da linha.


            //Agora escrevemos TAM bytes com espaços(borrado! A linha fica em branco)
            int i;
            for (i=0; i<TAM ;i++ ) {
                putc((int)' ', file);
            }

            //TADAH!!!
            //usamos break para sair
            break;
        }

        inicioLinha = ftell( file );  //Se não encontrou necessotamos continuar lendo linhas... então anotamos outravez o inicio da seguinte linha antes de começar tudo de novo.
    }

    fclose(file);
}
