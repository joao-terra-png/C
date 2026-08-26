// Leia quatro notas, calcule a média aritmética e imprima o resultado. 
#include <stdio.h>

int main()
{
    int i, j, k, l;
    
    printf("Digite a primeira nota ");
    scanf("%d", &i);
    
    printf("Digite a segundo nota ");
    scanf("%d", &j);
    
    printf("Digite a terceiro nota ");
    scanf("%d", &k);
    
    printf("Digite a quarta nota ");
    scanf("%d", &l);
    
    int media = (i + j + k + l) / 4;
    printf("A média das notas é %d", media);
    
}