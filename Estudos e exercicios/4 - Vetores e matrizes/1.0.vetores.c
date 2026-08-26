/*
VETORES

array uni-dimensional
    char nome[50];
    
*/

#include <stdio.h>

int main()
{
    //vetores e strings
    // "asdojasdk"
    char nome[50];
    
    printf("Qual o seu nome? ");
    gets(nome);
    printf("Olá %s\n", nome);
    
    //vetores e caracteres
    char letras[26];
    // 'a'
    int contador = 0;
    for(int i = 97; i <= 122; i++){
        letras[contador] = i;
        contador = contador + 1;
    }
    //Imprimindo as letras e seus valores em decimal
    for(int i =0; i < 26; i++){
        printf("%d == %c\n", letras[i], letras[i]);
    }
    
    //char = 'l';
    //char a = 97
    
    //vetores de inteiros
    int numeros[10];
    
    //vetores e reais
    float valores[5];
    
    return 0;
}