#include "arquivosCabecalho/data.h"
#include "arquivosCabecalho/funcionario.h"
#include "arquivosCabecalho/produto.h"

int validarData(Data validando){

    if (validando.ano >= 1900 && validando.ano <= 9999){
        if (validando.mes >= 1 && validando.mes <= 12){
            if ((validando.dia >= 1 && validando.dia <= 31) && (validando.mes == 1 || validando.mes == 3 || validando.mes == 5 || validando.mes == 7 || validando.mes == 8 || validando.mes == 10 || validando.mes == 12)){
            }else if ((validando.dia >= 1 && validando.dia <= 30) && (validando.mes == 4 || validando.mes == 6 || validando.mes == 9 || validando.mes == 11)){
                return 1;
            }else if ((validando.dia >= 1 && validando.dia <= 28) && (validando.mes == 2)){
                return 1;
            }else if (validando.dia == 29 && validando.mes == 2 && (validando.ano % 400 == 0 || (validando.ano % 4 == 0 && validando.ano % 100 != 0))){
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
