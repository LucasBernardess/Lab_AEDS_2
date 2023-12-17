#include <stdio.h>
#include <stdlib.h>
#include "pse.h"

int main(){
    Pilha* P;
    int valor;
    P = criarPilha(P);
    empilhar(P,20);
    empilhar(P,30);
    empilhar(P,40);
    empilhar(P,50);
    imprimirPilha(P);
    topoPilha(P, &valor);
    printf("Topo -> %d\n", valor);
    desempilhar(P, &valor);
    topoPilha(P, &valor);
    printf("Topo -> %d\n", valor);
    imprimirPilha(P);
    liberarPilha(P);
}