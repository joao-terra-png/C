//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "projbio.h"

/* Operações básicas */

//Autores: Nathaly e Luiza
//RA: 858030 e 859337
//Data de criação: 24/06/2026
//Data de alteração: 01/07/2026
//Objetivo:  Inicializar um conjunto sem elementos armazenados.

//Subrotina: criarConjunto
//Parâmetro de saída: C (conjunto vazio)
//Resultado: Conjunto ∅ (sem elementos)

void criarConjunto(tConjunto *C) {
    C->nElementos = 0;
}

/*---------------------------------------------------------------------------*/

/*
Autor: Murilo Destaole (858026) Daniel Yuji (856670)
Data de Criação: 24/06/26
Data de Alteração: 01/07/26
Objetivo: Implementação de função para inserir um novo elemento no conjunto, desde que o conjunto não esteja cheio e o elemento ainda não exista nele.
*/

/*
Sub-rotina: inserirElemento
Objetivo: Inserir um novo elemento no conjunto, desde que o conjunto não esteja cheio e o elemento ainda não exista nele.
Parâmetros:
- conjunto: Estrutura que representa o conjunto onde o elemento será inserido (entrada/saída de dados)
- elemento: O valor inteiro que se deseja inserir no conjunto (entrada de dados)
Valor de Retorno:
- ERRO_DUPLICADO se o elemento já existe, ERRO_CONJUNTO_CHEIO se o conjunto está cheio, SUCESSO caso contrário (int)
*/

int inserirElemento(tConjunto *conjunto, int elemento) {
    if (buscaElemento(*conjunto, elemento)) {
        return ERRO_DUPLICADO;
    }

    if (conjunto->nElementos >= MAX_ELEMENTOS) {
        return ERRO_CONJUNTO_CHEIO;
    }

    conjunto->elementos[conjunto->nElementos] = elemento;
    conjunto->nElementos++;

    return SUCESSO;
}

/*---------------------------------------------------------------------------*/

/*
Objetivo: Inserir vários elementos de uma vez no conjunto, ignorando
os que já existem ou não couberem por falta de espaço.
Parâmetros:
- c: conjunto onde os elementos serão inseridos (entrada/saída)
- vetor: vetor com os elementos a inserir (entrada)
- quantidade: quantidade de elementos em vetor (entrada)
Valor de retorno: quantidade de elementos efetivamente inseridos (int)
*/

int inserirVariosElementos(tConjunto *c, int vetor[], int quantidade) {
    int i;
    int totalInseridos = 0;

    for (i = 0; i < quantidade; i++) {
        if (inserirElemento(c, vetor[i]) == SUCESSO) {
            totalInseridos++;
        }
    }

    return totalInseridos;
}

/*---------------------------------------------------------------------------*/

/*
Autor: Guilherme Goulart de Oliveira e Kemily Vitoria
RA: 856171
Data de Criacao: 24/06/26
Data de Alteracao: 01/07/26
Objetivo: Implementacao da sub-rotina de Remover elemento do Conjunto
*/

//
// Subrotina: removerElemento
// Objetivo: Remover um elemento do conjunto, caso ele exista,
// deslocando os elementos subsequentes para preencher o espaco.
// Parâmetros Formais
// - conj: conjunto do qual o elemento sera removido (entrada e saída)
// - elemento: valor do elemento a ser removido (entrada)
// Valor de retorno: 1 se o elemento foi removido,
// ou 0 se o elemento nao foi encontrado no conjunto (int)
//
int removerElemento(tConjunto *conj, int elemento)
{
    int i;          /* Indice para percorrer o vetor */
    int posicao;    /* Posicao do elemento encontrado */
    int encontrado; /* Flag: 1 se encontrou, 0 se nao */

    /* Inicializa variaveis de controle */
    encontrado = 0;
    posicao = -1;

    /* Percorre o vetor buscando o elemento */
    for (i = 0; i < conj->nElementos; i++)
    {
        if (conj->elementos[i] == elemento)
        {
            posicao = i;
            encontrado = 1;
            break; /* Elemento encontrado, encerra a busca */
        }
    }

    /* Se nao encontrou, retorna erro (falso) */
    if (!encontrado)
    {
        return 0;
    }

    /* Desloca os elementos apos a posicao uma casa para a esquerda */
    for (i = posicao; i < conj->nElementos - 1; i++)
    {
        conj->elementos[i] = conj->elementos[i + 1];
    }

    /* Decrementa o contador de elementos */
    conj->nElementos--;

    return 1;
}

/*---------------------------------------------------------------------------*/

/* Exibição */

