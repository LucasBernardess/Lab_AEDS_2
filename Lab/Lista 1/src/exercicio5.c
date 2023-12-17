#include <stdio.h>

int decrescente(int x){
    if(x > 0){
        printf(" %d", x);
        decrescente(x-1);
    }
}

int crescente(int x){
    if(x<6){
        printf(" %d", x);
        crescente(x+1);
    }
}

int main(){
    printf("decrescente ->");
    decrescente(5);
    printf("\ncrescente -> ");
    crescente(1);
     printf("\n");
    return 0;
}