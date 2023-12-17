#include <stdio.h>
#include "abp.h" 

int main() {
    ABP* arvore = criaABP(); 

    int opcao, elem;

    do {
        printf("### Menu Principal ###\n");
        printf("1. Inserir elemento\n");
        printf("2. Buscar elemento\n");
        printf("3. Remover elemento\n");
        printf("4. Imprimir árvore em ordem\n");
        printf("5. Imprimir árvore em pré-ordem\n");
        printf("6. Imprimir árvore em pós-ordem\n");
        printf("7. Mostrar quantidade de nós\n");
        printf("8. Destruir a árvore\n");
        printf("9. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elem);
                if (insereElem(arvore, elem)) {
                    printf("Elemento inserido com sucesso.\n");
                } else {
                    printf("Falha ao inserir o elemento.\n");
                }
                break;

            case 2:
                printf("Digite o elemento a ser buscado: ");
                scanf("%d", &elem);
                if (pesquisa(arvore, elem)) {
                    printf("Elemento encontrado na árvore.\n");
                } else {
                    printf("Elemento não encontrado na árvore.\n");
                }
                break;

            case 3:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &elem);
                if (removeElem(arvore, elem)) {
                    printf("Elemento removido com sucesso.\n");
                } else {
                    printf("Falha ao remover o elemento.\n");
                }
                break;

            case 4:
                printf("Imprimir árvore em ordem:\n");
                em_ordem(*arvore, 0);
                break;

            case 5:
                printf("Imprimir árvore em pré-ordem:\n");
                pre_ordem(*arvore, 0);
                break;

            case 6:
                printf("Imprimir árvore em pós-ordem:\n");
                pos_ordem(*arvore, 0);
                break;

            case 7:
                printf("Quantidade de nós na árvore: %d\n", countNodes(arvore));
                break;

            case 8:
                destroiABP(arvore);
                printf("Árvore destruída.\n");
                arvore = criaABP();
                break;

            case 9:
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 9);

    destroiABP(arvore);
    return 0;
}
