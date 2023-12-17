#include <stdio.h>

void shellsort(int arr[], int num);
void quickSort(int array[], int low, int high);
void mergeSort(int arr[], int l, int r);
void heapSort(int arr[], int n);
void printArray(int arr[], int n);
void swap(int *a, int *b);
int partition(int array[], int low, int high);
void merge(int arr[], int l, int m, int r);
void heapify(int arr[], int n, int i);

void shellsort(int arr[], int num) {
    int i, j, k, tmp;
    for (i = num / 2; i > 0; i = i / 2) {
        for (j = i; j < num; j++) {
            for (k = j - i; k >= 0; k = k - i) {
                if (arr[k + i] >= arr[k]) { // Modificação aqui
                    tmp = arr[k];
                    arr[k] = arr[k + i];
                    arr[k + i] = tmp;
                } else {
                    break;
                }
            }
        }
    }
}


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] >= pivot) { 
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) { 
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[largest])
        largest = left;

    if (right < n && arr[right] < arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int vetor[n];

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    shellsort(vetor, n);
    printf("<----- Shellsort ----->\n");
    printArray(vetor, n);

    int vetor_quick[n];
    for (int i = 0; i < n; i++) {
        vetor_quick[i] = vetor[i];
    }
    printf("<----- Quicksort ----->\n");
    quickSort(vetor_quick, 0, n - 1);
    printArray(vetor_quick, n);

    int vetor_merge[n];
    for (int i = 0; i < n; i++) {
        vetor_merge[i] = vetor[i];
    }
    printf("<----- Mergesort ----->\n");
    mergeSort(vetor_merge, 0, n - 1);
    printArray(vetor_merge, n);

    int vetor_heap[n];
    for (int i = 0; i < n; i++) {
        vetor_heap[i] = vetor[i];
    }
    heapSort(vetor_heap, n);
    printf("<----- Heapsort ----->\n");
    printArray(vetor_heap, n);

    return 0;
}