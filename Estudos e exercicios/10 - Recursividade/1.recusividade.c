#include <stdio.h>

// recursividade
/*
Recursividade é o ato de uma função chamar a si mesma

OBS: é importante que a função recursiva tenha uma condição de parada

Linguagens funcionais não há for, necessário usar recursividade
*/

int fib(int n){
    if(n == 0){
        return 0;
    }
    
    if(n == 1){
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

int main(){

    int qty;

    printf("Enter the fibonacci sequence's size: ");
    scanf("%d", &qty);

    for(int i = 0; i < qty; i++){
        printf("%d ", fib(i+1));
    }

    return 0;
}