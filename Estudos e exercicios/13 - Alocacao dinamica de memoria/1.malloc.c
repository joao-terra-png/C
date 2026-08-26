#include <stdio.h>
#include <stdlib.h>

//Malloc

/*
Malloc mantém o lixo do sistema
*/

int main(){

    int qtd, *p;

    printf("Informe a quantidade de elementos para o vetor: ");
    scanf("%d", &qtd);

    p = (int*)malloc(qtd * sizeof(int)); //3 x 4 == 12 bytes //reserva espaço na memória

    if(p){
        for(int i = 0; i < qtd; i++){
            printf("Informe o valor para a posicao %d do vetor: ", i);
            scanf("%d", &p[i]);
        }

        for(int i = 0; i < qtd; i++){
            printf("No vetor 'numeros[%d]' esta o valor %d: \n", i, p[i]);
        }

        printf("A variavel 'p' ocupa %ld bytes em memoria.\n", qtd * sizeof(int));
    }else{
        printf("Erro: memoria insuficiente!");
    }

    //liberar a memória (desalocar)
    free(p);
    p = NULL; //medida de segurança

    return 0;
}