#include <stdio.h>
#include "Trie.h"

int main(){
    // Chaves de entrada (use apenas 'a' a 'z' em minúsculas)
    char chaves[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    char saida[][32] = {"Nao encontrada na TRIE", "Encontrada na TRIE"};

    NO *raiz = criaNO();
    int i;
    for (i = 0; i < 8; i++)
        inserir(raiz, chaves[i]);

    printf("%s --- %s\n", "the", saida[buscar(raiz, "the")]);
    printf("%s --- %s\n", "these", saida[buscar(raiz, "these")]);
    printf("%s --- %s\n", "their", saida[buscar(raiz, "their")]);
    printf("%s --- %s\n", "thaw", saida[buscar(raiz, "thaw")]);

    printf("\n\n----------Impressao FINAL:\n");
    imprimeTrie(raiz);

    return 0;
}
