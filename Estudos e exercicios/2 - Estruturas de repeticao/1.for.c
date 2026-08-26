//UTILIZANDO FOR - receba e some 5 números inteiros e apresente a soma no final
#include <stdio.h>

int main()
{
    int numero, soma = 0;
    
    //para o int i inicando em 0; enquanto i < 5; incrementa o i em 1;
    //inicialização, critério de parada. forma de incremento
    for(int i = 0; i < 5; i++){
        printf("Informe um número: ");
        scanf("%d", &numero);
        
        soma = soma + numero;
    }
    
    printf("A soma é %d", soma);
    
    return 0;
}