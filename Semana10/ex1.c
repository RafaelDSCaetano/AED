#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readExpr(char *buffer, size_t tamanho) {
    printf("Digite uma operação matemática contendo parênteses, colchetes e chaves: \n");
    fgets(buffer, tamanho, stdin);

    // Tirar o caractere '\n'
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }
}

int contaParenteses(const char *expr) {
    int parenteses = 0;
    size_t j = strlen(expr);

    for (size_t i = 0; i < j; i++) {
        if (expr[i] == '(') {
            parenteses++;
        }
        else if (expr[i] == ')' ){
            parenteses--;
        }
    }
    return parenteses;
}

int contaChaves(const char *expr) {
    int chaves = 0;
    size_t j = strlen(expr);

    for (size_t i = 0; i < j; i++) {
        if (expr[i] == '{') {
            chaves++;
        }
        else if (expr[i] == '}' ){
            chaves--;
        }
    }
    return chaves;
}

int contaColchetes(const char *expr) {
    int colchetes = 0;
    size_t j = strlen(expr);

    for (size_t i = 0; i < j; i++) {
        if (expr[i] == '[') {
            colchetes++;
        }
        else if (expr[i] == ']' ){
            colchetes--;
        }
    }
    return colchetes;
}

void corrigeExpr(char *expr, int parenteses, int colchetes, int chaves) {
    size_t len = strlen(expr);
    // Adicionar parênteses, colchetes e chaves corretivos no final da expressão
    while (parenteses > 0) {
        expr[len++] = ')';
        parenteses--;
    }
    while (colchetes > 0) {
        expr[len++] = ']';
        colchetes--;
    }
    while (chaves > 0) {
        expr[len++] = '}';
        chaves--;
    }
    
    expr[len] = '\0'; 
}

int main() {
    int parenteses, colchetes, chaves;
    char expr[100];

    readExpr(expr, sizeof(expr));
    printf("Você digitou: %s\n", expr);
    parenteses = contaParenteses(expr);
    colchetes = contaColchetes(expr);
    chaves = contaChaves(expr);
    printf("Número de parênteses, colchetes e chaves: %d, %d, %d\n", parenteses, colchetes, chaves);

    corrigeExpr(expr, parenteses, colchetes, chaves);
    printf("Nova expressão: %s\n", expr);

    return 0;
}
