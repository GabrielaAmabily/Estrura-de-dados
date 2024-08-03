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

int exibe(fila *fila){
    no *aux = fila->inicio;
    printf("os Elementos da fila sao: ");
    while( aux != NULL){ // pq nao é aux->prox != NULL ?
        printf(" %d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n\n");
}

retira(fila *fila, int n){
    if(fila->inicio == NULL){
        printf("Erro: fila vazia");
        printf("\n\n");
        return 0;
    }
    if(fila->tam < n){
        printf("Erro: posicao invalida");
        printf("\n\n");
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

    exibe(&fila);

    printf("removendo ate setimo elemento: \n");
    retira(&fila, 7);
    printf("removendo ate terceiro elemento: \n");
    retira(&fila, 3);

    exibe(&fila);


}



