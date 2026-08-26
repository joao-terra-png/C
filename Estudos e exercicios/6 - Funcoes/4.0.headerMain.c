//main.c
#include <stdio.h>
#include "help.h" //biblioteca própria

int main(){ 
    int n1, n2, ret_s, ret_m;
    
    message();
    
    printf("Enter first number: ");
    scanf("%d", &n1);
    
    printf("Enter second number: ");
    scanf("%d", &n2);
    
    ret_s = sum(n1, n2);
    printf("The sum of %d with %d is: %d\n", n1, n2, ret_s);
    
    ret_m = mul(n1, n1);
    printf("The multiplication of %d with %d is: %d\n", n1, n2, ret_m);
    
    return 0; 
}