#include <stdio.h>

int main()
{
    FILE *arc;
    int num, result, sum = 0;
    
    arc = fopen("archive.txt", "r");
    
    if(arc){
        while(!feof(arc)){
            result = fscanf(arc, "%d", &num);
            printf("Result: %d\n", result);
            if(result == 1){
                sum = sum + num;
            }
        }
    }else{
        printf("File not found.");
    }
    
    printf("The sum of the found numbers is %d", sum);
    fclose(arc);
    
    return 0;
}