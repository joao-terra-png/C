/*
Autor: Grupo B
Data de Criação: 24/06/2026
Data de Alteração: 08/07/2026
Objetivo: Testar a implementação do Tipo Abstrato de Dados (TAD) Conjunto
           por meio de um menu com operações de manipulação e consulta
           de conjuntos de números inteiros.
*/

//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include "projbio.h"

#ifdef _WIN32
    #define LIMPAR_TELA() system("cls")
#else
    #define LIMPAR_TELA() system("clear")
#endif

//Protótipos
int lerInteiro(const char *prompt, int *destino);
void pausar(void);


//Função Principal
int main()
{
    tConjunto A, B;
    int opcao, valor, quantidade, i;
    int vetor[MAX_ELEMENTOS];

    criarConjunto(&A);
    criarConjunto(&B);

    do
    {
        LIMPAR_TELA();

        printf("\n============================================\n");
        printf("             MENU CONJUNTO                 \n");
        printf("============================================\n");
        printf("\n -- Operacoes basicas --\n");
        printf(" 1  - Criar (esvaziar) conjunto A\n");
        printf(" 2  - Criar (esvaziar) conjunto B\n");
        printf(" 3  - Inserir elemento em A\n");
        printf(" 4  - Inserir elemento em B\n");
        printf(" 5  - Inserir varios elementos em A\n");
        printf(" 6  - Inserir varios elementos em B\n");
        printf(" 7  - Remover elemento de A\n");
        printf(" 8  - Remover elemento de B\n");
        printf("\n -- Exibicao --\n");
        printf(" 9  - Mostrar A (desordenado)\n");
        printf(" 10 - Mostrar B (desordenado)\n");
        printf(" 11 - Mostrar A ordenado\n");
        printf(" 12 - Mostrar B ordenado\n");
        printf("\n -- Consultas --\n");
        printf(" 13 - A esta vazio?\n");
        printf(" 14 - B esta vazio?\n");
        printf(" 15 - Numero de elementos de A\n");
        printf(" 16 - Numero de elementos de B\n");
        printf(" 17 - Buscar elemento em A\n");
        printf(" 18 - Buscar elemento em B\n");
        printf(" 19 - Maior e menor valor de A\n");
        printf(" 20 - Maior e menor valor de B\n");
        printf("\n -- Operacoes entre conjuntos --\n");
        printf(" 21 - Uniao A U B\n");
        printf(" 22 - Interseccao A ∩ B\n");
        printf(" 23 - Diferenca A - B\n");
        printf("\n -- Relacoes --\n");
        printf(" 24 - A esta contido em B (subconjunto proprio)\n");
        printf(" 25 - A esta contido ou igual a B\n");
        printf(" 26 - A contem B (proprio)\n");
        printf(" 27 - A contem ou igual a B\n");
        printf(" 28 - A e igual a B\n");
        printf(" 0  - Sair\n");

        if (!lerInteiro("Escolha: ", &opcao))
        {
            printf("\nEntrada encerrada. Saindo...\n");
            break;
        }

        switch(opcao)
        {
            /* ---------- Operacoes basicas ---------- */

            case 1:
                criarConjunto(&A);
                printf("Conjunto A criado (esvaziado)!\n");
                break;

            case 2:
                criarConjunto(&B);
                printf("Conjunto B criado (esvaziado)!\n");
                break;

            case 3:
            {
                int resultadoInsercao;

                if (!lerInteiro("Digite valor para A: ", &valor))
                {
                    printf("\nEntrada encerrada. Saindo...\n");
                    opcao = 0;
                    break;
                }

                resultadoInsercao = inserirElemento(&A, valor);
                if(resultadoInsercao == ERRO_DUPLICADO)
                    printf("Elemento duplicado!\n");
                else if(resultadoInsercao == ERRO_CONJUNTO_CHEIO)
                    printf("Conjunto cheio!\n");
                else
                    printf("Inserido com sucesso!\n");
                break;
            }

            case 4:
            {
                int resultadoInsercao;

                if (!lerInteiro("Digite valor para B: ", &valor))
                {
                    printf("\nEntrada encerrada. Saindo...\n");
                    opcao = 0;
                    break;
                }

                resultadoInsercao = inserirElemento(&B, valor);
                if(resultadoInsercao == ERRO_DUPLICADO)
                    printf("Elemento duplicado!\n");
                else if(resultadoInsercao == ERRO_CONJUNTO_CHEIO)
                    printf("Conjunto cheio!\n");
                else
                    printf("Inserido com sucesso!\n");
                break;
            }

            case 5:
            {
                int totalInseridos;

                if (!lerInteiro("Quantos elementos deseja inserir em A? ", &quantidade))
                {
                    printf("\nEntrada encerrada. Saindo...\n");
                    opcao = 0;
                    break;
                }

                if (quantidade < 0 || quantidade > MAX_ELEMENTOS)
                {
                    printf("Quantidade invalida!\n");
                    break;
                }

                for (i = 0; i < quantidade; i++)
                {
                    char prompt[32];
                    sprintf(prompt, "Valor %d: ", i + 1);
                    if (!lerInteiro(prompt, &vetor[i]))
                    {
                        printf("\nEntrada encerrada. Saindo...\n");
                        opcao = 0;
                        break;
                    }
                }
                if (opcao == 0) break;

                totalInseridos = inserirVariosElementos(&A, vetor, quantidade);
                printf("%d de %d elementos inseridos com sucesso!\n", totalInseridos, quantidade);
                break;
            }

            case 6:
            {
                int totalInseridos;

                if (!lerInteiro("Quantos elementos deseja inserir em B? ", &quantidade))
                {
                    printf("\nEntrada encerrada. Saindo...\n");
                    opcao = 0;
                    break;
                }

                if (quantidade < 0 || quantidade > MAX_ELEMENTOS)
                {
                    printf("Quantidade invalida!\n");
                    break;
                }

                for (i = 0; i < quantidade; i++)
                {
                    char prompt[32];
                    sprintf(prompt, "Valor %d: ", i + 1);
                    if (!lerInteiro(prompt, &vetor[i]))
                    {
                        printf("\nEntrada encerrada. Saindo...\n");
                        opcao = 0;
                        break;
                    }
                }
                if (opcao == 0) break;

                totalInseridos = inserirVariosElementos(&B, vetor, quantidade);
                printf("%d de %d elementos inseridos com sucesso!\n", totalInseridos, quantidade);
                break;
            }

            case 7:
                if (!lerInteiro("Digite valor para remover de A: ", &valor))
                {
                    printf("\nEntrada encerrada. Saindo...\n");
                    opcao = 0;
                    break;
                }

                if(removerElemento(&A, valor))
                    printf("Removido!\n");
                else
                    printf("Nao encontrado!\n");
                break;

            case 8:
                if (!lerInteiro("Digite valor para remover de B: ", &valor))
                {
                    printf("\nEntrada encerrada. Saindo...\n");
                    opcao = 0;
                    break;
                }

                if(removerElemento(&B, valor))
                    printf("Removido!\n");
                else
                    printf("Nao encontrado!\n");
                break;

            /* ---------- Exibicao ---------- */

            case 9:
                printf("Conjunto A: ");
                exibirConjuntoDesordenado(A);
                break;

            case 10:
                printf("Conjunto B: ");
                exibirConjuntoDesordenado(B);
                break;

            case 11:
            {
                int crescente;

                if (!lerInteiro("Ordem (1-crescente / 0-decrescente): ", &crescente))
                {
                    printf("\nEntrada encerrada. Saindo...\n");
                    opcao = 0;
                    break;
                }
                printf("Conjunto A ordenado: ");
                exibirConjuntoOrdenado(A, crescente);
                break;
            }

            case 12:
            {
                int crescente;

                if (!lerInteiro("Ordem (1-crescente / 0-decrescente): ", &crescente))
                {
                    printf("\nEntrada encerrada. Saindo...\n");
                    opcao = 0;
                    break;
                }
                printf("Conjunto B ordenado: ");
                exibirConjuntoOrdenado(B, crescente);
                break;
            }

            /* ---------- Consultas ---------- */

            case 13:
                if(estaVazio(A))
                    printf("A esta vazio\n");
                else
                    printf("A NAO esta vazio\n");
                break;

            case 14:
                if(estaVazio(B))
                    printf("B esta vazio\n");
                else
                    printf("B NAO esta vazio\n");
                break;

            case 15:
                printf("Numero de elementos de A: %d\n", numeroElementosConjunto(A));
                break;

            case 16:
                printf("Numero de elementos de B: %d\n", numeroElementosConjunto(B));
                break;

            case 17:
                if (!lerInteiro("Digite o valor a buscar em A: ", &valor))
                {
                    printf("\nEntrada encerrada. Saindo...\n");
                    opcao = 0;
                    break;
                }

                if(buscaElemento(A, valor))
                    printf("Elemento encontrado em A\n");
                else
                    printf("Elemento NAO encontrado em A\n");
                break;

            case 18:
                if (!lerInteiro("Digite o valor a buscar em B: ", &valor))
                {
                    printf("\nEntrada encerrada. Saindo...\n");
                    opcao = 0;
                    break;
                }

                if(buscaElemento(B, valor))
                    printf("Elemento encontrado em B\n");
                else
                    printf("Elemento NAO encontrado em B\n");
                break;

            case 19:
                if (estaVazio(A))
                {
                    printf("Conjunto A esta vazio!\n");
                    break;
                }
                printf("Maior de A: %d\n", maiorValor(A));
                printf("Menor de A: %d\n", menorValor(A));
                break;

            case 20:
                if (estaVazio(B))
                {
                    printf("Conjunto B esta vazio!\n");
                    break;
                }
                printf("Maior de B: %d\n", maiorValor(B));
                printf("Menor de B: %d\n", menorValor(B));
                break;

            /* ---------- Operacoes entre conjuntos ---------- */

            case 21:
            {
                tConjunto U = uniaoConjuntos(A, B);
                printf("Uniao: ");
                exibirConjuntoDesordenado(U);
                break;
            }

            case 22:
            {
                tConjunto I = intersecaoConjuntos(A, B);
                printf("Interseccao: ");
                exibirConjuntoDesordenado(I);
                break;
            }

            case 23:
            {
                tConjunto D = diferencaConjuntos(A, B);
                printf("Diferenca (A - B): ");
                exibirConjuntoDesordenado(D);
                break;
            }

            /* ---------- Relacoes ---------- */

            case 24:
                if(verificaEstaContido(A, B))
                    printf("A esta contido propriamente em B\n");
                else
                    printf("A NAO esta contido propriamente em B\n");
                break;

            case 25:
                if(verificaEstaContidoIgual(A, B))
                    printf("A esta contido em B (ou e igual)\n");
                else
                    printf("A NAO esta contido em B\n");
                break;

            case 26:
                if(contem(A, B))
                    printf("A contem B (propriamente)\n");
                else
                    printf("A NAO contem B propriamente\n");
                break;

            case 27:
                if(contemIgual(A, B))
                    printf("A contem B (ou e igual)\n");
                else
                    printf("A NAO contem B\n");
                break;

            case 28:
                if(igual(A, B))
                    printf("A e igual a B\n");
                else
                    printf("A NAO e igual a B\n");
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

        if (opcao != 0)
            pausar();

    } while(opcao != 0);

    return 0;
}

/*
    Subrotina: lerInteiro
    Objetivo: Ler um numero inteiro do teclado de forma segura.
    Se o usuario digitar algo que nao seja um numero (ex: uma letra),
    a funcao limpa o buffer de entrada, avisa o usuario e pede
    novamente, em vez de deixar o programa "travar" ou fechar sozinho.

    Parametros:
    - prompt: mensagem exibida antes de cada tentativa de leitura (entrada)
    - destino: endereco onde o valor lido sera armazenado (saida)

    Valor de retorno:
    - 1 se um numero foi lido com sucesso
    - 0 se o fim da entrada foi atingido (EOF), sinalizando que nao ha
      mais nada para ler (usado para encerrar o programa com seguranca)
*/
int lerInteiro(const char *prompt, int *destino)
{
    int resultado;
    int c;

    while (1)
    {
        if (prompt != NULL)
            printf("%s", prompt);

        resultado = scanf("%d", destino);

        if (resultado == 1)
        {
            /* Leitura numerica valida */
            return 1;
        }

        if (resultado == EOF)
        {
            return 0;
        }

        while ((c = getchar()) != '\n' && c != EOF);

        printf("Entrada invalida! Digite um numero inteiro.\n");
    }
}

/*
    Subrotina: pausar
    Objetivo: Interromper a execucao ate o usuario apertar Enter,
    evitando que a mensagem suma quando o menu for reimpresso na
    tela. Descarta primeiro o '\n' residual deixado pela leitura
    anterior (scanf), para nao confundi-lo com o Enter do usuario.
*/
void pausar(void)
{
    int c;

    printf("\nPressione Enter para continuar...");

    while ((c = getchar()) != '\n' && c != EOF);

    getchar();
}