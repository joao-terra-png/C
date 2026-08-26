//UTILIZANDO WHILE - receba e some números inteiros até que o número de entrada seja 0 e apresente a soma no final
#include <stdio.h>

int main()
{
   int numero, soma = 0;
   
   printf("Informe um número: ");
   scanf("%d", &numero);
   
   while(numero != 0){
           printf("Informe um número: ");
        scanf("%d", &numero);
        
        soma = soma + numero;
    }
    
    printf("A soma é %d", soma);
    
    return 0;
}