#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
} Pessoa;

// Função de comparação para ordenação
int compararPessoas(const void *a, const void *b) {
    Pessoa *p1 = (Pessoa *)a;
    Pessoa *p2 = (Pessoa *)b;

    // Compara pelo nome
    int comparacaoNomes = strcmp(p1->nome, p2->nome);
    if (comparacaoNomes != 0) {
        return comparacaoNomes;
    } else {
        // Se os nomes forem iguais, compara pela idade
        return p1->idade - p2->idade;
    }
}

void ordenarCrescentePorSelecao(Pessoa vetor[], int tamanho) {
    int i, j, minIndex;
    Pessoa temp;

    for (i = 0; i < tamanho - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < tamanho; j++) {
            if (compararPessoas(&vetor[j], &vetor[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = vetor[i];
            vetor[i] = vetor[minIndex];
            vetor[minIndex] = temp;
        }
    }
}

void ordenarDecrescentePorSelecao(Pessoa vetor[], int tamanho) {
    int i, j, maxIndex;
    Pessoa temp;

    for (i = 0; i < tamanho - 1; i++) {
        maxIndex = i;
        for (j = i + 1; j < tamanho; j++) {
            if (compararPessoas(&vetor[j], &vetor[maxIndex]) > 0) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            temp = vetor[i];
            vetor[i] = vetor[maxIndex];
            vetor[maxIndex] = temp;
        }
    }
}

void ordenarCrescentePorInsercao(Pessoa vetor[], int tamanho) {
    int i, j;
    Pessoa chave;

    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && compararPessoas(&vetor[j], &chave) < 0) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

void ordenarDecrescentePorInsercao(Pessoa vetor[], int tamanho) {
    int i, j;
    Pessoa chave;

    for (i = 1; i < tamanho; i++) {
        chave = vetor[i];
        j = i - 1;

        while (j >= 0 && compararPessoas(&vetor[j], &chave) > 0) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = chave;
    }
}

int main() {
    Pessoa pessoas[] = {
        {"Maria", 25},
        {"Joao", 30},
        {"Ana", 20},
        {"Joao", 25},
        {"Maria", 30}
    };
    int tamanho = sizeof(pessoas) / sizeof(pessoas[0]);

    ordenarCrescentePorSelecao(pessoas, tamanho);
    printf("Ordenacao Crescente por Selecao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s - %d\n", pessoas[i].nome, pessoas[i].idade);
    }
    printf("\n");

    ordenarDecrescentePorSelecao(pessoas, tamanho);
    printf("Ordenacao Decrescente por Selecao:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s - %d\n", pessoas[i].nome, pessoas[i].idade);
    }
    printf("\n");

    ordenarCrescentePorInsercao(pessoas, tamanho);
    printf("Ordenacao Crescente por Insercao:\n");
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%s - %d\n", pessoas[i].nome, pessoas[i].idade);
    }
    printf("\n");

    ordenarDecrescentePorInsercao(pessoas, tamanho);
    printf("Ordenacao Decrescente por Insercao:\n");
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%s - %d\n", pessoas[i].nome, pessoas[i].idade);
    }
    printf("\n");

    return 0;
}
