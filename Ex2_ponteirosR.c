#include <stdio.h>
#define VETOR {1, 2, 3, 4, 5, 6, 7, 8, 9}

int maiores(int n, int *vet, int x) {
    int contador = 0;

    for (int i = 0; i < n; i++) {
        if (vet[i] > x) {
            contador++;
        }
    }

    return contador;
}

int main() {
    int vet[] = VETOR;
    int tamanho = sizeof(vet) / sizeof(vet[0]);
    int x;

    printf("Digite o valor de x: ");
    scanf("%d", &x);

    int quantidade = maiores(tamanho, vet, x);
    printf("Quantidade de números maiores que %d: %d\n", x, quantidade);

    return 0;
}
