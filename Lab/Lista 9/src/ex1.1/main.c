#include <stdio.h>
#include "avl.h" 

int main() {
    AVL* arvore;
    int opcao, elem;

    do {
        printf("### Menu Principal ###\n");
        printf("1. Criar AVL\n");
        printf("2. Inserir um elemento\n");
        printf("3. Buscar um elemento\n");
        printf("4. Remover um elemento\n");
        printf("5. Imprimir a AVL em ordem\n");
        printf("6. Mostrar a quantidade de nós na AVL\n");
        printf("7. Destruir a AVL\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                arvore = criaAVL();
                printf("Árvore AVL criada.\n");
                break;

            case 2:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &elem);
                if (insereElem(arvore, elem)) {
                    printf("Elemento inserido com sucesso.\n");
                } else {
                    printf("Falha ao inserir o elemento.\n");
                }
                break;

            case 3:
                printf("Digite o elemento a ser buscado: ");
                scanf("%d", &elem);
                if (pesquisa(arvore, elem)) {
                    printf("Elemento encontrado na árvore.\n");
                } else {
                    printf("Elemento não encontrado na árvore.\n");
                }
                break;

            case 4:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &elem);
                if (removeElem(arvore, elem)) {
                    printf("Elemento removido com sucesso.\n");
                } else {
                    printf("Falha ao remover o elemento.\n");
                }
                break;

            case 5:
                printf("Imprimir árvore em ordem:\n");
                imprime(arvore);
                break;

            case 6:
                printf("Quantidade de nós na árvore: %d\n", countNodes(arvore));
                break;

            case 7:
                destroiAVL(arvore);
                printf("Árvore destruída.\n");
                break;

            case 8:
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 8);

    destroiAVL(arvore);
    return 0;
}
