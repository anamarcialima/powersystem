#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void limpar(){
#ifdef _linux_
    system("clear");
#elif _WIN32
    system("cls");
#else

#endif
}