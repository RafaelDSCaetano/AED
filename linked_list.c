typedef struct Nodo{
int info;
struct Nodo* prox;
}Nodo;

Nodo *criar(){//para testar
Nodo *inicio = (Nodo*) malloc(sizeof(Nodo));
inicio -> prox = NULL;
return inicio;
}

void inserir(Nodo *inicio, int valor) {//para testar
Nodo *novo = (Nodo*)malloc(sizeof(Nodo));
novo->info = valor;
novo->prox = inicio->prox;
inicio->prox = novo;
}

void imprimir(Nodo *inicio){//para testar
Nodo *atual = inicio->prox;
while(atual!=NULL){
printf("%d", atual->info);
atual=atual->prox;
}
printf("\n");
}

void reseta(Nodo *inicio){
Nodo *atual = inicio->prox;
Nodo *prox;

while(atual != NULL){
prox = atual->prox;
free(atual);
atual = prox;

}
inicio->prox = NULL;
}

void vazio(Nodo *inicio){
if (inicio->prox == NULL) {
printf("Lista encadeada é vazia.\n");
return;
}
else
printf("Lista encadeada não é vazia.\n");
return;
}

Nodo* proximo(Nodo *inicio, int valor){
Nodo *atual = inicio->prox;

while (atual != NULL){
if (atual->info == valor){
return atual->prox;}

atual = atual->prox;
}
return NULL; //elemento não encontrado

}

void buscaValor(Nodo *inicio, int valor){

Nodo *atual = inicio;
while (atual != NULL){
if (atual->info == valor){
printf("Valor encontrado!");
return;}

else{
atual = atual->prox;
}}
printf("Valor não encontrado!\n");
}