#include <stdio.h>

//aqui é criado outro espaço em memória para armazenar a variável
//assim value != counter sempre

//endereço de memória como parâmetro de entrada
void increase(int* value){ //* - recebendo um endereço de memória que aponta int
    printf("Before icrease.\n");
    printf("Counter value: %d\n", *value); //valor
    printf("Memory adress: %d\n", value); //endereço de memória
    
    printf("After increase.\n");
    printf("Counter value: %d\n", ++*value);
    printf("Memory adress: %d\n", value);
}

int main()
{
    //quando declaramos uma variável, a linguagem counter
    //aloca um espaço em memória para colocar este valor
    int counter = 10;
    
    printf("Before increase.\n");
    printf("Counter value: %d\n", counter);
    printf("Memory adress: %d\n", &counter);
    
    //cópia de valor
    increase(&counter); //passando o endereço de memória
    
    printf("After increase.\n");
    printf("Counter value: %d\n", counter);
    printf("Memory adress: %d\n", &counter);
    
    return 0;
}