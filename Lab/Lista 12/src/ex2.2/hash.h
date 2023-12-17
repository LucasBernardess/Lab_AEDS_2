#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int **tabela;
    int tam, qtd;
} Hash;

Hash *criaHash(int t) {
    Hash *h;
    h = (Hash *)malloc(sizeof(Hash));
    if (h != NULL) {
        h->tam = t;
        h->qtd = 0;
        h->tabela = (int **)malloc(t * sizeof(int *));
        if (h->tabela == NULL) return NULL;
        int i;
        for (i = 0; i < t; i++) h->tabela[i] = NULL;
    }
    return h;
}

void destroiHash(Hash *h) {
    if (h != NULL) {
        int i;
        for (i = 0; i < h->tam; i++)
            if (h->tabela[i] != NULL) free(h->tabela[i]);
        free(h->tabela);
        free(h);
    }
}

int chaveDivisao(int chave, int tam) {
    return (chave & 0x7FFFFFFF) % tam;
}

int sondagemLinear(int elem, int i) {
    return i; 
}

int sondagemQuadratica(int elem, int i) {
    return i * i; 
}

int sondagemDuploHash(int elem, int i) {
    return (i * chaveDivisao(elem, 7)) + 1; 
}

int insereHash_comTratamento(Hash *h, int elem, int (*funcaoHash)(int, int), int (*funcaoSondagem)(int, int)) {
    if (h == NULL) return 0;
    int pos = funcaoHash(elem, h->tam);

    int i = 0;
    while (h->tabela[pos] != NULL && i < h->tam) {
        pos = (pos + funcaoSondagem(elem, i)) % h->tam;
        i++;
    }

    if (i == h->tam) return 0; // Tabela cheia

    int *novo = (int *)malloc(sizeof(int));
    if (novo == NULL) return 0;
    *novo = elem;
    h->tabela[pos] = novo;
    h->qtd++;

    return 1;
}

int buscaHash_comTratamento(Hash *h, int elem, int (*funcaoHash)(int, int), int (*funcaoSondagem)(int, int), int *p) {
    if (h == NULL) return 0;
    int pos = funcaoHash(elem, h->tam);

    int i = 0;
    while (h->tabela[pos] != NULL && i < h->tam) {
        if (*(h->tabela[pos]) == elem) {
            *p = *(h->tabela[pos]);
            return 1;
        }
        pos = (pos + funcaoSondagem(elem, i)) % h->tam;
        i++;
    }

    return 0;
}

void imprimeHash(Hash *h) {
    if (h == NULL) return;
    int i;
    for (i = 0; i < h->tam; i++) {
        printf("%d: ", i);
        if (h->tabela[i] == NULL)
            printf("NULL\n");
        else
            printf("%d\n", *(h->tabela[i]));
    }
}

#endif
