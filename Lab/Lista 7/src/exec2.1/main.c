#include "MDF.h"
#include <stdio.h>

int main() {
    MFaixa* matriz = NULL;
    int opcao, tam, ini, fim, elem, i, j;

    do {
        printf("### Menu Principal ###\n");
        printf("1. Criar matriz\n");
        printf("2. Preencher aleatoriamente\n");
        printf("3. Inserir elemento\n");
        printf("4. Consultar elemento\n");
        printf("5. Imprimir matriz\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o tamanho da matriz: ");
                scanf("%d", &tam);
                matriz = criaMatriz(tam);
                if (matriz != NULL) {
                    printf("Matriz criada com sucesso!\n");
                } else {
                    printf("Falha ao criar a matriz. Certifique-se de que o tamanho seja > 1.\n");
                }
                break;

            case 2:
                if (matriz == NULL) {
                    printf("Crie uma matriz primeiro!\n");
                } else {
                    printf("Digite o intervalo de números aleatórios (início e fim): ");
                    scanf("%d %d", &ini, &fim);
                    if (preencheAleatorio(matriz, ini, fim)) {
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
                        printf("Elemento inserido com sucesso.\n");
                    } else {
                        printf("Falha ao inserir o elemento.\n");
                    }
                }
                break;

            case 4:
                if (matriz == NULL) {
                    printf("Crie uma matriz primeiro!\n");
                } else {
                    printf("Digite a linha e a coluna para consulta: ");
                    scanf("%d %d", &i, &j);
                    int resultado = consultaElem(matriz, i, j);
                    if (resultado) {
                        printf("Elemento consultado: %d\n", resultado);
                    } else {
                        printf("Falha na consulta.\n");
                    }
                }
                break;

            case 5:
                if (matriz == NULL) {
                    printf("Crie uma matriz primeiro!\n");
                } else {
                    imprimeFaixa(matriz);
                }
                break;

            case 0:
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    if (matriz != NULL) {
        destroiMatriz(matriz);
    }

    return 0;
}
