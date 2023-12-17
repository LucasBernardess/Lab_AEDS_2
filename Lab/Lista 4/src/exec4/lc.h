
#ifndef LC_H
#define LC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;    
}NO;

typedef struct NO* Lista;

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
    if(*li == NULL) return 1;
    return 0;
}

NO* alocarNO(){
    return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
    free(q);
}

int tamanho(Lista* li){
     if (li == NULL) return 0;
     int i = 0;
     NO* aux = *li;
     NO* contador = aux;
     while (aux->prox != NULL) {
        aux = aux->prox;
        i++;
        if(i > 0 && contador == aux){
            return i;
        }
    }
    return i;
}

int procura(Lista* li, int x){
    if(li == NULL) return -1;
    if(listaVazia(li)){
        printf("Lista Vazia!\n");
        return -1;
    }
    NO* aux = *li;
    NO* contador = aux;
    int i = 0;
    while(i < 1 || contador != aux){
        if(aux->info == x){
            return 1;
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
    if(listaVazia(li)){
        novo->prox = novo;
        *li = novo;
    }else{
        NO* aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = *li;
        *li = novo;        
    }
    return 1;
}

int insereFim(Lista* li, int elem){
    if(li == NULL) return 0;
    NO* novo = alocarNO();
    if(novo == NULL) return 0;
    novo->info = elem;
    if(listaVazia(li)){
        novo->prox = novo;
        *li = novo;
    }else{
        NO* aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = *li;       
    }
    return 1;
}

int removeIni(Lista *li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* prim = *li;
    if(prim == prim->prox){
        //apenas 1 elemento
        *li = NULL;
    }else{
        NO* aux = *li;
        while(aux->prox != (*li))
            aux = aux->prox;
        aux->prox = (*li)->prox;
        *li = (*li)->prox;
    }
    liberarNO(prim);
    return 1;
}

int removeFim(Lista *li){
    if(li == NULL) return 0;
    if(listaVazia(li)) return 0;
    NO* aux = *li;
    if(aux == aux->prox){
        //apenas 1 elemento
        *li = NULL;
    }else{
        NO* ant;
        while(aux->prox != (*li)){
            ant = aux;//anterior
            aux = aux->prox;
        }  
        ant->prox = *li;
    }
    liberarNO(aux);
    return 1;
}

void imprimeLista(Lista* li){
    if(li == NULL) return;
    if(listaVazia(li)){
        printf("Lista Vazia!\n");
        return;
    }
    printf("Elementos:\n");
    NO* aux = *li;
    while(aux->prox != *li){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
    printf("%d ", aux->info);
    printf("\n");
}

void destroiLista(Lista *li){
    if(li != NULL && (*li) != NULL){
        NO* prim, *aux;
        prim = *li;
        *li = (*li)->prox;
        while((*li) != prim){
            aux = *li;
            *li = (*li)->prox;
            liberarNO(aux);
        }
        liberarNO(prim);
        free(li);
    }
}

#endif