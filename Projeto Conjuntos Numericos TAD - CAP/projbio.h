#ifndef PROJBIO_H
#define PROJBIO_H

#define MAX_ELEMENTOS 1000

/* Códigos de retorno */
#define ERRO_DUPLICADO 0
#define ERRO_CONJUNTO_CHEIO 1
#define SUCESSO 2

typedef struct {
    int nElementos;
    int elementos[MAX_ELEMENTOS];
} tConjunto;

/******************************************************************************
    Sumario de funcoes disponiveis:

    Operacoes basicas:
        void criarConjunto(tConjunto *c);
        int  inserirElemento(tConjunto *c, int elemento);
        int  inserirVariosElementos(tConjunto *c, int vetor[], int quantidade);
        int  removerElemento(tConjunto *c, int elemento);

    Exibicao:
        void exibirConjuntoDesordenado(tConjunto c);
        void exibirConjuntoOrdenado(tConjunto c, int crescente);

    Consultas:
        int estaVazio(tConjunto c);
        int numeroElementosConjunto(tConjunto c);
        int buscaElemento(tConjunto c, int elemento);
        int maiorValor(tConjunto c);
        int menorValor(tConjunto c);

    Operacoes entre conjuntos:
        tConjunto uniaoConjuntos(tConjunto A, tConjunto B);
        tConjunto intersecaoConjuntos(tConjunto A, tConjunto B);
        tConjunto diferencaConjuntos(tConjunto A, tConjunto B);

    Relacoes:
        int verificaEstaContido(tConjunto A, tConjunto B);
        int verificaEstaContidoIgual(tConjunto A, tConjunto B);
        int contem(tConjunto A, tConjunto B);
        int contemIgual(tConjunto A, tConjunto B);
        int igual(tConjunto A, tConjunto B);

******************************************************************************/

/* Operações básicas */

/*
Sub-rotina: criarConjunto
Objetivo: Inicializar um conjunto sem elementos armazenados.
Parâmetros:
- c: conjunto a ser inicializado (saída)
Valor de retorno: nenhum (void)
*/
void criarConjunto(tConjunto *c);

/*
Sub-rotina: inserirElemento
Objetivo: Inserir um novo elemento no conjunto, desde que o conjunto não
esteja cheio e o elemento ainda não exista nele.
Parâmetros:
- c: conjunto onde o elemento será inserido (entrada/saída)
- elemento: valor inteiro a ser inserido no conjunto (entrada)
Valor de retorno: ERRO_DUPLICADO se o elemento já existe,
ERRO_CONJUNTO_CHEIO se o conjunto está cheio, SUCESSO caso contrário (int)
*/
int inserirElemento(tConjunto *c, int elemento);

/*
Sub-rotina: inserirVariosElementos
Objetivo: Inserir vários elementos de uma vez no conjunto, ignorando
os que já existem ou não couberem por falta de espaço.
Parâmetros:
- c: conjunto onde os elementos serão inseridos (entrada/saída)
- vetor: vetor com os elementos a inserir (entrada)
- quantidade: quantidade de elementos em vetor (entrada)
Valor de retorno: quantidade de elementos efetivamente inseridos (int)
*/
int inserirVariosElementos(tConjunto *c, int vetor[], int quantidade);

/*
Sub-rotina: removerElemento
Objetivo: Remover um elemento do conjunto, caso ele exista, deslocando
os elementos subsequentes para preencher o espaço.
Parâmetros:
- c: conjunto do qual o elemento será removido (entrada/saída)
- elemento: valor do elemento a ser removido (entrada)
Valor de retorno: 1 se o elemento foi removido, ou 0 se o elemento não
foi encontrado no conjunto (int)
*/
int removerElemento(tConjunto *c, int elemento);

/* Exibição */

/*
Sub-rotina: exibirConjuntoDesordenado
Objetivo: Exibir todos os elementos do conjunto na sequência de
armazenamento (sem ordenação).
Parâmetros:
- c: conjunto de dados (entrada)
Valor de retorno: nenhum (void)
*/
void exibirConjuntoDesordenado(tConjunto c);

/*
Sub-rotina: exibirConjuntoOrdenado
Objetivo: Exibir os elementos de um conjunto ordenados de forma
crescente ou decrescente.
Parâmetros:
- c: conjunto a ser exibido (entrada)
- crescente: indicador de ordenação (1 para crescente, 0 para
  decrescente) (entrada)
Valor de retorno: nenhum (void)
*/
void exibirConjuntoOrdenado(tConjunto c, int crescente);

/* Consultas */

/*
Sub-rotina: estaVazio
Objetivo: Verificar se um determinado conjunto não possui nenhum
elemento.
Parâmetros:
- c: conjunto de dados (entrada)
Valor de retorno: 1 (true) se o conjunto estiver vazio, ou 0 (false)
caso contrário (int)
*/
int estaVazio(tConjunto c);

