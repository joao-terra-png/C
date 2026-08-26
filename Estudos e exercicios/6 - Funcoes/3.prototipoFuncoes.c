#include <stdio.h>

//Protóripo de função
/*
 * Assinatura das funções
 * 
 * - tipo de retorno
 * - nome
 * - parâmetros de entrada (opcional)
 */
int sum(int num1, int num2); //PF

int main(){ 
    int n1, n2, ret;
    
    printf("Enter first number: ");
    scanf("%d", &n1);
    
    printf("Enter second number: ");
    scanf("%d", &n2);
    
    ret = sum(n1, n1);
    
    printf("The sum of %d with %d is: %d\n", n1, n2, ret);
    return 0; 
}

int sum(int num1, int num2){
    return num1 + num2;
}