#include <stdio.h>

//Estrutura das funções
/*
- tipo de retorno
- nome
- parâmetros de entrada (opcional)
- implementação
- retorno (opcional)
*/

void message(){ //função não tem retorno, só executa
    printf("Welcome"); //implementação
} //não tem return pois é void

int sum(int num1, int num2){
    int res = num1 + num2;
    return res;
}

// 'a'
// '97'
void next_char(char character){
    printf("%c", character+1);
}

int main(){ //função principal
    printf("hello..."); //função da biblioteca stdio
    return 0; //já que a função é int. 0 = sucesso; != 0 = error
}