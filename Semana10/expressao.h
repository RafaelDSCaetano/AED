#ifndef EXPRESSAO_H
#define EXPRESSAO_H

#include <stddef.h>  // Para size_t

// TAD para Expressão
typedef struct {
    char expr[100];
} Expressao;

// Função para ler a expressão do usuário
void readExpr(Expressao *e);

#endif // EXPRESSAO_H
