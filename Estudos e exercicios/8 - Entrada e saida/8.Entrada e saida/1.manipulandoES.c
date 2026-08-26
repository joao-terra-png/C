#include <stdio.h>

int main()
{
    FILE *arq;
    
    //fopen(nome-do-arquivos, forma-de-abertura)
    //w - abrir o arquivo para escrita(se já existir, será sobreescrito)
    //r - abrir o arquivo para leitura(não podemos escrever nele)
    //a - abrir o arquivo para adicação de conteúdo(se já existir, conteúdo será 
	//     adiconado nas linhas abaixo)
    arq = fopen("arquivo.txt", "w");
    
    //semper que finalizar a manipulação de um arquivo, ele deve ser fechado
    fclose(arq);
    
    return 0;
}