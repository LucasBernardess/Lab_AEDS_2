#include <stdio.h>
#include "LDE.h"

int main(){
    Lista *L;
    L = criaLista();

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 20);
    insereFim(L, 30);
    insereFim(L, 50);
    insereFim(L, 60);
    insereFim(L, 70);
    insereFim(L, 80);
    insereFim(L, 90);
    InsereOrdenado(L,25);

    removePrimeiraOcorrencia(L,40);
    removeIni(L);
    removeFim(L);

    printf("procura -> %d\n", procura(L,300));
    imprimeLista(L);
    printf("tamanho -> %d\n", tamanho(L));
    destroiLista(L);

    return 0;
}