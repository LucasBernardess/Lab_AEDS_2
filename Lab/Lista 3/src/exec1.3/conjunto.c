#include "conjunto.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_TAM 100

void criarConjuntoVazio(ConjuntoInteiros *conjunto) {
    conjunto->tamanho = 0;
}

void inserirElemento(ConjuntoInteiros *conjunto, int elemento) {
    if (conjunto->tamanho < MAX_TAM) {
        conjunto->elementos[conjunto->tamanho] = elemento;
        conjunto->tamanho++;
    }
}

void removerElemento(ConjuntoInteiros *conjunto, int elemento) {
    int i, j;
    for (i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] == elemento) {
            for (j = i; j < conjunto->tamanho - 1; j++) {
                conjunto->elementos[j] = conjunto->elementos[j + 1];
            }
            conjunto->tamanho--;
            break;
        }
    }
}

bool pertenceConjunto(ConjuntoInteiros *conjunto, int elemento) {
    for (int i = 0; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] == elemento) {
            return true;
        }
    }
    return false;
}

int menorValor(ConjuntoInteiros *conjunto) {
    if (conjunto->tamanho == 0) {
        fprintf(stderr, "Conjunto vazio. Não é possível encontrar o menor valor.\n");
        exit(1);
    }

    int menor = conjunto->elementos[0];
    for (int i = 1; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] < menor) {
            menor = conjunto->elementos[i];
        }
    }
    return menor;
}

int maiorValor(ConjuntoInteiros *conjunto) {
    if (conjunto->tamanho == 0) {
        fprintf(stderr, "Conjunto vazio. Não é possível encontrar o maior valor.\n");
        exit(1);
    }

    int maior = conjunto->elementos[0];
    for (int i = 1; i < conjunto->tamanho; i++) {
        if (conjunto->elementos[i] > maior) {
            maior = conjunto->elementos[i];
        }
    }
    return maior;
}

bool conjuntosSaoIguais(ConjuntoInteiros *conjunto1, ConjuntoInteiros *conjunto2) {
    if (conjunto1->tamanho != conjunto2->tamanho) {
        return false;
    }

    for (int i = 0; i < conjunto1->tamanho; i++) {
        if (!pertenceConjunto(conjunto2, conjunto1->elementos[i])) {
            return false;
        }
    }

    return true;
}

int tamanhoConjunto(ConjuntoInteiros *conjunto) {
    return conjunto->tamanho;
}

bool conjuntoEhVazio(ConjuntoInteiros *conjunto) {
    return conjunto->tamanho == 0;
}