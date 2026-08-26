/*
2. Faça um programa que receba do usuário o nome de um arquivo texto e mostre na tela quantas linhas
este arquivo possui. 
*/

#include <stdio.h>

int main()
{
    FILE *arc;
    char archive_name[12];
    int line_counter = 0;
    
    printf("Enter the name of the archive: ");
    fgets(archive_name, 12, stdin);
    
    arc = fopen(archive_name, "r");
    if(arc){
        for(char c = getc(arc); c != EOF; c = getc(arc)){
            if(c == '\n'){
                line_counter = line_counter + 1;
            }
        }
        printf("The archive %s has %d lines.", archive_name, line_counter);
    }else{
        printf("Couldn't open file.");
    }
    
    fclose(archive_name);
    return 0;
}