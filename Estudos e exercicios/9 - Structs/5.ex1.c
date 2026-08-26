//1. Crie um programa que leia o nome, a idade e o endereço de uma pessoa e armazene os dados em uma struct. 

#include <stdio.h>
#include <string.h>

struct st_register{
    char name[100];
    int age;
    char adress[200];    
}user;

int main(){

    printf("Insert your name: ");
    fgets(user.name, 100, stdin);

    printf("Inser your age: ");
    scanf("%d", &user.age);
    getchar();

    printf("Insert your adress: ");
    fgets(user.adress, 200, stdin);

    printf("\nUser's name: %s\n", strtok(user.name, "\n"));
    printf("User's age: %d\n", user.age);
    printf("User's adress: %s\n", strtok(user.adress, "\n"));

    return 0;
}