/*
Faça um programa que contenha duas variáveis inteiras. Leia estas variáveis do teclado. Em seguida,
compare seus endereços e exiba o conteúdo do maior endereço.
*/

#include <stdio.h>

int main(){
    int inter1, inter2;
    
    printf("Enter inter1: ");
    scanf("%d", &inter1);
    
    printf("Enter inter2: ");
    scanf("%d", &inter2);
    
    printf("Adress inter1: %p\n", &inter1);
    printf("Adress inter2: %p\n", &inter2);
    
    if(&inter1 > &inter2){
        printf("Biggest adress: %d", inter1);
    }else{
        printf("Biggest adress: %d", inter2);
    }
    
    return 0;
}