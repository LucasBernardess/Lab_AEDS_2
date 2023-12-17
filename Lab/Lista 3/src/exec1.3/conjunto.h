#ifndef CONJUNTO_H
#define CONJUNTO_H
#define MAX_TAM 100
#include <stdbool.h>

typedef struct {
    int elementos[MAX_TAM];
    int tamanho;
} ConjuntoInteiros;

void criarConjuntoVazio(ConjuntoInteiros *conjunto);
void inserirElemento(ConjuntoInteiros *conjunto, int elemento);
void removerElemento(ConjuntoInteiros *conjunto, int elemento);
bool pertenceConjunto(ConjuntoInteiros *conjunto, int elemento);
int menorValor(ConjuntoInteiros *conjunto);
int maiorValor(ConjuntoInteiros *conjunto);
bool conjuntosSaoIguais(ConjuntoInteiros *conjunto1, ConjuntoInteiros *conjunto2);
int tamanhoConjunto(ConjuntoInteiros *conjunto);
bool conjuntoEhVazio(ConjuntoInteiros *conjunto);


#endif