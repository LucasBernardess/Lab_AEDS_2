#ifndef FSE_H
#define FSE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NO{
    int info ;
    struct NO* prox ;
}NO;

typedef struct {
    int qtd;
    struct NO* ini;
    struct NO* fim;
}Fila;


Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    if (fila != NULL) {
        fila->qtd = 0;
        fila->ini = NULL;
        fila->fim = NULL;
    }
    return fila;
}


int filaVazia(Fila* fila) {
    return (fila == NULL || fila->qtd == 0);
}

bool enfileirar(Fila* fila, int valor) {
    if (fila == NULL)
        return false;

    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL)
        return false;

    novo->info = valor;
    novo->prox = NULL;

    if (fila->qtd == 0) {
        fila->ini = novo;
        fila->fim = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }

    fila->qtd++;
    return true;
}


bool desenfileirar(Fila* fila, int* valor) {
    if (fila == NULL || fila->qtd == 0)
        return false;

    NO* temp = fila->ini;
    *valor = temp->info;

    if (fila->qtd == 1) {
        fila->ini = NULL;
        fila->fim = NULL;
    } else {
        fila->ini = temp->prox;
    }

    free(temp);
    fila->qtd--;
    return true;
}

void imprimirFila(Fila* fila) {
    if (fila == NULL || fila->qtd == 0) {
        printf("Fila vazia.\n");
        return;
    }

    NO* atual = fila->ini;
    printf("Fila: ");
    while (atual != NULL) {
        printf("%d ", atual->info);
        atual = atual->prox;
    }
    printf("\n");
}

int primeiroElemento(Fila* fila, int* valor) {
    if (fila == NULL || fila->qtd == 0)
        return 0;

    *valor = fila->ini->info;
    return 1;
}

void liberarFila(Fila* fila) {
    if (fila != NULL) {
        NO* atual = fila->ini;
        while (atual != NULL) {
            NO* temp = atual;
            atual = atual->prox;
            free(temp);
        }
        free(fila);
    }
}

#endif
