#include <stdio.h>

int main(){
	//Declaração de variáveis
    int idade;

    //Entrada
    printf("Qual a sua idade?");
    scanf("%d", &idade);

	//Processamento
    if(idade < 18){
        printf("Voce e menor de idade");
    }else if(idade > 18 && idade < 60){
        printf("Voce e adulto\n");
    }else{
        printf("Voce e idoso\n");
    }

	//Saída
    printf("Sua idade é %d", idade);
    return 0;

}