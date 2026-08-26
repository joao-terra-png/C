#include <stdio.h>

//typedef -- redefinir tipos

int main(){
    typedef float nota;

    //declarando variaveis
    nota prova1 = 7.0; //dado do tipo float mas apelidado de NOTA
    nota prova2 = 6.0;

    nota soma = prova1 + prova2;

    printf("A soma das notas eh %f", soma);

    return 0;
}