/*Implemente uma fun ̧c ̃ao que receba como parˆametro um array de n ́umeros reais (VET) de
tamanho N e retorne quantos n ́umeros negativos existem nesse array. Essa função deve
obedecer ao cabe ̧calho: int negativos(float *vet, int N); Teste a fun ̧c ̃ao com um programa
main.*/

#include <stdio.h>

int negativos(float *vet, int N){
    int cont;
    for(int i = 0; i<N; i++){
        if(vet[i] < 0){
            cont++;
        }
    }
    return cont;
}


int main(){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    float vet[n];
    printf("Digite os valores do vetor: ");
    for(int i = 0; i<n; i++){
        scanf("%f", &vet[i]);
    }
    int contador = negativos(vet, n);
    printf("total de números negativos -> %d\n", contador);

    return 0;
}