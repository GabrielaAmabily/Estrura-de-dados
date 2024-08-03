#include <stdio.h>
#include <stdlib.h>

//lista simplesmente encadeada e nao ordenada

    typedef struct no {
        int dado;
        struct no *prox;
    }No;
    
    typedef struct lista {
        No *inicio;
        No *fim;
        int tam ;
    } Lista;

void inicializar(Lista *lista);
int inserirInicio(Lista *lista, int dado);
int inserirFinal(Lista *lista, int dado);
int removerDado(Lista *lista, int dado);
void exibe(Lista *lista);

int main(){
    Lista minhalista;

    inicializar(&minhalista);

    inserirInicio(&minhalista, 1);
    inserirInicio(&minhalista, 4);
    inserirFinal(&minhalista, 4);

    exibe(&minhalista);

    inserirFinal(&minhalista, 9);

    exibe(&minhalista);

    inserirFinal(&minhalista, 7);
    removerDado (&minhalista, 1);

    exibe(&minhalista);


     

    return 0;
}

void inicializar(Lista *lista){
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tam = 0;
}

void exibe(Lista *lista){
    No *aux = lista->inicio;
    while(aux != NULL){
        printf(" %d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n\n");
}

int inserirInicio(Lista *lista, int dado){
    No *novo = malloc (sizeof (No));
     
    //testo se criou 
    if(novo == NULL){
        printf("nao foi possivel alocar um espaço para o novo dado");
        return 0;
    }

    novo->dado = dado;

    //testo se lista esta vazia 
    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
        lista->fim->prox = NULL;
    }

    //se nao esta vazia 
    else{
        novo->prox = lista->inicio;
        lista->inicio = novo;
    }

    lista->tam++;
    return 1;
}

int inserirFinal(Lista *lista, int dado){
    //criar novo para inserir 
    No *novo= malloc(sizeof(No));

    //testo se criou
    if(novo == NULL){
        printf("nao foi possivel alocar um espaço para o novo dado");
        return 0;
    }

    novo->dado = dado;

    //testo se lista esta vazia 
    if(lista->inicio == NULL){
        lista->inicio = novo;
        lista->fim = novo;
        lista->inicio->prox = NULL;
    }

    //se nao esta vazia 
    else{
        lista->fim->prox = novo;
        novo->prox = NULL;
        lista->fim = novo;
    }

    lista->tam++;
    return 1;
}

int removerDado(Lista *lista, int dado){
    //nao preciso malocar eles?
    No *aux;
    No *ant;
    int qtdRem = 0;
    aux = lista->inicio;
    ant = NULL;

    //tem elemento na lista ainda?
    while(aux !=NULL){
        //ja achei o dado?
        if(aux->dado == dado){
            //esse dado é o primeiro da lista?
            if(aux == lista->inicio){
                lista->inicio = aux->prox;
                free(aux);
                aux = lista->inicio;
            }
            //esse dado é o ultimo da lista? 
            else if(aux == lista->fim){
                lista->fim = ant;
                ant->prox = NULL;
                free(aux);
            }
            //dado esta no meio da lista
            else {
                ant->prox = aux->prox;
                free(aux);
                aux = ant->prox; // e se eu esquecer essa linha?
            }
            qtdRem++;
            lista->tam--;
        // se nao achei o dado vou pra frente 
        }  else {
            ant = aux;
            aux = aux->prox;
        }
    }
    return qtdRem;

}
