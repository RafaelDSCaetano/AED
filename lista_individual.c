#include <stdio.h>
#include <stdlib.h>


struct No {
    int dado;
    struct No* proximo;
};

struct No* criarNo(int dado) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = dado;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNoFinal(struct No** cabeca, int dado) {
    struct No* novoNo = criarNo(dado);
    if (*cabeca == NULL) {
        *cabeca = novoNo;
        return;
    }
    struct No* temp = *cabeca;
    while (temp->proximo != NULL) {
        temp = temp->proximo;
    }
    temp->proximo = novoNo;
}

struct No* encontrarCentral(struct No* cabeca) {
    struct No* lento = cabeca;
    struct No* rapido = cabeca;

    while (rapido != NULL && rapido->proximo != NULL) {
        lento = lento->proximo;
        rapido = rapido->proximo->proximo;
    }
    
    return lento;
}

void imprimirLista(struct No* cabeca) {
    struct No* temp = cabeca;
    while (temp != NULL) {
        printf("%d -> ", temp->dado);
        temp = temp->proximo;
    }
    printf("NULL\n");
}
int main() {
    // Criando a lista 1 -> 2 -> 3 -> 4 -> 5
    struct No* cabeca = NULL;
    inserirNoFinal(&cabeca, 1);
    inserirNoFinal(&cabeca, 2);
    inserirNoFinal(&cabeca, 3);
    inserirNoFinal(&cabeca, 4);
    inserirNoFinal(&cabeca, 5);

    printf("Lista: ");
    imprimirLista(cabeca);

    struct No* central = encontrarCentral(cabeca);
    printf("Elemento central: %d\n", central->dado);

    inserirNoFinal(&cabeca, 6);

    printf("Lista: ");
    imprimirLista(cabeca);

    central = encontrarCentral(cabeca);
    printf("Elemento central: %d\n", central->dado);

    return 0;
}
