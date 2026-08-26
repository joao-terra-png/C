//Faça um programa que determine e mostre os cinco primeiros múltiplos de 3, considerando números maiores que 0.
#include <stdio.h>

int main()
{
    int numero = 1;
    int contador = 0;
    
    printf("Apresentando os 5 primeiros múltiplos de 3: \n");
    while(contador < 5){
        if(numero % 3 == 0){
            printf("%d ", numero);
            contador++;
        }
            numero++;
    }

    return 0;
}