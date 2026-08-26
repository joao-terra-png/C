/*
Faça um programa que tenha uma função que dado um valor numérico de entrada, gere e imprima como
saída o número de linhas com pontos de exclamação, conforme exemplo abaixo (para n = 5):
!
!!
!!!
!!!!
!!!!!  
*/

#include <stdio.h>

void exclamation(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            printf("!");
        }
        printf("\n");
    }
}

int main(){
    int n;
    
    printf("Enter the number of lines: ");
    scanf("%d", &n);
    exclamation(n);
    return 0;
}