/*
3. Faça um programa que receba do usuário o nome de um arquivo texto e um caractere. Mostre na tela
quantas vezes aquele caractere aparece dentro do arquivo.
*/

#include <stdio.h>

int main()
{
    FILE *arc;
    char archive_name[12];
    char chara = 0;
    int chara_counter = 0;
    
    printf("Enter the name of the archive: ");
    fgets(archive_name, 12, stdin);
    
    printf("Enter the character you wish to count: ");
    scanf(" %c", &chara);
    
    arc = fopen(archive_name, "r");
    if(arc){
        for(char c = getc(arc); c != EOF; c = getc(arc)){
            if(c == chara){
                chara_counter = chara_counter + 1;
            }
        }
        printf("The character %c was found %d in %s", chara, chara_counter, archive_name);
    }else{
        printf("Couldn't open file.");
    }
    
    fclose(archive_name);
    return 0;
}