#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(int *A, int n) {
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

void printArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int n = 10; // Tamanho do vetor
    int A[n];

    // Inicializando o gerador de números aleatórios com a seed 42
    int seed = 42;
    srand(seed);

    // Preenchendo o vetor com números aleatórios no intervalo [-50, 30]
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 81 - 50; // rand() % 81 gera um número entre 0 e 80, então subtraímos 50 para obter o intervalo desejado
    }

    printf("Array antes da ordenação:\n");
    printArray(A, n);

    BubbleSort(A, n);

    printf("Array depois da ordenação:\n");
    printArray(A, n);

    return 0;
}
