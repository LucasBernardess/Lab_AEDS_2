#include <stdio.h>
#include "hash.h"

int main() {
    Hash *hash = criaHash(10);

    insereHash_comTratamento(hash, 25, chaveDivisao, sondagemLinear);
    insereHash_comTratamento(hash, 10, chaveDivisao, sondagemLinear);
    insereHash_comTratamento(hash, 35, chaveDivisao, sondagemLinear);

    int busca;
    if (buscaHash_comTratamento(hash, 10, chaveDivisao, sondagemLinear, &busca))
        printf("Encontrado: %d\n", busca);
    else
        printf("Não encontrado!\n");

    if (buscaHash_comTratamento(hash, 30, chaveDivisao, sondagemLinear, &busca))
        printf("Encontrado: %d\n", busca);
    else
        printf("Não encontrado!\n");

    printf("Estado do hash:\n");
    imprimeHash(hash);

    destroiHash(hash); 

    return 0;
}
