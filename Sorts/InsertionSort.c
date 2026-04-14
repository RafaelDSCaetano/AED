#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int *A, int n)
{
    int i, j;
    int x;
    for (j = 1; j < n; j++)
    {
        x = A[j];
        i = j - 1;
        while (i >= 0 && x < A[i])
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = x;
    }
}

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    struct timeval ini, fim;

    int n = 1000; // Tamanho do vetor
    int A[n];

    // Inicializando o gerador de números aleatórios com a seed 42
    int seed = 42;
    srand(seed);

    // Preenchendo o vetor com números aleatórios no intervalo [-50, 30]
    for (int i = 0; i < n; i++)
    {
        A[i] = rand() % 81 - 50; // rand() % 81 gera um número entre 0 e 80, então subtraímos 50 para obter o intervalo desejado
    }

    printf("Array antes da ordenação:\n");
    printArray(A, n);

    gettimeofday(&ini, 0); /* funcao que se quer medir o tempo*/

    insertionSort(A, n);

    gettimeofday(&fim, 0);
    double tempo = (fim.tv_sec - ini.tv_sec) + (fim.tv_usec -ini.tv_usec) *1e-6;
    printf("\nTempo: %.5f\n", tempo * 1000); // tempo em milissegundos

    

    printf("Array depois da ordenação:\n");
    printArray(A, n);

    return 0;
}
