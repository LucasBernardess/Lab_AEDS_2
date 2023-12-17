#include <stdio.h>
#include <stdbool.h>
#include "fse.h"

int main(){
    Fila* F;
    F = criarFila(F);
    filaVazia(F);
    enfileirar(F, 7);
    enfileirar(F,8);
    enfileirar(F,9);
    int valor;
    desenfileirar(F, &valor);
    printf("Desenfileirado -> %d\n", valor);
    int primeiro;
    primeiroElemento(F, &primeiro);
    printf("%d\n", primeiro);
    imprimirFila(F);
    liberarFila(F);
}
