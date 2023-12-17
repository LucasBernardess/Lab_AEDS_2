#include <stdio.h>
#include "ArvoreB.h"

int main(){
    ArvoreB *B = criaArvoreB();
    int valores[21] = {20, 10, 40, 50, 30, 55, 3, 11, 4, 28, 36, 33, 52, 17, 25, 13, 45, 9, 43, 8, 48};
    int remover[17] = {45, 30, 28, 50, 8, 10, 4, 20, 40, 55, 17, 33, 11, 36, 3, 9, 52};

    int i;
    Registro r;
    char c;

    printf("\n\n----Arvore B - INSERCAO:\n");
    for(i=0; i<21; i++){
        r.chave = valores[i];
        insereArvoreB(B, r);
        printf("Inserido %d..\n", valores[i]);
    }  

    printf("\n\n----Arvore B - PESQUISA:\n");
    for(i=0; i<21; i++){
        r.chave = valores[i];
        if (pesquisaArvoreB(B, &r) != -1)
            printf("Valor %d encontrado!\n", valores[i]);
        else
            printf("Valor %d nao encontrado.\n", valores[i]);
    }

    printf("\n\n----Arvore B - FINAL:\n");
    imprimeArvoreB(B);

    printf("\n\n----Arvore B - REMOCAO:\n");
    for(i=0; i<17; i++){
        r.chave = remover[i];
        removeArvoreB(B, r);
        printf("Removido %d..\n", remover[i]);
    }  
    
    printf("\n\n----Arvore B - FINAL APÓS REMOÇÃO:\n");
    imprimeArvoreB(B);

    destroiArvoreB(B);
    return 0;
}
