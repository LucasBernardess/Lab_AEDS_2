#include <stdio.h>
#include <stdlib.h>
#include "HASH.h"

int main() {
    // Criação da tabela hash com 10 posições
    Hash *tabela = criaHash(10);

    // Inserção de elementos na tabela hash
    insereHash_comEncadeamento(tabela, 5);
    insereHash_comEncadeamento(tabela, 15);
    insereHash_comEncadeamento(tabela, 25);
    insereHash_comEncadeamento(tabela, 8);
    insereHash_comEncadeamento(tabela, 18);
    insereHash_comEncadeamento(tabela, 28);

    // Impressão da tabela hash
    printf("Tabela Hash:\n");
    imprimeHash(tabela);

    // Busca de elementos na tabela hash
    int valor;
    if (buscaHash_comEncadeamento(tabela, 15, &valor))
        printf("\nO elemento 15 foi encontrado na tabela.\n");
    else
        printf("\nO elemento 15 nao foi encontrado na tabela.\n");

    if (buscaHash_comEncadeamento(tabela, 20, &valor))
        printf("O elemento 20 foi encontrado na tabela.\n");
    else
        printf("O elemento 20 nao foi encontrado na tabela.\n");

    // Destruir tabela hash e liberar memória
    destroiHash(tabela);

    return 0;
}
