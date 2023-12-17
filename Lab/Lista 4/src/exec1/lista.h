#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int info;
    struct NO* prox;    
}NO;

typedef struct NO* Lista;

Lista* criaLista();
int listaVazia(Lista *li);
NO* alocarNO();
void liberarNO(NO* q);
int procura(Lista* li, int x);
int insereIni(Lista* li, int elem);
int insereFim(Lista* li, int elem);
int InsereOrdenado(Lista*li, int elem);
int removeIni(Lista* li);
int removeFim(Lista* li);
int removePrimeiraOcorrencia(Lista* li, int elem);
void imprimeLista(Lista* li);
void destroiLista(Lista* li);

#endif