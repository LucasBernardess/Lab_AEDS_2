#include <stdio.h>
#include "FPHeap.h"

int main(){
    FilaP* F;
    int menu = -1;
    int quantidade = 0;
    do{
        printf("1 - Criar Fila;\n");
        printf("2 - Inserir um item pela prioridade;\n");
        printf("3 - Ver o início da Fila;\n");
        printf("4 - Remover um item;\n");
        printf("5 - Imprimir a Fila;\n");
        printf("6 - Mostrar o tamanho da Fila;\n");
        printf("7 - Destruir a Fila;\n");
        printf("8 - Sair;\n");
        scanf("%d", &menu);
        if(menu == 1){
            F = criaFila();
        }else if(menu == 2){
            printf("Digite o elemento que você  quer inserir:");
            int elem;
            scanf("%d", &elem);
            printf("Digite a prioridade desse elemento:");
            int prioridade;
            scanf("%d", &prioridade);
            inserirPrio(F, elem, prioridade);
            quantidade ++;
        }else if(menu == 3){
            int p;
            int prio;
            verIni(F, &p, &prio);
            printf("Inicio -> %d || Prioridade -> %d\n", p, prio);
        }else if(menu == 4){
            removeIni(F);
        }else if(menu == 5){
            imprime(F);
        }else if(menu == 6){
            printf("Tamanho -> %d\n", quantidade);
        }else if(menu == 7){
            destroiFila(F);
        }
    }while(menu != 8);

    return 0;
}