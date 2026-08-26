/*
Faça um programa que tenha uma função que receba um vetor de inteiros como parâmetro e retorne o maior valor. 
*/
#include <stdio.h>

int bigger_value(int vector[], int qty){
    int bigger = 0;
    
    for(int i = 0; i < qty; i++){
        if(i == 0){
            bigger = vector[i];
        }
        
        if(vector[i] > bigger){
            bigger = vector[i];
        }
    }
    
    return bigger;
}

int main(){
    int vector[10] = {1, 6, 8, 15, 24, 32, 47, 88, 4, 2};
    
    int bigger = bigger_value(vector, 10);
    printf("The biggest value of the vector is %d", bigger);

    return 0;
}