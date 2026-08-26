//2. Crie um programa que tenha uma struct chamada aluno contendo nome, número de matrícula e curso.
//Leia do usuário a informação de 5 alunos, armazene em um vetor desta estrutura e imprima os dados na tela. 

#include <stdio.h>
#include <string.h>

struct student{
    char name[100];
    int number;
    char course[100];
}students[5];

int main(){
    for(int i = 0; i < 5; i++){
        printf("Enter student %d name: ", (i+1));
        fgets(students[i].name, 100, stdin);

        printf("Enter student %d number: ", (i+1));
        scanf("%d", &students[i].number);
        getchar();

        printf("Enter student %d course: ", (i+1));
        fgets(students[i].course, 100, stdin);
    }

    for(int i = 0; i < 5; i++){        
        printf("\n=== Student %d ===\n", (i+1));
        printf("Name: %s\n", strtok(students[i].name, "\n"));
        printf("Number: %d\n", students[i].number);
        printf("Course: %s\n", strtok(students[i].course, "\n"));
    }
}