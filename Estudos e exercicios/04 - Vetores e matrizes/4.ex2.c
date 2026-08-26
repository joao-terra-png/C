/*

Faça um programa que leia um vetor de 10 posições. Conte e mostre quantos valores pares ele possui.

*/
#include <stdio.h>

int main() {
    int vector[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int counter = 0;
	
	for(int i = 0; i < 10, i++){
		printf("Enter value %d out of 10: ", i + 1);
		scanf("%d", &vector[i]);
	}

    for(int i = 0; i < 10; i++){
        if(vector[i] % 2 == 0){
            counter++;
            printf("vector[%d]: %d\n", i, vector[i]);
        }
    }
	printf("%d even numbers found", counter);

    return 0;
}