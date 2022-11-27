#include "arquivosCabecalho/data.h"
#include "arquivosCabecalho/funcionario.h"
#include "arquivosCabecalho/produto.h"

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
