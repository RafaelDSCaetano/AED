#include <stdio.h>
#include <stdlib.h>

typedef struct NoArv {
    int valor;
    struct NoArv* esquerda;
    struct NoArv* direita;
} NoArv;

NoArv* novo(int valor) {
    NoArv* no = (NoArv*)malloc(sizeof(NoArv));
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    return no;
}

NoArv* cria_arv(int* v, int inicio, int fim) {
    if (inicio > fim) {
        return NULL;
    }

    int meio = (inicio + fim) / 2;
    NoArv* raiz = novo(v[meio]);

    raiz->esquerda = cria_arv(v, inicio, meio - 1);
    raiz->direita = cria_arv(v, meio + 1, fim);

    return raiz;
}

NoArv* cria_arvore(int* v, int n) {
    if (n <= 0) {
        return NULL;
    }
    return cria_arv(v, 0, n - 1);
}

void imprime_arv(NoArv* raiz) {
    if (raiz != NULL) {
        imprime_arv(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprime_arv(raiz->direita);
    }
}

void libera_arv(NoArv* raiz) {
    if (raiz != NULL) {
        libera_arv(raiz->esquerda);
        libera_arv(raiz->direita);
        free(raiz);
    }
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 10, 15};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    NoArv* arvore = cria_arvore(vetor, tamanho);
    
    printf("Árvore em ordem: ");
    imprime_arv(arvore);
    printf("\n");

    libera_arv(arvore);
    return 0;
}
