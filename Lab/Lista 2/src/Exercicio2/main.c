#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    CatalogoProdutos* c = c = (CatalogoProdutos*)malloc(sizeof(CatalogoProdutos));
    criarCatalogo(c);
    int contador = 0;
    int indice = 0;
    char nome_prod[30];
    double preco_prod;
    int quantidade_prod;
    char pesq_prod[30];
    while(contador != 4){
        printf("Digite qual opção você quer\nDigite 1 para adicionar um produto\nDigite 2 para verificar o estoque\nDigite 3 para imprimir o catalogo\n Digite 4 para sair\n");
        scanf("%d", &contador);
        if(contador == 1){
            printf("Digite o nome do produto: ");
            scanf("%s", &nome_prod);
            printf("Digite o preço do produto a ser inserido: ");
            scanf("%lf", &preco_prod);
            printf("Digite a quantidade do produto a ser inserido:");
            scanf("%d", &quantidade_prod);
            adicionarProduto(c, nome_prod, preco_prod, quantidade_prod);
        }else if(contador == 2){
            printf("Digite o produto que você quer pesquisar: ");
            scanf("%s", &nome_prod);
            verificarEstoque(c, nome_prod);
        }else if(contador == 3){
            imprimirCatalogo(c);
        }
    }
}