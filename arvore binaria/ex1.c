#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *esquerda, *direita;
} No;

No* novoNo(int dado) {
    No* no = (No*)malloc(sizeof(No));
    no->dado = dado;
    no->esquerda = no->direita = NULL;
    return no;
}

No* inserir(No* raiz, int dado, char lado) {
    if (raiz == NULL)
        return novoNo(dado);

    if (lado == 'E')
        raiz->esquerda = inserir(raiz->esquerda, dado, lado);
    else if (lado == 'D')
        raiz->direita = inserir(raiz->direita, dado, lado);

    return raiz;
}

No* encontrarMin(No* raiz) {
    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;
    return raiz;
}

No* encontrarMax(No* raiz) {
    while (raiz->direita != NULL)
        raiz = raiz->direita;
    return raiz;
}

No* removerMin(No* raiz) {
    if (raiz->esquerda == NULL)
        return raiz->direita;
    raiz->esquerda = removerMin(raiz->esquerda);
    return raiz;
}

No* removerMax(No* raiz) {
    if (raiz->direita == NULL)
        return raiz->esquerda;
    raiz->direita = removerMax(raiz->direita);
    return raiz;
}

int contarNos(No* raiz) {
    if (raiz == NULL)
        return 0;
    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

No* balancearArvore(No* raiz) {
    if (raiz == NULL)
        return NULL;

    int contagemEsquerda = contarNos(raiz->esquerda);
    int contagemDireita = contarNos(raiz->direita);

    if (contagemDireita > contagemEsquerda + 2) {
        raiz->esquerda = inserir(raiz->esquerda, raiz->dado, 'D');
        No* noMin = encontrarMin(raiz->direita);
        raiz->dado = noMin->dado;
        raiz->direita = removerMin(raiz->direita);
    } else if (contagemEsquerda > contagemDireita + 2) {
        raiz->direita = inserir(raiz->direita, raiz->dado, 'E');
        No* noMax = encontrarMax(raiz->esquerda);
        raiz->dado = noMax->dado;
        raiz->esquerda = removerMax(raiz->esquerda);
    }

    raiz->esquerda = balancearArvore(raiz->esquerda);
    raiz->direita = balancearArvore(raiz->direita);

    return raiz;
}

void imprimirArvore(No* raiz, int espaco) {
    if (raiz == NULL)
        return;

    espaco += 10;

    imprimirArvore(raiz->direita, espaco);

    printf("\n");
    for (int i = 10; i < espaco; i++){
        printf(" ");
    }
    printf("%d\n", raiz->dado);

    imprimirArvore(raiz->esquerda, espaco);
}

int main() {
    No* raiz = NULL;

    // E - ESQUERDA; D - DIREITA
    raiz = inserir(raiz, 10, 'D');
    raiz = inserir(raiz, 13, 'D');
    raiz = inserir(raiz, 5, 'E');
    raiz = inserir(raiz, 15, 'D');
    raiz = inserir(raiz, 7, 'E');
    raiz = inserir(raiz, 15, 'D');
    raiz = inserir(raiz, 9, 'D');

    printf("Árvore antes do balanceamento:\n");
    imprimirArvore(raiz, 0);

    raiz = balancearArvore(raiz);

    printf("\nÁrvore após o balanceamento:\n");
    imprimirArvore(raiz, 0);

    return 0;
}
