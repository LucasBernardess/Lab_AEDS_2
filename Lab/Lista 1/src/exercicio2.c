/*Implemente um programa que preenche dois vetores diferentes com n ́umero aleat ́orios ( rand()
) e que contenha 3funçoes:
(a) Retorna o maior elemento do vetor; 
(b) Retorna o menor
elemento do vetor e 
(c) Retorna a m ́edia dos elementos do vetor. Teste a fun ̧c ̃ao com um
programa main.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define TAM 20

int maior( int *vet){
    int maior = vet[0];
    for(int i = 1; i < TAM; i++){
        if(vet[i] > maior){
            maior = vet[i];
        }
    }

    return maior;
}

int menor(int *vet){
    int menor = vet[0];
    for(int i = 1; i < TAM; i++){
        if(vet[i] < menor){
            menor = vet[i];
        }
    }
    return menor;
}

float media(int *vet){
    int soma;
    for(int i = 0; i < TAM; i++){
        soma += vet[i];
    }
    float media = soma/TAM;
    return media;
}

int main(){

    int vet1[TAM];
    int vet2[TAM];
    srand(time(NULL));
    for(int i = 0; i < TAM; i++){
        vet1[i] = rand() % 500;
        printf("%d - ", vet1[i]);
    }
    printf("\n");

    for(int i = 0; i < TAM; i++){
        vet2[i] = rand() % 500;
        printf("%d - ", vet2[i]);
    }
    printf("\n");

    int maior1 = maior(vet1);
    int maior2 = maior(vet2);
    int menor1 = menor(vet1);
    int menor2 = menor(vet2);
    float media1 = media(vet1);
    float media2 = media(vet2);

    printf("O maior elemento do vetor 1 é %d, o menor elemento do vetor é %d, e sua média é %.2f\n", maior1, menor1, media1);
    printf("O maior elemento do vetor 2 é %d, o menor elemento do vetor é %d, e sua média é %.2f\n", maior2, menor2, media2);

}
