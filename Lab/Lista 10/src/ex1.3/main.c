#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void selectionSort(int arr[], int n, long *comparacoes, long *movimentacoes) {
    int i, j, minIndex, temp;
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                (*comparacoes)++;
                minIndex = j;
            }
        }
        if (minIndex != i) {
            (*comparacoes)++;
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            (*movimentacoes) += 3; // Incrementa o número de movimentações (3 trocas)
        }
    }
}

void insertionSort(int arr[], int n, long *comparacoes, long *movimentacoes) {
    int i, chave, j;
    
    for (i = 1; i < n; i++) {
        chave = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > chave) {
            (*comparacoes)++; // Incrementa o número de comparações
            arr[j + 1] = arr[j];
            (*movimentacoes)++; // Incrementa o número de movimentações
            j = j - 1;
        }
        arr[j + 1] = chave;
        (*movimentacoes)++; // Incrementa o número de movimentações
    }
}

void medirDesempenho(int *valores, int tamanho, char *tipoOrdenacao) {
    int *copiaValores = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; ++i) {
        copiaValores[i] = valores[i];
    }

    clock_t inicio, fim;
    double tempoExecucao;
    long comparacoes = 0, movimentacoes = 0;

    inicio = clock();
    if (strcmp(tipoOrdenacao, "Selecao") == 0) {
        selectionSort(copiaValores, tamanho, &comparacoes, &movimentacoes);
    } else if (strcmp(tipoOrdenacao, "Insercao") == 0) {
        insertionSort(copiaValores, tamanho, &comparacoes, &movimentacoes);
    } else {
        printf("Algoritmo de ordenação não está disponível\n");
        free(copiaValores);
        return;
    }
    fim = clock();

    tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tipo de ordenacao: %s\n", tipoOrdenacao);
    printf("Tempo de execucao: %f segundos\n", tempoExecucao);
    printf("Numero de comparações: %ld\n", comparacoes);
    printf("Numero de movimentações: %ld\n\n", movimentacoes);

    free(copiaValores);
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <nome_do_arquivo>\n", argv[0]);
        return 1;
    }

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int tamanho;
    fscanf(arquivo, "%d", &tamanho);

    int *valores = (int *)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        fscanf(arquivo, "%d", &valores[i]);
    }

    fclose(arquivo);

    medirDesempenho(valores, tamanho, "Selecao");
    medirDesempenho(valores, tamanho, "Insercao");

    free(valores);

    return 0;
}
