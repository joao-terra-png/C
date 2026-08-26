//1. Crie um programa que tenha uma função recursiva que receba um número inteiro positivo N e calcula e apresente o somatório dos números de 1 a N. 
#include <stdio.h>

int sum(int);

int main(){

    int n = 5;

    printf("The sum of the first %d numbers is %d", n, sum(n));

    return 0;
}

int sum(int n){
    if(n <= 1){
        return n;
    }
    return n + sum(n - 1);
}