#include <stdio.h>
#include <stdlib.h>

// Lista simplesmente encadeada e não ordenada
// funções padrao de inserção e remoção 
// função separa e contatena lista 

typedef struct no {
    int dado;
    struct no *prox;
} No;

typedef struct lista {
    No *inicio;
    No *fim;
    int tam;
} Lista;

void inicializar(Lista *lista);
int inserirInicio(Lista *lista, int dado);
int inserirFinal(Lista *lista, int dado);
int removerDado(Lista *lista, int dado);
void exibe(Lista *lista);
Lista *lsepara(Lista *lista, int dado);
Lista *concatenar( Lista *lista1, Lista *lista2);

int main() {
    Lista minhalista;
    Lista *lista2;

    inicializar(&minhalista);

    inserirInicio(&minhalista, 2);
    inserirInicio(&minhalista, 5);
    inserirFinal(&minhalista, 10);
    inserirFinal(&minhalista, 8);
    inserirFinal(&minhalista, 1);
    
    printf("Lista Original antes da separação:\n");
    exibe(&minhalista);
    
    if(minhalista.tam <= 1 ){ 
        printf ("nao foi possivel dividir a lista devido ao tamanho");
    } else{
        lista2 = lsepara(&minhalista, 2);
        printf("Lista Original após a separação:\n");
        exibe(&minhalista);
        printf("Tamanho: %d \n\n", minhalista.tam);
        printf("Nova Lista após a separação:\n");
        exibe(lista2);
        printf("Tamanho: %d \n\n", lista2->tam);
    }
    
    printf("Lista concatenada: \n");
    concatenar(&minhalista, lista2);
    exibe(&minhalista);

    return 0;
}

void inicializar(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void exibe(Lista *lista) {
    No *aux = lista->inicio;
    while (aux != NULL) {
        printf(" %d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n\n");
}

int inserirInicio(Lista *lista, int dado) {
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL) {
        printf("Não foi possível alocar um espaço para o novo dado");
        return 0;
    }

    novo->dado = dado;
    novo->prox = lista->inicio;
    lista->inicio = novo;

    if (lista->fim == NULL) {
        lista->fim = novo;
    }

    lista->tam++;
    return 1;
}

int inserirFinal(Lista *lista, int dado) {
    No *novo = (No *)malloc(sizeof(No));

    if (novo == NULL) {
        printf("Não foi possível alocar um espaço para o novo dado");
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

int removerDado(Lista *lista, int dado) {
    No *aux = lista->inicio;
    No *ant = NULL;
    int qtdRem = 0;

    while (aux != NULL) {
        if (aux->dado == dado) {
            if (aux == lista->inicio) {
                lista->inicio = aux->prox;
                free(aux);
                aux = lista->inicio;
            } else if (aux == lista->fim) {
                lista->fim = ant;
                ant->prox = NULL;
                free(aux);
                aux = NULL;
            } else {
                ant->prox = aux->prox;
                free(aux);
                aux = ant->prox;
            }
            qtdRem++;
            lista->tam--;
        } else {
            ant = aux;
            aux = aux->prox;
        }
    }

    return qtdRem;
}

Lista *lsepara(Lista *lista, int dado) {
    No *aux = lista->inicio;
    Lista *lista2 = malloc(sizeof(Lista));
    inicializar(lista2);
    int qtd1 = 0;

    while (aux != NULL && aux->dado != dado) {
        qtd1++;
        aux = aux->prox;
    }

        if (aux-> prox == NULL) {
            printf("nao foi possivel separar pois este ja eh o ultimo elemento da lista ou elemento nao foi encontrado.\n\n");
            return lista2;
        }
    
        else if(aux->dado == dado) {
            lista2->inicio = aux->prox;
            lista2->fim = lista->fim;
            aux->prox = NULL;
            lista->fim = aux;
            lista2->tam = lista->tam - (qtd1 + 1);
            lista->tam = qtd1 + 1;
    }
    return lista2;
}

Lista *concatenar( Lista *lista1, Lista *lista2){
    No *aux = lista1->inicio; 
    if(lista1->inicio == NULL){
        printf("    A lista esta vazia nao ha nada para concatenar \n\n");
        return 0;
    } else {
        lista1->fim->prox = lista2->inicio;
        if(lista2->inicio == NULL){
        printf("    A lista 2 esta vazia nao ha nada para concatenar com lista 1 \n\n");
        return 0;
            }else{
                while (aux->prox != NULL){
                    aux = aux->prox;
                }
                lista1->fim = aux;
                free(lista2);
                return lista1;
        }
    }
}
