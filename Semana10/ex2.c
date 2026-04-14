#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
char valor;
struct elem* prox;
}Elem;

typedef struct fila{
Elem* ini;
Elem* fim;
}Fila;

Fila* cria (void){
Fila* f = (Fila*) malloc(sizeof(Fila));
f->ini = f->fim = NULL;
return f;
}

void insere (Fila* f, char v){
Elem* novo = (Elem*) malloc(sizeof(Elem));
novo->valor = v;
novo->prox = NULL;
if(f->fim != NULL){ // Fila não vazia
f->fim->prox = novo;
}
f->fim = novo;
if(f->ini == NULL){ // Fila vazia
f->ini = novo;
}
}

int vazia(Fila* f) {
    return f->ini == NULL;
}

char retira (Fila* f){
Elem* t;
char v;
if(vazia(f)){
printf("Fila vazia.\n");
exit(1);
}
t = f->ini;
v = t->valor;
f->ini = t->prox;
if(f->ini == NULL){
f->fim = NULL;
}
free(t);
return v;
} 

void imprime(Fila* f) {
    while (!vazia(f)) {
        char valor = retira(f);
        printf("%c ", valor);
    }
    printf("\n");
}


int main(){
char frase[100];
Fila* f = cria();

printf("Digite uma frase:\n");
fgets(frase, sizeof(frase), stdin);


for(int i=0;frase[i] != '\n';i++){
	if (frase[i] >= 'A' && frase[i] <= 'Z') {
		insere(f,frase[i]);}	
}

imprime(f);
free(f);

return 0;
}

