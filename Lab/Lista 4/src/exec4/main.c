#include <stdio.h>
#include "LC.h"

int main(){
    Lista *L;
    L = criaLista();

    insereFim(L, 10);
    insereFim(L, 20);
    insereFim(L, 30);
    insereFim(L, 40);
    insereFim(L, 50);
    insereFim(L, 60);
    insereFim(L, 70);
    insereFim(L, 80);
    insereFim(L, 90);

    removeIni(L);
    removeFim(L);

    imprimeLista(L);
    printf("tamanho -> %d\n", tamanho(L));
    printf("procura -> %d\n", procura(L, 50));

    destroiLista(L);


    return 0;
}