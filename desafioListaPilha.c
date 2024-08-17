#include <stdlib.h>
#include <stdio.h>

//Desafio de Programação - Sábado Letivo (27/07)

struct pilha {
    int tam;
    struct pilha *prox;
    struct no *endereco;
};
typedef struct pilha Pilha;

typedef struct no {
    int dado;
    struct no *prox;
    } No;

typedef struct lista{
    No *inicio; 
    No *fim;
    int tam;
}Lista;

void inicializaLista(Lista *lista);
int inserirLista(Lista *lista, int dado);
void exibe(Lista *lista);
void inicializarPilha (Pilha *pilha);
int valoresPilha(Pilha *pilha, No *endereco);
void preenchePilha(Pilha *pilha, Lista *lista);
int compararPilhas(Pilha *pilha1, Pilha *pilha2);

int main(){

    Lista lista1, lista2, lista3;
    inicializaLista(&lista1);
    inicializaLista(&lista2);
    inicializaLista(&lista3);

    inserirLista(&lista1, 2);
    inserirLista(&lista1, 3);
    inserirLista(&lista1, 8);

    inserirLista(&lista2, 3);
    inserirLista(&lista2, 4);

    inserirLista(&lista3, 1);
    inserirLista(&lista3, 2);

    lista1.fim->prox = lista3.inicio;
    lista2.fim->prox = lista3.inicio;

    printf("listas: \n");
    exibe(&lista1);
    exibe(&lista2);

    Pilha p1;
    Pilha p2;
    inicializarPilha(&p1);
    inicializarPilha(&p2);

    preenchePilha(&p1, &lista1);
	preenchePilha(&p2, &lista2);

    int comum = compararPilhas(&p1, &p2);
	printf("comum: %d", comum);

	return 0;

}

void inicializaLista(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0; 
}

int inserirLista(Lista *lista, int dado){
    No *novo = malloc(sizeof(No));
    
    if (novo == NULL) {
        printf("nao foi possivel alocar um espaço para o novo dado");
        return 0;
    }
    
    novo->dado = dado;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
        lista->fim = novo;
    } else {
        lista->fim->prox = novo;
        lista->fim = novo;
    }

    lista->tam++;
    return 1;
}


void exibe(Lista *lista){
    No *aux = lista->inicio;
    while(aux != NULL){
        printf(" %d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

void inicializarPilha (Pilha *pilha){
    pilha->tam = 0;
    pilha->prox = NULL; 
}

int valoresPilha(Pilha *pilha, No *endereco){
	Pilha *novo = (Pilha *) malloc(sizeof(Pilha));
	if(novo == NULL)
	   return 0;

	novo->endereco = endereco;
	novo->prox = pilha->prox;
	pilha->prox = novo;

	pilha->tam++;

	return 1;
}

void preenchePilha(Pilha *pilha, Lista *lista){
	No *aux = lista->inicio;

	while(aux != NULL){
		valoresPilha(pilha, aux);
		aux = aux->prox;
	}
}

int compararPilhas(Pilha *pilha1, Pilha *pilha2) {
    Pilha *aux1 = pilha1->prox;
    Pilha *aux2 = pilha2->prox;
    Pilha *ultimo_comum = NULL;

    while (aux1 != NULL && aux2 != NULL) {
        if (aux1->endereco == aux2->endereco) {
            ultimo_comum = aux1; // armazena o último nó comum
        } else {
            break; // Se os endereços não forem iguais, saia do loop
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }

    if (ultimo_comum != NULL) {
        return ultimo_comum->endereco->dado;
    } else {
        return -1; // ou outra indicação de que não há interseção
    }
}



