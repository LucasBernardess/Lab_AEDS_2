#include <stdio.h>
#include "fila.h"

int main(){
    int menu;
    int controle = 0;
    Fila *F;
    do{
        printf("Digite 1 para criar a fila\nDigite 2 para enfileirar um item\nDigite 3 para ver o início da fila\n");
        printf("Digite 4 para desenfileirar um item\nDigite 5 para imprimir a fila\nDigite 6 para destruir a fila\nDigite 7 para sair\n");
        scanf("%d", &menu);
        if(menu == 1 && controle ==0){
            F = criaFila();
            controle = 1;
        }else if(menu == 2){
            int elem;
            printf("Digite o elemento que você quer enfileirar:");
            scanf("%d", &elem);
            enfileirar(F,elem);
        }else if(menu == 3){
            int p;
            verInicio(F, &p);
            printf("Início da fila -> %d\n", p);
        }else if(menu == 4){
            desenfileirar(F);
        }else if(menu == 5){
            imprime(F);
        }else if(menu == 6){
            destroiFila(F);
            controle = 0;
        }
    }while(menu != 7);
}
