#ifndef CORRETOR_H
#define CORRETOR_H

#include "contador.h"  // Para a estrutura Contador

// TAD para Corretor
typedef struct {
    char expr[200]; // Aumentado para garantir espaço para correções
} Corretor;

// Função para corrigir a expressão desbalanceada
void corrigeExpr(const char *expr, Contador c, Corretor *cor);

#endif // CORRETOR_H
