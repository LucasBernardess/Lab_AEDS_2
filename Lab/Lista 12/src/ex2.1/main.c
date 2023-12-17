#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main() {
    Hash *hash_divisao = criaHash(10);
    Hash *hash_multiplicacao = criaHash(10);
    Hash *hash_dobra = criaHash(10);

    int elementos[] = {12, 34, 56, 78, 90, 23, 45, 67, 89, 10};

    int i;
    for (i = 0; i < 10; i++) {
        insereHash_semTratar(hash_divisao, elementos[i], chaveDivisao);
        insereHash_semTratar(hash_multiplicacao, elementos[i], chaveMultiplicacao);
        insereHash_semTratar(hash_dobra, elementos[i], chaveDobra);
    }

    printf("Tabela Hash com função de hashing de Divisão:\n");
    imprimeHash(hash_divisao);

    printf("\nTabela Hash com função de hashing de Multiplicação:\n");
    imprimeHash(hash_multiplicacao);

    printf("\nTabela Hash com função de hashing de Dobra:\n");
    imprimeHash(hash_dobra);

    int elemento_busca = 56;
    int encontrado = 0;
    printf("\nBusca pelo elemento %d:\n", elemento_busca);
    encontrado = buscaHash_semTratar(hash_divisao, elemento_busca, chaveDivisao, &elemento_busca);
    if (encontrado)
        printf("Elemento %d encontrado na tabela com função de hashing de Divisão.\n", elemento_busca);
    else
        printf("Elemento %d não encontrado na tabela com função de hashing de Divisão.\n", elemento_busca);

    encontrado = buscaHash_semTratar(hash_multiplicacao, elemento_busca, chaveMultiplicacao, &elemento_busca);
    if (encontrado)
        printf("Elemento %d encontrado na tabela com função de hashing de Multiplicação.\n", elemento_busca);
    else
        printf("Elemento %d não encontrado na tabela com função de hashing de Multiplicação.\n", elemento_busca);

    encontrado = buscaHash_semTratar(hash_dobra, elemento_busca, chaveDobra, &elemento_busca);
    if (encontrado)
        printf("Elemento %d encontrado na tabela com função de hashing de Dobra.\n", elemento_busca);
    else
        printf("Elemento %d não encontrado na tabela com função de hashing de Dobra.\n", elemento_busca);

    destroiHash(hash_divisao);
    destroiHash(hash_multiplicacao);
    destroiHash(hash_dobra);

    return 0;
}