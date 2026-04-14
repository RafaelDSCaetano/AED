#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
#include <math.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *A, int n) {
    int i;
    bool trocado;
    do {
        trocado = false;
        for (i = 1; i < n; i++) {
            if (A[i - 1] > A[i]) {
                troca(&A[i - 1], &A[i]);
                trocado = true;
            }
        }
    } while (trocado);
}

void merge(int *arr, int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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

    free(L);
    free(R);
}

void mergeSort(int *arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 3500;   
    int *arr = (int*) malloc(n * sizeof(int));
    int arr_size = n;

    

    int seed = 42;
    srand(seed);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    printf("Array antes da ordenação:\n");

    struct timeval ini, fim;

    printf("Array original: \n");
    printArray(arr, arr_size);

    int choice;
    printf("Escolha o algoritmo de ordenação:\n1. Quick Sort\n2. Merge Sort\n3. Bubble Sort\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            gettimeofday(&ini, 0);
            quickSort(arr, 0, arr_size - 1);
            printf("Array ordenado usando Quick Sort: \n");
            break;
        case 2:
            gettimeofday(&ini, 0);
            mergeSort(arr, 0, arr_size - 1);
            printf("Array ordenado usando Merge Sort: \n");
            break;
        case 3:
            gettimeofday(&ini, 0);
            bubbleSort(arr, arr_size);
            printf("Array ordenado usando Bubble Sort: \n");
            break;
        default:
            printf("Escolha inválida\n");
            return 1;
    }

    printArray(arr, arr_size);
    
    gettimeofday(&fim, 0);
    double tempo = (fim.tv_sec - ini.tv_sec) + (fim.tv_usec - ini.tv_usec) * 1e-6;
    printf("Tempo: %.5f ms\n", tempo * 1000); // Tempo em milissegundos
    
    return 0;
}
