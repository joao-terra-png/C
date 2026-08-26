/* Escreva um programa que declare um inteiro, inicialize-o com 0, incremente-o de 100 em 100, imprimindo
seu valor na tela, até que seu valor seja 100000 (cem mil). */
#include <stdio.h>

int main()
{
    int i = 0;
    
    do{
        printf("%d\n", i);
        i++;
    }while(i <= 100000);
    
    return 0;
}