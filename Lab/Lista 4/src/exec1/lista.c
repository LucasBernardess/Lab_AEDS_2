#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Lista* criaLista(){
    Lista *li;
    li = (Lista*) malloc (sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int listaVazia(Lista *li){
    if(li == NULL) return 1;
    if(*li == NULL) return 1;//True - Vazia!
    return 0;//False - tem elemento!
}

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

int procura(Lista* li, int x){
    if(li == NULL) return -1;
    if(listaVazia(li)){
        printf("Lista Vazia!\n");
        return -1;
    }
    NO* aux = *li;
    int i = 0;
    while(aux != NULL){
        if(aux->info == x){
            return i;
        }
        aux = aux->prox;
        i++;
    }
    return -1;
    printf("\n");
}

int insereIni(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = *li;
    *li = novo;
    return 1;
}

int insereFim(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    novo->prox = NULL;
    if(listaVazia(li)){
        *li = novo;
    }else{
        NO* aux = *li;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return 1;
}

int InsereOrdenado(Lista* li, int elem) {
    if (li == NULL) return 0;
    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) return 0; // Verifica se a alocação de memória foi bem-sucedida
    novo->info = elem;
    if (*li == NULL || elem <= (*li)->info) {
        // Insere no início da lista ou em uma lista vazia
        novo->prox = *li;
        *li = novo;
        return 1; // Inserção bem-sucedida
    }
    NO* aux = *li;
    while (aux->prox != NULL && aux->prox->info < elem) {
        aux = aux->prox;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
    return 1; // Inserção bem-sucedida
}

int removeIni(Lista* li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* aux = *li;
    *li = aux->prox;
    liberarNO(aux);
    return 1;
}

int removeFim(Lista* li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* ant, *aux = *li;
    while(aux->prox != NULL){
        ant = aux;
        aux = aux->prox;
    }
    if(aux == *li)
        *li = aux->prox;
    else   
        ant->prox = aux->prox;
    liberarNO(aux);
    return 1;
}

int removePrimeiraOcorrencia(Lista* li, int elem){
    if (li == NULL || *li == NULL) {
        return 0; // Lista vazia ou ponteiro nulo, a remoção não é possível
    }
    NO* ant = NULL;
    NO* atual = *li;
    while (atual != NULL) {
        if (atual->info == elem) {
            if (ant == NULL) {
                // Remoção do primeiro elemento da lista
                *li = atual->prox;
            } else {
                // Remoção de um elemento no meio ou final da lista
                ant->prox = atual->prox;
            }
            free(atual); // Libera a memória do nó removido
            return 1;     // Remoção bem-sucedida
        }
        ant = atual;
        atual = atual->prox;
    }
    return 0; // Elemento não encontrado, remoção não realizada
}

void imprimeLista(Lista* li){
    if(li == NULL) return;
    if(listaVazia(li)){
        printf("Lista Vazia!\n");
        return;
    }
    printf("Elementos:\n");
    NO* aux = *li;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

void destroiLista(Lista* li){
    if(li != NULL){
        NO* aux;
        while((*li) != NULL){
            aux = *li;
            *li = (*li)->prox;
            liberarNO(aux);
        }
        free(li);
    }
}