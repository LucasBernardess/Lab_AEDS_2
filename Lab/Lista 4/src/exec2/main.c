#include <stdio.h>
#include "Lista_se.h"

int main(){
    Lista *L;
    L = criaLista();

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 20);
    insereFim(L, 20);
    insereFim(L, 20);
    insereFim(L, 30);
    InsereOrdenado(L, 25);

    removeIni(L);
    printf("procura -> %d\n", procura(L, 210));
    removePrimeiraOcorrencia(L, 20);
    imprimeLista(L);
    printf("tamanho -> %d\n", tamanho(L));

    destroiLista(L);
    return 0;
}