//Autores: Nathaly e Luiza
//RA: 858030 e 859337
//Data de criação: 24/06/2026
//Data de alteração: 01/07/2026
//Objetivo:  Exibir todos os elementos do conjunto na sequência de armazenamento.

//Subrotina: exibirConjuntoDesordenado
//Objetivo : Exibir todos os elementos do conjunto na sequência de armazenamento.
//Parâmetro: C - conjunto de dados (entrada)

void exibirConjuntoDesordenado(tConjunto C) {
    int i;
    printf("Conjunto { ");
    for (i = 0; i < C.nElementos; i++) {
        printf("%d", C.elementos[i]);
        if (i < C.nElementos - 1)
            printf(", ");
    }
    printf(" }\n");
}

/*---------------------------------------------------------------------------*/

/*
Autor: Iago Brás Antunes de Souza
RA: 856967
Data de Criação: 24/06/2026
Data de Alteração: 01/07/2026
Objetivo: Exibir os elementos de um conjunto ordenados de forma crescente ou decrescente
*/

static int compararCrescente(const void *a, const void *b) {
    int valA = *(const int*)a;
    int valB = *(const int*)b;
    return (valA > valB) - (valA < valB);
}

static int compararDecrescente(const void *a, const void *b) {
    int valA = *(const int*)a;
    int valB = *(const int*)b;
    return (valB > valA) - (valB < valA);
}

