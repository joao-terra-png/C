/*
1. Crie um programa que:
a) Aloque dinamicamente um array de 5 números inteiros;
b) Peça para o usuário informar os 5 números no espaço alocado;
c) Mostre na tela os 5 valores;
d) Libere a memória alocada; 
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *pointer, vector[5];

    pointer = (int*)malloc(sizeof(vector));
    
    for(int i = 0; i < 5; i++){
        printf("Enter %d array's value: ", i + 1);
        scanf("%d", &pointer[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("Array's %d value: %d\n", i + 1, pointer[i]);
    }

    free(pointer);
    pointer = NULL;

    return 0;
}