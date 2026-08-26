#include <stdlib.h>

/*
Conversão de strings
    atof() //string --> double
    atoi() //string --> inteiro
    atol() //string --> inteiro longo

Geração de sequência pseudo-aleatória
    rand() //gera número aleatório 
    srand() //inicializa o gerador de número aleatório

        time_t t;

        //inicializar o gerador --> garante número mais aleatórios
        srand((unsigned) time(&t));

        //gerar 6 números entre 0 e 60
        for(int i = 0; i < 6; i++){
            printf("%d\n", rand() % 61);
        }

Gerenciamento de memória dinâmica
    malloc() //faz a alocação, mas mantém o lixo
    callod() //faz a alocação, mas zera o espaço
    free()
    realoc()

Pesquisa e ordenação
    qsort() //ordena os elementos de um array
        
        int compara(int *x, int *y){
            if(*x > *y){
                return 1;
            }else if{
                return 0;
            }else{
                return -1;
            }
        }
        
        int main(){
            int numeros[] = {6, 2, 9, 3, 7, 1, 5};

            qsort(numeros, 7, sizeof(int), (void *)compara);
        }

Aritmética de inteiros
    abs() //valor absoluto (módulo)
    div() //divisão inteira (.quot - quociente .rem - resto)
*/