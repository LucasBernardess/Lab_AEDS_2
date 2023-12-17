#include <stdio.h>

int somaIntervalo(int maior, int menor) {
    if (maior == menor) {
        return menor; 
    } else {
        return maior + somaIntervalo(maior - 1, menor); 
    }
}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    int maior, menor;
    if(a>b){
        maior = a;
        menor = b;
    }else{
        menor = a;
        maior = b;
    }
    int soma = somaIntervalo(maior, menor);
    printf("Resultado da soma -> %d\n", soma);
}