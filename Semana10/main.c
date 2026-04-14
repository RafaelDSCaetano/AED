#include <stdio.h>
#include <string.h>
#include "expressao.h"
#include "contador.h"
#include "corretor.h"

void readExpr(Expressao *e) {
    printf("Digite uma operação matemática contendo parênteses, colchetes e chaves: \n");
    fgets(e->expr, sizeof(e->expr), stdin);

    // Tirar o caractere '\n'
    size_t len = strlen(e->expr);
    if (len > 0 && e->expr[len - 1] == '\n') {
        e->expr[len - 1] = '\0';
    }
}

void contaParenteses(const char *expr, Contador *c) {
    c->parenteses = 0;
    size_t j = strlen(expr);

    for (size_t i = 0; i < j; i++) {
        if (expr[i] == '(') {
            c->parenteses++;
        } else if (expr[i] == ')') {
            c->parenteses--;
        }
    }
}

void contaColchetes(const char *expr, Contador *c) {
    c->colchetes = 0;
    size_t j = strlen(expr);

    for (size_t i = 0; i < j; i++) {
        if (expr[i] == '[') {
            c->colchetes++;
        } else if (expr[i] == ']') {
            c->colchetes--;
        }
    }
}

void contaChaves(const char *expr, Contador *c) {
    c->chaves = 0;
    size_t j = strlen(expr);

    for (size_t i = 0; i < j; i++) {
        if (expr[i] == '{') {
            c->chaves++;
        } else if (expr[i] == '}') {
            c->chaves--;
        }
    }
}

void corrigeExpr(const char *expr, Contador c, Corretor *cor) {
    strcpy(cor->expr, expr);
    size_t len = strlen(cor->expr);

    // Adicionar parênteses, colchetes e chaves corretivos no final da expressão
    while (c.parenteses > 0) {
        cor->expr[len++] = ')';
        c.parenteses--;
    }
    while (c.colchetes > 0) {
        cor->expr[len++] = ']';
        c.colchetes--;
    }
    while (c.chaves > 0) {
        cor->expr[len++] = '}';
        c.chaves--;
    }
    cor->expr[len] = '\0'; // Certificar-se de terminar a string corretamente
}

int main() {
    Expressao e;
    Contador c;
    Corretor cor;

    readExpr(&e);
    printf("Você digitou: %s\n", e.expr);

    contaParenteses(e.expr, &c);
    contaColchetes(e.expr, &c);
    contaChaves(e.expr, &c);

    if (c.parenteses == 0 && c.colchetes == 0 && c.chaves == 0) {
        printf("A expressão está corretamente balanceada.\n");
    } else {
        printf("A expressão não está balanceada.\n");
        printf("Número de parênteses, colchetes e chaves faltando: %d, %d, %d\n", c.parenteses, c.colchetes, c.chaves);
    }

    corrigeExpr(e.expr, c, &cor);
    printf("Nova expressão: %s\n", cor.expr);

    return 0;
}
