#include <stdio.h>
#include "DDE.h"
int main(){
    Deque *D;
    int menu;
    int controle = 0;
    int p;
    do{
        printf("1 - Criar Deque;\n");
        printf("2 - Inserir um item no fim;\n");
        printf("3 - Inserir um item no início;\n");
        printf("4 - Ver o início do Deque;\n");
        printf("5 - Ver o fim do Deque;\n");
        printf("6 - Remover um item do fim;\n");
        printf("7 - Remover um item do início;\n");
        printf("8 - Imprimir o Deque;\n");
        printf("9 - Destruir o Deque;\n");
        printf("10 - Sair;\n");
        scanf("%d", &menu);
        if(menu == 1 && controle ==0){
            D = criaDeque();
            controle = 1;
        }else if(menu == 2){
            int elem;
            printf("Digite o elemento que você quer inserir:");
            scanf("%d", &elem);
            insereFim(D, elem);
        }else if(menu == 3){
            int elem;
            printf("Digite o elemento que você quer inserir:");
            scanf("%d", &elem);
            insereIni(D, elem);
        }else if(menu == 4){
            verInicio(D, &p);
            printf("Inicio do deque -> %d", p);
        }else if(menu == 5){
            int fimDeque = verFim(D, &p);
            printf("Fim do deque -> %d", p);
        }else if(menu == 6){
            removeFim(D);
        }else if(menu == 7){
            removeIni(D);
        }else if(menu == 8){
            imprime(D);
        }else if(menu == 9){
            destroiDeque(D);
        }
    }while(menu != 10);
}