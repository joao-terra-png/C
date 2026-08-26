#include <stdio.h>

int main()
{
    FILE *arc;
    char c;
    
    arc = fopen("archive.txt", "r"); //leitura
    
    if(arc){
        while((c = getc(arc)) != EOF){ //End Of File
            printf("%c", c);
        }
    }else{
        printf("File not found.");
    }
    
    fclose(arc);
    return 0;
}