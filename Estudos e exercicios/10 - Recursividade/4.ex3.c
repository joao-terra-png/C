//3. Crie um programa que tenha uma função recursiva que receba um valor inteiro e converta este número para binário.
#include <stdio.h>

int binary(int);

int main(){
    int n;

    printf("Enter a number to convert to binary: ");
    scanf("%d", &n);

    printf("%d in binary is %d", n, binary(n));
}

int binary(int n){
    if(n == 0){
        return n;
    }else{
        return(n % 2 + 10 * binary(n / 2));
    }
}