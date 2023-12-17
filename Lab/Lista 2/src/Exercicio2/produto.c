#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void criarCatalogo(CatalogoProdutos *c){
    c->produtos->chave = 0;
}

void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade){
    if(c->produtos->chave >= 100){
        printf("Catalogo Cheio \n");
        return;
    }
    printf("aqui\n");
    strcpy(c->produtos[c->produtos->chave].nome, nome); 
    c->produtos[c->produtos->chave].preco = preco;
    c->produtos[c->produtos->chave].quantidade = quantidade;
    printf("Nome do produto -> %s\n\n\n", c->produtos[c->produtos->chave].nome);
    c->produtos->chave++;
}

int verificarEstoque(CatalogoProdutos *c, char *nome){
    int iguais = 0;
    for(int i = 0; i< 3; i++){
        printf("nome -> %s", c->produtos[i].nome);
        printf("Quantidade -> %d\n", c->produtos[i].quantidade);
        printf("Preço -> %.2lf\n\n", c->produtos[i].preco); 
    }
    for(int i = 0; i < 100; i++){
        iguais = strcmp(c->produtos[i].nome, nome);
        if(iguais == 0){
            printf("Produto está presente no estoque\n");
            printf("Quantidade -> %d\n", c->produtos[i].quantidade);
            printf("Preço -> %.2lf\n\n", c->produtos[i].preco);
            return 0;
        }
    }
    printf("Produto não existe no estoque\n");
    return 0;
}

void imprimirCatalogo(CatalogoProdutos *c){
    for(int i = 0; i< c->produtos->chave; i++){
        printf("Nome -> %s | Quantidade -> %d | Preço -> %.2lf\n", c->produtos[i].nome, c->produtos[i].quantidade, c->produtos[i].preco);
    }
    printf("\n");
}