/*
Sub-rotina: numeroElementosConjunto
Objetivo: Retornar a quantidade atual de elementos armazenados no
conjunto.
Parâmetros:
- c: conjunto de dados (entrada)
Valor de retorno: quantidade atual de elementos armazenados no
conjunto (int)
*/
int numeroElementosConjunto(tConjunto c);

/*
Sub-rotina: buscaElemento
Objetivo: Verificar se um elemento está armazenado no conjunto.
Parâmetros:
- c: conjunto de dados (entrada)
- elemento: valor procurado (entrada)
Valor de retorno: 1 (true) se o elemento for encontrado, 0 (false)
caso contrário (int)
*/
int buscaElemento(tConjunto c, int elemento);

/*
Sub-rotina: maiorValor
Objetivo: Encontrar e retornar o maior valor contido no conjunto.
Parâmetros:
- c: conjunto que será analisado (entrada)
Valor de retorno: maior valor presente no conjunto (int)
*/
int maiorValor(tConjunto c);

/*
Sub-rotina: menorValor
Objetivo: Encontrar e retornar o menor valor contido no conjunto.
Parâmetros:
- c: conjunto que será analisado (entrada)
Valor de retorno: menor valor presente no conjunto (int)
*/
int menorValor(tConjunto c);

/* Operações entre conjuntos */

/*
Sub-rotina: uniaoConjuntos
Objetivo: Realizar a união de dois conjuntos, retornando um novo
conjunto contendo todos os elementos de A e B.
Parâmetros:
- A: conjunto de entrada (entrada)
- B: conjunto de entrada (entrada)
Valor de retorno: conjunto resultante contendo a união de A e B
(tConjunto)
*/
tConjunto uniaoConjuntos(tConjunto A, tConjunto B);

/*
Sub-rotina: intersecaoConjuntos
Objetivo: Calcular a interseção entre dois conjuntos, retornando um
conjunto com os elementos comuns a A e B.
Parâmetros:
- A: conjunto base para verificação (entrada)
- B: conjunto de referência para busca (entrada)
Valor de retorno: conjunto contendo apenas os elementos presentes em
A e B (tConjunto)
*/
tConjunto intersecaoConjuntos(tConjunto A, tConjunto B);

/*
Sub-rotina: diferencaConjuntos
Objetivo: Calcular a diferença entre dois conjuntos (A - B),
retornando um conjunto com os elementos que pertencem ao conjunto A
e não pertencem ao conjunto B.
Parâmetros:
- A: primeiro conjunto, do qual será feita a diferença (entrada)
- B: segundo conjunto, cujos elementos serão excluídos (entrada)
Valor de retorno: conjunto resultante da diferença (tConjunto)
*/
tConjunto diferencaConjuntos(tConjunto A, tConjunto B);

/* Relações */

/*
Sub-rotina: verificaEstaContido
Objetivo: Retornar se um conjunto C1 é um subconjunto próprio do
conjunto C2 (todos os elementos de C1 pertencem a C2 e C2 possui
pelo menos um elemento que não pertence a C1).
Parâmetros:
- A: conjunto de dados (entrada)
- B: conjunto de dados (entrada)
Valor de retorno: 1 se A é subconjunto próprio de B, 0 caso
contrário (int)
*/
int verificaEstaContido(tConjunto A, tConjunto B);

/*
Sub-rotina: verificaEstaContidoIgual
Objetivo: Retornar se todo elemento de A pertence a B, permitindo que
A seja igual a B (subconjunto não necessariamente próprio).
Parâmetros:
- A: conjunto de dados (entrada)
- B: conjunto de dados (entrada)
Valor de retorno: 1 se A é subconjunto de B (incluindo igualdade), 0
caso contrário (int)
*/
int verificaEstaContidoIgual(tConjunto A, tConjunto B);

/*
Sub-rotina: contem
Objetivo: Verificar se o conjunto A contém todo o conjunto B, ou
seja, se B é um subconjunto próprio de A (todos os elementos de B
estão em A, mas A possui pelo menos um elemento que B não possui).
Parâmetros:
- A: conjunto de dados (entrada)
- B: conjunto de dados (entrada)
Valor de retorno: 1 (true) se A contém B propriamente, 0 (false)
caso contrário (int)
*/
int contem(tConjunto A, tConjunto B);

/*
Sub-rotina: contemIgual
Objetivo: Verificar se o conjunto A contém todo o conjunto B,
permitindo que A seja igual a B (subconjunto não necessariamente
próprio).
Parâmetros:
- A: conjunto de dados (entrada)
- B: conjunto de dados (entrada)
Valor de retorno: 1 (true) se todo elemento de B está em A, 0
(false) caso contrário (int)
*/
int contemIgual(tConjunto A, tConjunto B);

/*
Sub-rotina: igual
Objetivo: Verificar se dois conjuntos possuem exatamente os mesmos
elementos (mesmo tamanho e mesmo conteúdo, independente da ordem).
Parâmetros:
- A: conjunto de dados (entrada)
- B: conjunto de dados (entrada)
Valor de retorno: 1 (true) se A e B são iguais, 0 (false) caso
contrário (int)
*/
int igual(tConjunto A, tConjunto B);

#endif