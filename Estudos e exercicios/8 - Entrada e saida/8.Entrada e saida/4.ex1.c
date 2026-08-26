/*
1. Faça um programa que:
a) Crie/abra um arquivo texto de nome “arq.txt”;
b) Permita que o usuário grave diversos caracteres neste arquivo, até que o usuário entre com o caractere
‘0’;
c) Feche o arquivo;
d) Abra e leia o arquivo, caractere por caractere, e escreva na tela todos os caracteres armazenados
*/

#include <stdio.h>

int main()
{
    FILE *arc1, *arc;
    char chara = 'A';
    
    arc1 = fopen("arq.txt", "wa");
    
    if(arc1){
        while(chara != '0'){
            printf("Enter a character or 0 to close: ");
            scanf(" %c", &chara); //precisa do espaço por causa do enter
            
            if(chara != '0'){
                fputc(chara, arc1);
            }
        }
    }else{
        printf("Couldn't create file");
    }
    
    fclose(arc1);
    arc1 = NULL;
    
    arc = fopen("arq.txt", "r");
    
    if(arc){
        while((chara = getc(arc)) != EOF){
            printf("%c\n", chara);
        }
    }else{
        printf("File not found");
    }
    
    fclose(arc);
    arc = NULL;
    
    return 0;
}