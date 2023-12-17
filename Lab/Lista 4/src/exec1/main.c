#include "lista.h"

int main(){
    Lista *L;
    L = criaLista();

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 30);
    insereFim(L, 20);
    insereFim(L, 20);
    printf("Procura -> %d\n", procura(L, 70));
    InsereOrdenado(L, 12);
    removeIni(L);
    removePrimeiraOcorrencia(L, 20);
    imprimeLista(L);
    destroiLista(L);
    return 0;
}