#include "conjunto.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    ConjuntoInteiros conjunto1, conjunto2;
    criarConjuntoVazio(&conjunto1);
    criarConjuntoVazio(&conjunto2);

    inserirElemento(&conjunto1, 1);
    inserirElemento(&conjunto1, 2);
    inserirElemento(&conjunto1, 3);

    inserirElemento(&conjunto2, 2);
    inserirElemento(&conjunto2, 3);
    inserirElemento(&conjunto2, 4);

    printf("Conjunto 1: ");
    for (int i = 0; i < conjunto1.tamanho; i++) {
        printf("%d ", conjunto1.elementos[i]);
    }
    printf("\n");

    printf("Conjunto 2: ");
    for (int i = 0; i < conjunto2.tamanho; i++) {
        printf("%d ", conjunto2.elementos[i]);
    }
    printf("\n");

    printf("União dos conjuntos: ");
    for (int i = 0; i < conjunto1.tamanho; i++) {
        printf("%d ", conjunto1.elementos[i]);
    }
    for (int i = 0; i < conjunto2.tamanho; i++) {
        if (!pertenceConjunto(&conjunto1, conjunto2.elementos[i])) {
            printf("%d ", conjunto2.elementos[i]);
        }
    }
    printf("\n");

    printf("Interseção dos conjuntos: ");
    for (int i = 0; i < conjunto1.tamanho; i++) {
        if (pertenceConjunto(&conjunto2, conjunto1.elementos[i])) {
            printf("%d ", conjunto1.elementos[i]);
        }
    }
    printf("\n");

    printf("Diferença dos conjuntos (Conjunto 1 - Conjunto 2): ");
    for (int i = 0; i < conjunto1.tamanho; i++) {
        if (!pertenceConjunto(&conjunto2, conjunto1.elementos[i])) {
            printf("%d ", conjunto1.elementos[i]);
        }
    }
    printf("\n");

    printf("O número 2 pertence ao Conjunto 1: %s\n", pertenceConjunto(&conjunto1, 2) ? "Sim" : "Não");

    printf("Menor valor do Conjunto 1: %d\n", menorValor(&conjunto1));
    printf("Maior valor do Conjunto 1: %d\n", maiorValor(&conjunto1));

    printf("Conjunto 1 e Conjunto 2 são iguais: %s\n", conjuntosSaoIguais(&conjunto1, &conjunto2) ? "Sim" : "Não");

    printf("Tamanho do Conjunto 1: %d\n", tamanhoConjunto(&conjunto1));
    printf("Tamanho do Conjunto 2: %d\n", tamanhoConjunto(&conjunto2));

    if(conjuntoEhVazio(&conjunto1) == 0)
        printf("Conjunto 1 é vazio: não\n");
    else
        printf("Conjunto 1 é vazio: sim\n");
}