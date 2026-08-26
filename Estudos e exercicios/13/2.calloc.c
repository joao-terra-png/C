#include <stdio.h>
#include <stdlib.h>

//Calloc

/*
Calloc zera os espaços da memória
*/

int main(){

    int qtd, *p;

    printf("Informe a quantidade de elementos para o vetor: ");
    scanf("%d", &qtd);

    p = (int*)calloc(qtd, sizeof(int)); //3 x 4 == 12 bytes //reserva espaço na memória

    if(p){
        printf("A variavel 'p' ocupa %ld bytes em memoria.\n", qtd * sizeof(int));
    }else{
        printf("Erro: memoria insuficiente!");
    }

    //liberar a memória (desalocar)
    free(p);
    p = NULL; //medida de segurança

    return 0;
}