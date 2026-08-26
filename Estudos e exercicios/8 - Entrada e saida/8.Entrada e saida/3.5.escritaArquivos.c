#include <stdio.h>

int main()
{
    FILE *arc;
    char fruit[10];
    
    arc = fopen("fruits.txt", "a");//adição
    
    if(arc){
        printf("Enter a fruit, or 0 to close: \n");
        fgets(fruit, 10, stdin); //stdin = standard input = teclado
        while(fruit[0] != '0'){
            fputs(fruit, arc);
            printf("Enter a fruit, or 0 to close: \n");
            fgets(fruit, 10, stdin);
        }
    }else{
        printf("Couldn't create file.");
    }
    
    fclose(arc);
    
    return 0;
}