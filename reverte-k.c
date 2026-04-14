#include <stdio.h>
#include <stdlib.h>

void reverterSegmento(int lista[], int inicio, int fim) {
    int temp;
    while (inicio < fim) {
        temp = lista[inicio];
        lista[inicio] = lista[fim];
        lista[fim] = temp;
        inicio++;
        fim--;
    }
}

void reverterGrupos(int lista[], int tamanho, int k) {
    for (int i = 0; i < tamanho; i += k) {
        int fim = (i + k - 1 < tamanho) ? i + k - 1 : tamanho - 1;
        reverterSegmento(lista, i, fim);
    }
}

void imprimirLista(int lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int lista1[] = {1, 2, 2, 4, 5, 6, 7, 8};
    int tamanho1 = sizeof(lista1) / sizeof(lista1[0]);
    int k1 = 4;

    int lista2[] = {0, 8, 7, 6, 3, 2, 1, 0};
    int tamanho2 = sizeof(lista2) / sizeof(lista2[0]);
    int k2 = 3;

    int lista3[] = {0, 1, 2, 4, 4, 3, 0, 1};
    int tamanho3 = sizeof(lista3) / sizeof(lista3[0]);
    int k3 = 5;


    printf("Lista 1 original:\n");
    imprimirLista(lista1, tamanho1);

    reverterGrupos(lista1, tamanho1, k1);

    printf("\nLista após reverter grupos de %d elementos:\n\n", k1);
    imprimirLista(lista1, tamanho1);

        //lista 2
    printf("Lista 2 original:\n");
    imprimirLista(lista2, tamanho2);

    reverterGrupos(lista2, tamanho2, k2);

    printf("\nLista após reverter grupos de %d elementos:\n\n", k2);
    imprimirLista(lista2, tamanho2);

        //lista 3
    printf("Lista 3 original:\n");
    imprimirLista(lista3, tamanho3);

    reverterGrupos(lista3, tamanho3, k3);

    printf("\nLista após reverter grupos de %d elementos:\n\n", k3);
    imprimirLista(lista3, tamanho3);

    return 0;
}
