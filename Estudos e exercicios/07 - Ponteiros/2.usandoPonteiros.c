#include <stdio.h>

int main()
{
    int n; //vairável que guarda seu valor na memória
    
    //declarando
    int* p; // ponteiro é um valor que aponta para um endereço de memória
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    //inicializando o ponteiro
    p = &n;
    
    printf("Number entered: %d\n", n);
    
    printf("Memory adress: %p\n", &n);
    
    printf("Pointer adress: %p\n", p);
    
    return 0;
}