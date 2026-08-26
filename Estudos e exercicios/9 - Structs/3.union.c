#include <stdio.h>
#include <string.h>

//A Union separa e utiliza apenas o espaço da MAIOR variavel
union pessoa{
    char nome[100]; //1 char = 1 byte --> 100 bystes
    int idade; //4 byster --> 104 bytes
}pes;

int main(){

    strcpy(pes.nome, "Joao Gabriel"); //copia a string para a var
    printf("Dados de %s\n", pes.nome);

    pes.idade = 39;
    pritnf("Ela tem %d anos\n", pes.idade);

    pritnf("A variavel 'pes esta ocupando %ld bytes em memoria", sizeof(pes));

    return 0;
}