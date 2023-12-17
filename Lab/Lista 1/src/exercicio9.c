#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int preenche_vetor(int *vetor, int n){
    if(n<=0){
        return 0;
    }
    vetor[n] = rand() % 500;
    return preenche_vetor(vetor, n-1);
}

int crescente(int *vetor_crescente, int n, int indice){
    if(indice < n){
        printf("%d ", vetor_crescente[indice]);
        crescente(vetor_crescente, n, indice+1);
    }
}

int decrescnte(int *vetor_decrescente, int n, int indice){
    if(indice >= 0){
        printf("%d ", vetor_decrescente[indice]);
        decrescnte(vetor_decrescente, n, indice-1);
    }
}

int encontrarMaior(int *vetor, int n) {
    if (n == 1) {
        return vetor[0];
    }
    int maiorNoRestante = encontrarMaior(vetor, n - 1);
    return (maiorNoRestante > vetor[n - 1]) ? maiorNoRestante : vetor[n - 1];
}


int main(){
    int n;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);
    int vetor[n];
    srand(time(NULL));
    preenche_vetor(vetor, n);
    crescente(vetor, n, 0);
    printf("\n");
    decrescnte(vetor, n, n-1);
    printf("\n");
    int maior = encontrarMaior(vetor, n);
    printf("maior elemento -> %d\n", maior);
}



