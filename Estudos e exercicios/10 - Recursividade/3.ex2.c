//2. Crie um programa que tenha uma função recursiva que calcule e retorne o fatorial de um número inteiro N
#include <stdio.h>

int fat(int);

int main(){
    
    int n;

    printf("Enter the factorial number: ");
    scanf("%d", &n);

    printf("The value of the factorial is: %d", fat(n));

    return 0;
}

int fat(n){
    if(n <= 1){
        return n;
    }

    return n * fat(n - 1);
}