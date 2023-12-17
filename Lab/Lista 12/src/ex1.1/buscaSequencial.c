#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp; //Num. de comparacoes

int* copiaVetor(int* v, int n){
    int i;
    int *v2;
    v2 = (int*) malloc (n*sizeof(int));
    for(i=0; i<n; i++) v2[i] = v[i];
    return v2;
}
void imprimeVetor(int* v, int n){
    int i, prim = 1;
    printf("[");
    for(i=0; i<n; i++)
        if(prim){ printf("%d", v[i]); prim = 0; }
        else printf(", %d", v[i]);
    printf("]\n");
}

void preencheAleatorio(int* v, int n, int ini, int fim){
    int i;
    for(i=0; i<n; i++)
        v[i] = ini + rand() % (fim-ini + 1); 
}

void troca(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
} 

int buscaSequencial(int *v, int n, int elem){
    int i;
    for(i=0; i<n; i++){
        comp++;
        if(v[i] == elem) 
            return i; //Elemento encontrado
    }
    return -1; //Elemento encontrado
}


int main(){

    //Atribuicoes iniciais
    srand(time(NULL));
    comp = 0;
    clock_t t;

    /*
    //Template de Calculo do Tempo de Execucao
    t = clock();
    //Chamada do Algoritmo aqui...
    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);
    */

    int *v;
    int n, x;
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &n);
    v = (int*) malloc (n*sizeof(int));

    
    preencheAleatorio(v, n, 1, n);
    imprimeVetor(v, n);
    
    
    printf("Digite um elemento para busca:\n");
    scanf("%d", &x);

    int ind;

    t = clock();
    ind = buscaSequencial(v, n, x);
    t = clock() - t;
    printf("-----Informacoes:\n");
    printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
    printf("Comparacoes: %d\n", comp);

    //imprimeVetor(v, n);

    if(ind != -1)
        printf("O elemento %d foi encontrado na pos %d.\n", x, ind);
    else
        printf("O elemento %d NAO foi encontrado!\n", x);
    

    free(v);
    return 0;
}
