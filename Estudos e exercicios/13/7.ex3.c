/*
3. Faça um programa que receba do usuário o tamanho de uma string e chame uma função para locar
dinamicamente essa string. Receba esta string do usuário. Por fim, apresente conteúdo dessa string sem
suas vogais.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int size;
    char *pointer;

    printf("Enter strings' size: ");
    scanf("%d", &size);
    getchar();

    pointer = (char*)malloc(sizeof(char) * size + 1);

    printf("Enter string: ");
    fgets(pointer, size + 1, stdin);

    for(int i = 0; i <= size; i++){
        if(*(pointer + i) != 'a' && *(pointer + i) != 'A' && *(pointer + i) != 'e' && *(pointer + i) != 'E' && *(pointer + i) != 'i' && *(pointer + i) != 'I' && *(pointer + i) != 'o' && *(pointer + i) != 'O' && *(pointer + i) != 'u' && *(pointer + i) != 'U'){
            printf("%c", *(pointer + i));
        }
    }

    return 0;
}