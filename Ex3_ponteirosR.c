#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float soma_inferior(float **mat, int n) {
    float soma = 0.0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            soma += mat[i][j];
        }
    }

    return soma;
}

int main() {
    srand(time(NULL));

    int n;
    printf("Digite a dimensao da matriz quadrada: ");
    scanf("%d", &n);
    float **mat = malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++) {
        mat[i] = malloc(n * sizeof(float));
        for (int j = 0; j < n; j++) {
            mat[i][j] = (rand() % 100) + ((rand() % 100)/100.0); // Gera um número aleatório entre 0 e 100
        }
    }

    printf("Matriz gerada:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }

    float resultado = soma_inferior(mat, n);
    printf("Soma dos elementos abaixo da diagonal principal: %.2f\n", resultado);

    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
