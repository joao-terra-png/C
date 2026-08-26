// Faça um programa que leia três valores e apresente como resultado a soma dos quadrados dos valores lidos. 
#include <stdio.h>

int main()
{
    int i, j, k;
    
    printf("Digite o primeiro valor ");
    scanf("%d", &i);
    
    printf("Digite o segundo valor ");
    scanf("%d", &j);
    
    printf("Digite o terceiro valor ");
    scanf("%d", &k);
    
    int soma = i*i + j*j + k*k;
    printf("A soma dos quadrados dos seus valores é %d", soma);
    
}