#include <stdio.h> //biblioteca para se trabalhar com entrada e saída padrão (teclado e monitor)

int main(){
    //Declarando variáveis - valores que podem ser alterados durante a execução
    int idade;
    //int idade = 0; isso é declarar e inicializar

    //Função para escrever algo na saída padrão do console
    printf("Qual e a sua idade?"); //imprime algo no console

    //Receber dados
    scanf("%d", &idade); //recebe algo do teclado -- scan(tipo da var, qual var vai armazenar)
    printf("A sua idade e %d", idade);
    return 0;
}