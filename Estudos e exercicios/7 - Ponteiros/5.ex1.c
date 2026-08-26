/*
Faça um programa que declare um inteiro, um real e um char, e ponteiros para inteiro, real e char. Associe
as variáveis aos ponteiros (use &). Modifique os valores de cada variável usando os ponteiros. Imprima os
valores das variáveis antes e após a modificação. 
*/

#include <stdio.h>

int main(){
    // Declarando variáveis
    int inter = 5;
    float real = 3.14;
    char chara = 'a';

    // Declarando ponteiros
    int* pInter;
    float* pReal;
    char* pChara;

    // Associando ponteiros às variáveis
    pInter = &inter;
    pReal = &real;
    pChara = &chara;

    // Imprimindo valores antes da modificação
    printf("Values before change:\n");
    printf("inter = %d\n", inter);
    printf("real = %.2f\n", real);
    printf("char = %c\n\n", chara);

    // Modificando os valores através dos ponteiros
    *pInter = 10;
    *pReal = 14.3;
    *pChara = 'b';

    // Imprimindo valores depois da modificação
    printf("Values after change:\n");
    printf("inter = %d\n", inter);
    printf("real = %.2f\n", real);
    printf("char = %c\n\n", chara);

    return 0;
}