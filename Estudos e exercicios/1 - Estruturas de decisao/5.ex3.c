/* Três amigos jogaram na loteria. Caso eles ganhem, o prêmio deve ser repartido proporcionalmente ao 
valor que cada um deu para a realização da aposta. Faça um programa que leia quanto cada apostador
apostou, o valor do prêmio e imprima quanto cada um ganharia do prêmio com base no valor investido. */
#include <stdio.h>

int main()
{
    float i, j, k, l = 0;
    float premio = 0;
    float p1, p2, p3, pt = 0;
    float premio1, premio2, premio3, total_premios = 0;
    
    printf("Quanto cada amigo apostou? \n");
    printf("Digite o primeiro valor ");
    scanf("%f", &i);
    
    printf("Digite o segundo valor ");
    scanf("%f", &j);
    
    printf("Digite o terceiro valor ");
    scanf("%f", &k);
    
    printf("Digite o valor do prêmio ");
    scanf("%f", &premio);
    
    l = (float)(i + j + k );
    printf("O total de apostas foi de %.2f\n", l);
    
    p1 = (float)(i / l);
    p2 = (float)(j / l);
    p3 = (float)(k / l);
    pt = (float)(p1 + p2 + p3);
    printf("O total de procentagens é %.2f\n", pt);
    
    premio1 = (float)(premio * p1);
    premio2 = (float)(premio * p2);
    premio3 = (float)(premio * p3);
    total_premios = (float)(premio1 + premio2 + premio3);
    printf("O total em prêmios é %.2f\n", total_premios);
    
    printf("O apostador 1 apostou %.2f que corresponde a %.2f e deverá receber o prêmio de %.2f\n", i, p1, premio1);
    printf("O apostador 2 apostou %.2f que corresponde a %.2f e deverá receber o prêmio de %.2f\n", j, p2, premio2);
    printf("O apostador 3 apostou %.2f que corresponde a %.2f e deverá receber o prêmio de %.2f\n", k, p3, premio3);
}