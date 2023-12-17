#include <stdio.h>

int multiplicacaoRecursiva(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    } else if (b == 1) {
        return a;
    } else {
        return a + multiplicacaoRecursiva(a, b - 1);
    }
}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    int resultado = multiplicacaoRecursiva(a,b);
    printf("Resultado -> %d\n", resultado);
}