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

void selectionSort(int *A, int n) {
    int i, j, min;
    for (i = 0; i < n; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        troca(&A[min], &A[i]);
    }
}

void insertionSort(int *A, int n) {
    int i, j;
    int x;
    for (j = 1; j < n; j++) {
        x = A[j];
        i = j - 1;
        while (i >= 0 && x < A[i]) {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
    }
}

void shellSort(int *A, int n) {
    int i, j;
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (i = h; i < n; i++) {
            for (j = i; j >= h && A[j] < A[j - h]; j -= h) {
                troca(&A[j], &A[j - h]);
            }
        }
        h = h / 3;
    }
}

void printArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    },
    printf("\n");
}

int main() {
    int exponent = 19; // Expoente
    int n = (int) pow(2, exponent); // Tamanho do vetor como uma potência de 2
    int *A = (int*) malloc(n * sizeof(int));

    // Definindo uma semente fixa para os números aleatórios
    int seed = 42;
    srand(seed);

    for (int i = 0; i < n; i++) {
        A[i] = rand() % 81 - 50; // rand() % 81 gera um número entre (0 e 80) - 50
    }

    printf("Array antes da ordenação:\n");
//    printArray(A, n);

    struct timeval ini, fim;

    gettimeofday(&ini, 0);
    
    // Descomente uma das linhas abaixo para testar o algoritmo de ordenação desejado

    // bubbleSort(A, n);
     selectionSort(A, n);
    // insertionSort(A, n);
    // shellSort(A, n);

    gettimeofday(&fim, 0);
    double tempo = (fim.tv_sec - ini.tv_sec) + (fim.tv_usec - ini.tv_usec) * 1e-6;
    printf("Tempo: %.5f ms\n", tempo * 1000); // Tempo em milissegundos

    printf("Array depois da ordenação:\n");
//    printArray(A, n);
    
    free(A);
    return 0;
}
