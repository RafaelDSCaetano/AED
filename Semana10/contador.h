#ifndef CONTADOR_H
#define CONTADOR_H

#include <stddef.h>  // Para size_t

// TAD para Contador
typedef struct {
    int parenteses;
    int colchetes;
    int chaves;
} Contador;

// Funções para contar parênteses, colchetes e chaves na expressão
void contaParenteses(const char *expr, Contador *c);
void contaColchetes(const char *expr, Contador *c);
void contaChaves(const char *expr, Contador *c);

#endif // CONTADOR_H
