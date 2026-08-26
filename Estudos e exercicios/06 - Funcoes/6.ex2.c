/*
Faça um programa que tenha uma função que, dado um caractere qualquer de entrada, retorne o mesmo caractere sempre em maiúsculo. 
*/
#include <stdio.h>

char get_upper(char character){
    char upper = (int)character - 32;
   
    return character;
}

int main(){
    char character = 'a';
    /*
    printf("Enter a character: ");
    scanf("%c", &character);
    */
    
    char upper = get_upper(character);
    printf("The upper case of your character is: %c", upper);
    
    return 0;
}