//
// Subrotina: exibirConjuntoOrdenado
// Objetivo: Exibir os elementos de um conjunto ordenados de forma crescente ou decrescente
// Parâmetros Formais
// - c: conjunto a ser exibido (entrada)
// - crescente: indicador de ordenação (1 para crescente, 0 para decrescente) (entrada)
// Valor de retorno: nenhum (void)
//
void exibirConjuntoOrdenado(tConjunto c, int crescente){
    int temp[MAX_ELEMENTOS];
    int n = c.nElementos;
    int i;

    for (i = 0; i < n; i++) {
        temp[i] = c.elementos[i];
    }

    if (crescente) {
        qsort(temp, n, sizeof(int), compararCrescente);
    } else {
        qsort(temp, n, sizeof(int), compararDecrescente);
    }

    printf("{");
    for (i = 0; i < n; i++) {
        printf("%d", temp[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

/*---------------------------------------------------------------------------*/

/* Consultas */

/*
Autor: Murilo Destaole (858026) Daniel Yuji (856670)
Data de Criação: 24/06/26
Data de Alteração: 01/07/26
Objetivo: Implementação de função para verificar se um determinado conjunto não possui nenhum elemento.
*/


/*
Sub-rotina: estaVazio
Objetivo: Verificar se um determinado conjunto não possui nenhum elemento.
Parâmetros:
- conjunto: Estrutura que armazena os dados e a quantidade de elementos do conjunto (entrada de dados)
Valor de Retorno:
- Retorna 1 (true) se o conjunto estiver vazio ou 0 (false) caso contrário.
*/

int estaVazio(tConjunto conjunto) {
    return conjunto.nElementos == 0;
}

/*---------------------------------------------------------------------------*/

/*
Autor: Beatriz Kwok (858034) e Iago Antonio de Souza (859087)
Data de Criação: 24/06/26
Data de Alteração: 24/06/26
Objetivo: Implementação da função de retornar a quantidade atual de elementos armazenados no conjunto
*/

// Subrotina: numeroElementosConjunto
// Objetivo: Retornar a quantidade atual de elementos armazenados no conjunto
// Parâmetros Formais
// c: conjunto de dados (parâmetro de entrada de dados).
// Valor de retorno: numeroElementos (int): retorna a quantidade atual de elementos armazenados no conjunto (parâmetro de saída de dados)
int numeroElementosConjunto(tConjunto c)
{
    int numeroElementos = c.nElementos;
    return numeroElementos;
}

/*---------------------------------------------------------------------------*/

/* ------------------------------------------------------------------
   buscaElemento
   Responsáveis: Isabely e Fernanda

   Objetivo: Verificar se um elemento está armazenado no conjunto.
   Retorna 1 (true) se o elemento for encontrado, 0 (false) caso
   contrário.
-------------------------------------------------------------------- */

int buscaElemento(tConjunto c, int elemento){
    int i;
    //loop que percorre todos os elementos (O(n))
    for(i = 0; i < c.nElementos; i++){
        //se elemento armazenado for igual ao elemento procurado
        if(c.elementos[i] == elemento){
            return 1; //true
        }
    }

    return 0; //false
}

/*---------------------------------------------------------------------------*/

/*
Autor: Isabela Garcia Gonçalves de Carvalho (856271), José Vitor Winterle de Souza (856378)
Data de Criação: 24/06/26
Data de Alteração: 01/07/26
*/

/*
Sub-rotina: maiorValor
Objetivo: Encontrar e retornar o maior valor contido no conjunto
Parâmetros:
- C: o conjunto que será analisado (entrada)*/

int maiorValor(tConjunto C){
    int i;
    int maior = C.elementos[0];

    for(i = 1; i < C.nElementos; i++){
        if(C.elementos[i] >= maior){
            maior = C.elementos[i];
        }
    }

    return maior;
}

/*---------------------------------------------------------------------------*/

/*
Autor: Isabela Garcia Gonçalves de Carvalho (856271), José Vitor Winterle de Souza (856378)
Data de Criação: 24/06/26
Data de Alteração: 01/07/26
*/

/*
Sub-rotina: menorValor
Objetivo: Encontrar e retornar o menor valor contido no conjunto
Parâmetros:
- C: o conjunto que será analisado (entrada)*/

int menorValor(tConjunto C){
    int i;
    int menor = C.elementos[0];

    for(i = 1; i < C.nElementos; i++){
        if(C.elementos[i] <= menor){
            menor = C.elementos[i];
        }
    }

    return menor;
}

/*---------------------------------------------------------------------------*/

/* Operações entre conjuntos */

/*
Autores: João Gabriel Azevedo Terra (858032) Thiago Aviz Brasil(856397)
Data de Criação: 24/06/26
Data de Alteração: 24/06/26
Objetivo: Implementação de união e interseção do Tipo Abstrato de Dados Conjunto
*/


/*
Sub-rotina: uniaoConjuntos
Objetivo: Realizar a união de dois conjuntos, retornando um novo conjunto contendo todos os elementos de A e B.
Parâmetros:
- A: conjunto de entrada (entrada de dados)
- B: conjunto de entrada (entrada de dados)
Valor de Retorno:
- Conjunto resultante contendo a união de A e B
*/
tConjunto uniaoConjuntos(tConjunto A, tConjunto B)
{
    tConjunto R;
    int i;

    R = A;

    for(i = 0; i < B.nElementos; i++){
        inserirElemento(&R, B.elementos[i]);
    }

    return R;
}

/*---------------------------------------------------------------------------*/

/*
Autores: João Gabriel Azevedo Terra (858032) Thiago Aviz Brasil(856397)
Data de Criação: 24/06/26
Data de Alteração: 24/06/26
Objetivo: Implementação de união e interseção do Tipo Abstrato de Dados Conjunto
*/

/*
Sub-rotina: intersecaoConjuntos
Objetivo: Calcular a interseção entre dois conjuntos, retornando um conjunto com os elementos comuns a A e B.
Parâmetros:
- A: conjunto base para verificação (entrada de dados)
- B: conjunto de referência para busca (entrada de dados)
Valor de Retorno:
- Conjunto contendo apenas os elementos presentes em A e B
*/
tConjunto intersecaoConjuntos(tConjunto A, tConjunto B)
{
    tConjunto R;
    int i;

    criarConjunto(&R);

    for(i = 0; i < A.nElementos; i++){
        if(buscaElemento(B, A.elementos[i])){
            inserirElemento(&R, A.elementos[i]);
        }
    }
    return R;
}

/*---------------------------------------------------------------------------*/

/*
Autor: Guilherme Goulart de Oliveira e Kemily Vitoria
RA: 856171
Data de Criacao: 24/06/26
Data de Alteracao: 01/07/26
Objetivo: Implementacao da sub-rotina de Retornar a diferenca
          entre 2 Conjuntos (a - b)
*/

//
// Subrotina: diferencaConjuntos
// Objetivo: Calcular a diferenca entre dois conjuntos (A - B),
// retornando um conjunto com os elementos que pertencem
// ao conjunto A e nao pertencem ao conjunto B.
// Parâmetros Formais
// - A: primeiro conjunto, do qual sera feita a diferenca (entrada)
// - B: segundo conjunto, cujos elementos serao excluidos (entrada)
// Valor de retorno: conjunto resultante da diferenca (tConjunto)
//
tConjunto diferencaConjuntos(tConjunto A, tConjunto B)
{
    tConjunto resultado;
    int i;

    criarConjunto(&resultado);

    for (i = 0; i < A.nElementos; i++)
    {
        if (!buscaElemento(B, A.elementos[i]))
        {
            inserirElemento(&resultado, A.elementos[i]);
        }
    }

    return resultado;
}

/*---------------------------------------------------------------------------*/

/*
Autor: Beatriz Kwok (858034) e Iago Antonio de Souza (859087)
Data de Criação: 01/07/26
Data de Alteração: 01/07/26
Objetivo: Implementação da função de retornar se um conjunto C1 é um subconjunto próprio de um conjunto C2.
*/

// Subrotina: verificaEstaContido
// Objetivo: Retornar se um conjunto C1 é um subconjunto próprio do conjunto C2.
// Parâmetros Formais
// C1: conjunto de dados (parâmetro de entrada de dados).
// C2: conjunto de dados (parâmetro de entrada de dados).
// Valor de retorno (int): retorna 1 se todos os elementos de C1 pertencem a C2 e C2 possui pelo menos um elemento que não pertence a C1; caso contrário, retorna 0.
int verificaEstaContido(tConjunto C1, tConjunto C2)
{
    int i;
    // Se a quantidade de elementos de C1 for maior ou igual que a quantidade de elementos de C2
    if (C1.nElementos >= C2.nElementos){
        return 0; //false
    }
    // Loop que verifica se todo elemento de C1 pertence a C2
    for (i = 0; i < C1.nElementos; i++){
        // Se o elemento C1.elementos[i] não pertence a C2
        if (!buscaElemento(C2, C1.elementos[i])){
            return 0; //false
        }
    }
    return 1; //true
}

/*---------------------------------------------------------------------------*/

/*
Autor: Beatriz Kwok (858034) e Iago Antonio de Souza (859087)
Data de Criação: 01/07/26
Data de Alteração: 01/07/26
Objetivo: Implementação da função de retornar se um conjunto C1 está contido em C2 (subconjunto não necessariamente próprio).
*/

// Subrotina: verificaEstaContidoIgual
// Objetivo: Retornar se todo elemento de C1 pertence a C2 (C1 pode ser igual a C2).
// Valor de retorno (int): 1 se C1 é subconjunto de C2 (incluindo igualdade), 0 caso contrário.
int verificaEstaContidoIgual(tConjunto C1, tConjunto C2)
{
    int i;

    if (C1.nElementos > C2.nElementos){
        return 0; //false
    }

    for (i = 0; i < C1.nElementos; i++){
        if (!buscaElemento(C2, C1.elementos[i])){
            return 0; //false
        }
    }
    return 1; //true
}

/*---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------
   contem
   Responsáveis: Isabely e Fernanda

   Objetivo: Verificar se o conjunto c1 contém todo o conjunto c2,
   ou seja, se c2 é um subconjunto próprio de c1 (todos os elementos
   de c2 estão em c1, mas c1 possui pelo menos um elemento que c2
   não possui).
   Retorna 1 (true) se C1 contém C2, 0 (false) caso contrário.
----------------------------------------------------------------- */

int contem(tConjunto c1, tConjunto c2){
    int i;

    //se quantidade de elementos de c2 for maior ou igual a quantidade de elementos de c1
    if(c2.nElementos >= c1.nElementos){
        return 0; //false
    }

    //loop que verifica se todo elemento de c2 está em c1
    for(i = 0; i < c2.nElementos; i++){
        //se o elemento c2.elementos[i] não esta em c1
        if(!buscaElemento(c1, c2.elementos[i])){
            return 0; //false
        }
    }

    return 1; //true
}

/*---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------
   contemIgual
   Objetivo: Verificar se o conjunto c1 contém todo o conjunto c2,
   permitindo que c1 seja igual a c2 (subconjunto não necessariamente próprio).
   Retorna 1 (true) se todo elemento de c2 está em c1, 0 (false) caso contrário.
----------------------------------------------------------------- */

int contemIgual(tConjunto c1, tConjunto c2){
    int i;

    if (c2.nElementos > c1.nElementos){
        return 0; //false
    }

    for (i = 0; i < c2.nElementos; i++){
        if (!buscaElemento(c1, c2.elementos[i])){
            return 0; //false
        }
    }

    return 1; //true
}

/*---------------------------------------------------------------------------*/

/* -----------------------------------------------------------------
   igual
   Objetivo: Verificar se dois conjuntos possuem exatamente os mesmos
   elementos (mesmo tamanho e mesmo conteúdo, independente da ordem).
   Retorna 1 (true) se A e B são iguais, 0 (false) caso contrário.
----------------------------------------------------------------- */

int igual(tConjunto A, tConjunto B){
    if (A.nElementos != B.nElementos){
        return 0; //false
    }

    return contemIgual(A, B) && contemIgual(B, A);
}