#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct{
    char nome[30]; 
    int chave;
    double preco;
    int quantidade;
}Produto;

typedef struct{
    Produto produtos[100];
}CatalogoProdutos;

void criarCatalogo(CatalogoProdutos *c);
void adicionarProduto(CatalogoProdutos *c, char *nome, double preco, int quantidade);
int verificarEstoque(CatalogoProdutos *c, char *nome);
void imprimirCatalogo(CatalogoProdutos *c);

#endif