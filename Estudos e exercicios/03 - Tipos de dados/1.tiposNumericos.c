/*
Tipos numéricos
    - Inteiros;
    - Reais;
*/

#include <stdio.h>

int main()
{
    /*
    //Inteiros
    int numero_inteiro; //7, 9, 852145... %d
    
    //Reais
    float numero_quebrado; //3.5, 7.25, 10.25115... %f
    double float_longo; %g
    */
    
    float media, nota1, nota2;
    
    printf("Qual a primeira nota? ");
    scanf("%f", &nota1);
    
    printf("Qual a segunda nota? ");
    scanf("%f", &nota2);
    
    media = (nota1 + nota2) / 2;
    printf("Sua média é %.2f.", media);
    
    return 0;
}