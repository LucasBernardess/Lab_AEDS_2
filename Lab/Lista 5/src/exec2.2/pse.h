#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definição das estruturas
typedef struct NO {
    int info;
    struct NO* prox;
} NO;

typedef struct {
    int qtd;
    struct NO* topo;
} Pilha;

Pilha* criarPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));
    if (pilha != NULL) {
        pilha->qtd = 0;
        pilha->topo = NULL;
    }
    return pilha;
}

bool pilhaVazia(Pilha* pilha) {
    return (pilha == NULL || pilha->qtd == 0);
}

int empilhar(Pilha* pilha, int valor) {
    if (pilha == NULL)
        return 0;

    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL)
        return 0;

    novo->info = valor;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->qtd++;
    return 1;
}

int desempilhar(Pilha* pilha, int* valor) {
    if (pilha == NULL || pilha->qtd == 0)
        return 0;

    NO* temp = pilha->topo;
    *valor = temp->info;
    pilha->topo = temp->prox;
    free(temp);
    pilha->qtd--;
    return 1;
}

int topoPilha(Pilha* pilha, int* valor) {
    if (pilha == NULL || pilha->qtd == 0)
        return 0;

    *valor = pilha->topo->info;
    return 1;
}

void imprimirPilha(Pilha* pilha) {
    if (pilha == NULL || pilha->qtd == 0) {
        printf("Pilha vazia.\n");
        return;
    }

    NO* atual = pilha->topo;
    printf("Pilha: ");
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}

void liberarPilha(Pilha* pilha) {
    if (pilha != NULL) {
        NO* atual = pilha->topo;
        while (atual != NULL) {
            NO* temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(pilha);
    }
}