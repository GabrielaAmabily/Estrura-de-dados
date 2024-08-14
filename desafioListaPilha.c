#include <stdlib.h>
#include <stdio.h>

struct pilha {
    int tam;
    int dado;
    struct pilha *prox;
    
};

typedef struct pilha Pilha;

void inicializarPilha (Pilha *pilha){
    pilha->tam = 0;
    pilha->prox = NULL; 
}

int adicionaPilha(Pilha *pilha, int dado){
    Pilha *novo;
    novo = malloc (sizeof(Pilha));

    if(novo == NULL){
        return 0;
    }

    novo->dado = dado;
    novo->prox = pilha->prox;
    pilha->prox = novo;

    pilha->tam++;
    return 1;
}

int main(){
    Pilha p1;
    Pilha p2;

    inicializarPilha(&p1);
    inicializarPilha(&p2);

    adicionaPilha(&p1, 2);
    adicionaPilha(&p1, 4);
    adicionaPilha(&p1, 98);
    adicionaPilha(&p2, 1);
    adicionaPilha(&p2, 5);
    adicionaPilha(&p2, 7);
    adicionaPilha(&p2, 98);


    return 0;
}
