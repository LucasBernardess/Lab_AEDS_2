#include <stdio.h>
#include "pilha.h"

int main(){
    int menu = 7;
    Pilha* p;
    int controle = 0;
    do{
        printf("Digite 1 para criar a pilha\nDigite 2 para empilhat um item\nDigite 3 para ver o topo da pilha\n");
        printf("Digite 4 para desempilhar um item\nDigite 5 para imprimir a pilha\nDigite 6 para destruir a pilha\nDigite 7 para sair\n");
        scanf("%d", &menu);
        if(menu == 1 && controle == 0){
            p = criaPilha();
	    controle = 1;
        }else if(menu == 2){
            int elem;
            printf("Digite o elemento que você quer empilhar:");
            scanf("%d", &elem);
            empilhar(p, elem);
        }else if(menu == 3){
            int r;
            verTopo(p, &r);
            printf("Topo -> %d\n\n", r);
        }else if(menu == 4){
            desempilhar(p);
        }else if(menu == 5){
            imprime(p);
        }else if(menu == 6){
            destroiPilha(p);
        }
    }while(menu != 7);
}
