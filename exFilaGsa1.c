#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *prox;
} no ;

typedef struct fila {
    struct no *inicio;
    struct no *fim; 
    int tam;    
}fila;

//void pq nao retorna nada
void inicializar(fila *fila){
    fila->inicio = NULL;  
    fila->fim = NULL;     

    fila->tam = 0;
}

int inserir(fila *fila, int dado){
    no *novo = malloc (sizeof(no));
    
    novo->dado =  dado;
    novo->prox = NULL;

    if( novo == NULL){
        return 0;
    }

    if(fila->inicio == NULL){
        fila->inicio = novo;
        fila->fim = novo;
    }
    else{
        fila->fim->prox = novo;
        fila->fim = novo;
    }
    fila->tam++;
    return 1; 
}

int somaExibe(fila *fila){
    int soma = 0;
    no *aux = fila->inicio;
    printf("os Elementos da fila sao: ");
    while( aux != NULL){ // pq nao é aux->prox != NULL ?
        printf(" %d ", aux->dado);
        soma += aux->dado;
        aux = aux->prox;
    }
    printf("\n");
    printf("a soma dos elementos da fila eh: %d ", soma);
    printf("\n");
    printf("\n");
}

int removeElementos(fila *fila, int n){
    if(fila->inicio == NULL){
        return 0;
    }
    for(int i = 0; i < n ; i++){
        no *temp = fila->inicio;
        fila->inicio = fila->inicio->prox;
        free(temp);
        fila->tam--;
    }
}

int main(){

    fila fila; //cade o asterisco?

    inicializar(&fila); //endereço de fila?

    inserir(&fila, 1);
    inserir(&fila, 2);
    inserir(&fila, 3);
    inserir(&fila, 4);
    inserir(&fila, 5);

    somaExibe(&fila); //endereço dnv??

    removeElementos(&fila, 2);
    somaExibe(&fila);

    inserir(&fila, 300);
    inserir(&fila, 400);
    inserir(&fila, 500);
    somaExibe(&fila);
}


