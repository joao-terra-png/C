/*
Faça um programa que leia um vetor de 10 posições e atribua valor 0 para todos os elementos que possuírem valores negativos.
*/
#include <stdio.h>

int main()
{
    int vector[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    for(int i = 0; i < 10; i++){
		printf("Enter value %d out of 10: ", i + 1);
		scanf("%d", &vector[i]);
	}
	
    for(int i = 0; i < 10; i++){
        if(vector[i] < 0){
            vector[i] = 0;
        }
        printf("vector[%d]: %d\n", i, vector[i]);
    }

    return 0;
}