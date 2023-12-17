#include <stdio.h>
#include <stdlib.h>
#define TAM 3

typedef struct Alunos{
    char nome[30];
    int matricula;
    float nota;
}Aluno;

Aluno maior(struct Alunos *aluno){
    char nome[30];
    strncpy(nome,aluno[0].nome, 30);
    float maiorNota = aluno[0].nota;
    int matricula = aluno[0].matricula;

    for(int i = 1; i <TAM; i++){
        if(maiorNota < aluno[i].nota){
            strncpy(nome,aluno[i].nome, 30);
            maiorNota = aluno[i].nota;
            matricula = aluno[i].matricula;
        }
    }

    printf("\nAluno com maior nota -> %s\n", nome);
    printf("Matrícula -> %d\n", matricula);
    printf("Nota -> %.2f\n\n\n", maiorNota);
}

Aluno menor(struct Alunos *aluno){
    char nome[30];
    strncpy(nome,aluno[0].nome, 30);
    float menorNota = aluno[0].nota;
    int matricula = aluno[0].matricula;

    for(int i = 1; i <TAM; i++){
        if(menorNota > aluno[i].nota){
            strncpy(nome,aluno[i].nome, 30);
            menorNota = aluno[i].nota;
            matricula = aluno[i].matricula;
        }
    }

    printf("Aluno com menor nota -> %s\n", nome);
    printf("Matrícula -> %d\n", matricula);
    printf("Nota -> %.2f\n\n\n", menorNota);
}


int main(){
    struct Alunos *aluno = (Aluno*)malloc(TAM*sizeof(Aluno));
    srand(time(NULL));
    for(int i = 0; i<TAM; i++){
        printf("Digite o nome do aluno: ");
        scanf("%s", &aluno[i].nome);
        printf("Digite a nota do aluno: ");
        scanf("%f", &aluno[i].nota);
        printf("Digite a matricula do aluno: ");
        scanf("%d", &aluno[i].matricula);
    }
    for(int i = 0; i < TAM; i++){
        printf("nome - > %s |", aluno[i].nome);
        printf("matrícula -> %d |", aluno[i].matricula);
        printf("nota -> %.2f\n", aluno[i].nota);
    }

    maior(aluno);
    menor(aluno);
}