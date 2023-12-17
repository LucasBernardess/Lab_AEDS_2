#include <stdio.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("\ninsertionSort \n");
    for(int i = 0; i < n; i++){
        printf(" %d", arr[i]);
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] > arr[min_idx])
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }

    printf("\nselectionSort\n");
    for(int i = 0; i < n; i++){
        printf(" %d", arr[i]);
    }
}

void bubble_sort(int arr[], int n) {
    int c, d, t;

    for (c = 0 ; c < n - 1; c++) {
        for (d = 0 ; d < n - c - 1; d++) {
            if (arr[d] < arr[d+1]) {
            t = arr[d];
            arr[d] = arr[d+1];
            arr[d+1] = t;
            }
        }
    }
    printf("\nbubble_sort\n");
    for(int i = 0; i < n; i++){
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main(){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int vetor[n];
    for(int i = 0; i < n; i++){
        printf("Digite o número que você quer inserir no vetor:");
        scanf("%d", &vetor[i]);
    }
    insertionSort(vetor, n);
    selectionSort(vetor, n);
    bubble_sort(vetor, n);

    return 0;
}

