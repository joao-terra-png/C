/*
2. Faça um programa aloque inicialmente um vetor com 3 inteiros, pergunte ao usuário quantos valores ele
quer informar, use REALLOC caso seja mais que 3 valores, leia e apresente os valores. 
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *pointer, vector[3], amount;

    pointer = (int*)malloc(sizeof(vector));

    printf("Enter amount of array's elements: ");
    scanf("%d", &amount);

    if(amount > 3){
        pointer = (int*)realloc(pointer, sizeof(int) * amount);
    }

    for(int i = 0; i < amount; i++){
        printf("Enter value %d of %d: ", i + 1, amount);
        scanf("%d", &pointer[i]);
    }

    for(int i = 0; i < amount; i++){
        printf("Array's value %d of %d: %d\n", i + 1, amount, pointer[i]);
    }

    free(pointer);
    pointer = NULL;

    return 0;
}