#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void shellsort(int arr[], int num, int *comparacoes, int *movimentacoes) {
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2) {
        for (j = i; j < num; j++) {
            for (k = j - i; k >= 0; k = k - i) {
                (*comparacoes) += 2;
                if (arr[k + i] >= arr[k])
                    break;
                else {
                    tmp = arr[k];
                    arr[k] = arr[k + i];
                    arr[k + i] = tmp;
                    (*movimentacoes) += 3;
                }
            }
        }
    }
}

void swap(int *a, int *b, int *comparacoes, int *movimentacoes) {
    int t = *a;
    *a = *b;
    *b = t;
}

int medianOfThree(int array[], int low, int high, int *comparacoes, int *movimentacoes) {
    int mid = low + (high - low) / 2;

    if (array[low] > array[mid]) {
        swap(&array[low], &array[mid], comparacoes, movimentacoes);
    }
    if (array[low] > array[high]) {
        swap(&array[low], &array[high], comparacoes, movimentacoes);
    }
    if (array[mid] > array[high]) {
        swap(&array[mid], &array[high], comparacoes, movimentacoes);
    }

    swap(&array[mid], &array[high - 1], comparacoes, movimentacoes);
    return array[high - 1];
}

int partition(int array[], int low, int high, int *comparacoes, int *movimentacoes) {
    int pivot = medianOfThree(array, low, high, comparacoes, movimentacoes);
    int i = low - 1;
    int j;

    for (j = low; j < high; j++) {
        (*comparacoes)++;
        if (array[j] < pivot) {
            i++;
            if (i != j) {
                swap(&array[i], &array[j], comparacoes, movimentacoes);
                (*movimentacoes)++;
            }
        }
    }

    swap(&array[i + 1], &array[high], comparacoes, movimentacoes);
    (*movimentacoes)++;
    return (i + 1);
}

void quickSort(int array[], int low, int high, int *comparacoes, int *movimentacoes) {
    if (low < high) {
        (*comparacoes)++;
        int pi = partition(array, low, high, comparacoes, movimentacoes);
        quickSort(array, low, pi - 1, comparacoes, movimentacoes);
        quickSort(array, pi + 1, high, comparacoes, movimentacoes);
    }
}


void merge(int arr[], int l, int m, int r, int *comparacoes, int *movimentacoes) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    (*comparacoes)++;
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    (*comparacoes)++;

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        (*comparacoes)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
           (*movimentacoes)++;
        }
        else {
            arr[k] = R[j];
            j++;
           (*movimentacoes)++;
        }
        k++;
        (*comparacoes)++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*comparacoes)++;
        (*movimentacoes)++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*comparacoes)++;
        (*movimentacoes)++;
    }
}

void mergeSort(int arr[], int l, int r, int *comparacoes, int *movimentacoes) {
    if (l < r) {
        (*comparacoes)++;
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparacoes, movimentacoes);
        mergeSort(arr, m + 1, r, comparacoes, movimentacoes);
        merge(arr, l, m, r, comparacoes, movimentacoes);
    }
}

void heapify(int arr[], int n, int i, int *comparacoes, int *movimentacoes) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]){
      (*comparacoes)++;
      largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
      largest = right;
      (*comparacoes)++;
    }
    if (largest != i) {
      (*comparacoes)++;
      swap(&arr[i], &arr[largest], comparacoes, movimentacoes);
      (*movimentacoes) += 2;
      heapify(arr, n, largest, comparacoes, movimentacoes);
    }
}

void heapSort(int arr[], int n, int *comparacoes, int *movimentacoes) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i,  comparacoes, movimentacoes);
        (*comparacoes)++;
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i],  comparacoes, movimentacoes);
        heapify(arr, i, 0,  comparacoes, movimentacoes);
        (*comparacoes)++;
        (*movimentacoes) += 2;
    }
}

void medirDesempenho(int *valores, int tamanho, char *tipoOrdenacao) {
    int *copiaValores = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; ++i) {
        copiaValores[i] = valores[i];
    }

    clock_t inicio, fim;
    double tempoExecucao;
    int comparacoes = 0, movimentacoes = 0;

    inicio = clock();
    if (strcmp(tipoOrdenacao, "Shellsort") == 0) {
        shellsort(copiaValores, tamanho-1, &comparacoes, &movimentacoes);
    } else if (strcmp(tipoOrdenacao, "Quicksort") == 0) {
        quickSort(copiaValores,0, tamanho-1, &comparacoes, &movimentacoes);
    }else if(strcmp(tipoOrdenacao, "Mergesort") == 0){
        mergeSort(copiaValores, 0, tamanho-1, &comparacoes, &movimentacoes);
    }else if(strcmp(tipoOrdenacao, "Heapsort") == 0){
        heapSort(copiaValores, tamanho-1, &comparacoes, &movimentacoes);
    }
    else {
        printf("Algoritmo de ordenação não está disponível\n");
        free(copiaValores);
        return;
    }
    fim = clock();

    tempoExecucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tipo de ordenacao: %s\n", tipoOrdenacao);
    printf("Tempo de execucao: %f segundos\n", tempoExecucao);
    printf("Numero de comparações: %d\n", comparacoes);
    printf("Numero de movimentações: %d\n\n", movimentacoes);

    free(copiaValores);
}

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

    medirDesempenho(valores, tamanho, "Shellsort");
    medirDesempenho(valores, tamanho, "Quicksort");
    medirDesempenho(valores, tamanho, "Mergesort");
    medirDesempenho(valores, tamanho, "Heapsort");

    free(valores);

    return 0;
}
