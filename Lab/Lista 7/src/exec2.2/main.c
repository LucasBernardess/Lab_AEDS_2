#include "din.h"
#include "csr.h"
#include <stdio.h>

int main() {
    Matriz* matriz = NULL;
    MEsparsaCSR* matrizEsparsa = NULL;
    int opcao, linhas, colunas, qnn;
    int elem, i, j;

    do {
        printf("### Menu Principal ###\n");
        printf("1. Criar matriz\n");
        printf("2. Preencher matriz aleatoriamente\n");
        printf("3. Inserir elemento na matriz\n");
        printf("4. Consultar elemento na matriz\n");
        printf("5. Transformar em matriz esparsa\n");
        printf("6. Inserir elemento na matriz esparsa\n");
        printf("7. Consultar elemento na matriz esparsa\n");
        printf("8. Imprimir matriz\n");
        printf("9. Imprimir matriz esparsa\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o número de linhas e colunas da matriz: ");
                scanf("%d %d", &linhas, &colunas);
                matriz = criaMatriz(linhas, colunas);
                if (matriz != NULL) {
                    printf("Matriz criada com sucesso!\n");
                } else {
                    printf("Falha ao criar a matriz. Certifique-se de que as dimensões sejam válidas.\n");
                }
                break;

            case 2:
                if (matriz == NULL) {
                    printf("Crie uma matriz primeiro!\n");
                } else {
                    printf("Digite o intervalo de números aleatórios (início e fim): ");
                    scanf("%d %d", &elem, &qnn);
                    if (preencheAleatorio(matriz, elem, qnn)) {
                        printf("Matriz preenchida aleatoriamente.\n");
                    } else {
                        printf("Falha ao preencher a matriz aleatoriamente.\n");
                    }
                }
                break;

            case 3:
                if (matriz == NULL) {
                    printf("Crie uma matriz primeiro!\n");
                } else {
                    printf("Digite o elemento, a linha e a coluna: ");
                    scanf("%d %d %d", &elem, &i, &j);
                    if (insereElem(matriz, elem, i, j)) {
                        printf("Elemento inserido na matriz com sucesso.\n");
                    } else {
                        printf("Falha ao inserir o elemento na matriz.\n");
                    }
                }
                break;

            case 4:
                if (matriz == NULL) {
                    printf("Crie uma matriz primeiro!\n");
                } else {
                    printf("Digite a linha e a coluna para consulta: ");
                    scanf("%d %d", &i, &j);
                    int resultado;
                    if (consultaElem(matriz, &resultado, i, j)) {
                        printf("Elemento consultado na matriz: %d\n", resultado);
                    } else {
                        printf("Falha na consulta na matriz.\n");
                    }
                }
                break;

            case 5:
                if (matriz == NULL) {
                    printf("Crie uma matriz primeiro!\n");
                } else {
                    if (matrizEsparsa != NULL) {
                        destroiMatrizEsparsa(matrizEsparsa);
                    }
                    matrizEsparsa = transformarEmCSR(matriz);
                    if (matrizEsparsa != NULL) {
                        printf("Matriz transformada em matriz esparsa com sucesso.\n");
                    } else {
                        printf("Falha na transformação em matriz esparsa.\n");
                    }
                }
                break;

            case 6:
                if (matrizEsparsa == NULL) {
                    printf("Transforme uma matriz em matriz esparsa primeiro!\n");
                } else {
                    printf("Digite o elemento, a linha e a coluna: ");
                    scanf("%d %d %d", &elem, &i, &j);
                    if (insereElemEsparsa(matrizEsparsa, elem, i, j)) {
                        printf("Elemento inserido na matriz esparsa com sucesso.\n");
                    } else {
                        printf("Falha ao inserir o elemento na matriz esparsa.\n");
                    }
                }
                break;

            case 7:
                if (matrizEsparsa == NULL) {
                    printf("Transforme uma matriz em matriz esparsa primeiro!\n");
                } else {
                    printf("Digite a linha e a coluna para consulta: ");
                    scanf("%d %d", &i, &j);
                    int resultado;
                    if (consultaElemEsparsa(matrizEsparsa, i, j)) {
                        printf("Elemento consultado na matriz esparsa: %d\n", resultado);
                    } else {
                        printf("Falha na consulta na matriz esparsa.\n");
                    }
                }
                break;

            case 8:
                if (matriz == NULL) {
                    printf("Crie uma matriz primeiro!\n");
                } else {
                    imprime(matriz);
                }
                break;

            case 9:
                if (matrizEsparsa == NULL) {
                    printf("Transforme uma matriz em matriz esparsa primeiro!\n");
                } else {
                    imprimeEsparsa(matrizEsparsa);
                }
                break;

            case 0:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    if (matriz != NULL) {
        destroiMatriz(matriz);
    }
    if (matrizEsparsa != NULL) {
        destroiMatrizEsparsa(matrizEsparsa);
    }

    return 0;
}

