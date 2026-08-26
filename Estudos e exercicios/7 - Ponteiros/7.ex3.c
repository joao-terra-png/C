/*
Faça um programa que contenha um array de inteiros contendo 5 elementos. Utilizando apenas aritmética
de ponteiros, leia este array do teclado e imprima o dobro de cada valor lido.
*/

#include <stdio.h>

int main(){
    int values[5];
    
    for(int i = 0; i < 5; i++){
        printf("Enter value %d/5: ", i);
        scanf("%d", &values[i]);
    }
    
    for(int i = 0; i < 5; i++){
        printf("The double of %d is %d\n", *(values + i), *(values + i) * 2);
    }
    return 0;
}