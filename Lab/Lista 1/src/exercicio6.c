#include <stdio.h>
#include <string.h>

int decrescente(char *vec, int tam){
    if(tam > -1){
        printf(" %c", vec[tam]);
        decrescente(vec,tam-1);
    }
}

int main(){
    char vec[10] = {'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a'};
    decrescente(vec, 10);
    printf("\n");
}