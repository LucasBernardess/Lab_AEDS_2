#include <stdio.h>
#include "Patricia.h"

void binary(int n){
	if(n < 2) 
        printf("%d ", n % 2);
	else{
        binary(n / 2);
	    printf("%d ", n % 2);
	}
}

int main(){

    int valoresLivro[7] = {18, 19, 24, 33, 40, 54, 34};

    ArvorePat P = NULL;
    int x, i;

    printf("----------Insercao:\n");
    
    for(i = 0; i < 7; i++){
        printf("%d em binario: ", valoresLivro[i]); 
        binary(valoresLivro[i]); 
        printf("\n");
        P = Insere(valoresLivro[i], &P);
    }

    printf("\n\n----------Busca:\n");
    x = 33; 
    printf("%d em binario: ", x); 
    binary(x); 
    printf("\n");
    if(Pesquisa(x, P))
        printf("Valor encontrado!\n");
    else
        printf("Valor nao encontrado.\n");
    
    x = 50; 
    printf("%d em binario: ", x); 
    binary(x); 
    printf("\n");
    if(Pesquisa(x, P))
        printf("Valor encontrado!\n");
    else
        printf("Valor nao encontrado.\n");

    printf("\n\n----------Impressao FINAL:\n");
    imprimePatricia(P);
    
    return 0;
}
