#include <stdio.h>

int main()
{
    FILE *arc;
    char name[100], *result;
    
    arc = fopen("archive.txt", "r"); 
    
    if(arc){
        while(!feof(arc)){
            result = fgets(name, 100, arc);
            printf("Result: %d\n", result);
            if(result){
                printf("%s\n", name);
            }
        }
    }else{
        printf("File not found.");
    }
    
    fclose(arc);
    return 0;
    