#ifndef ABP_H
#define ABP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[100];
    int matricula;
    double nota;
} Aluno;

typedef struct NO {
    Aluno info;
    struct NO* esq;
    struct NO* dir;
} NO;

typedef struct NO* ABP;

NO* alocarNO() {
    return (NO*)malloc(sizeof(NO));
}

void liberarNO(NO* q) {
    free(q);
}

ABP* criaABP() {
    ABP* raiz = (ABP*)malloc(sizeof(ABP));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void destroiRec(NO* no) {
    if (no == NULL) return;
    destroiRec(no->esq);
    destroiRec(no->dir);
    liberarNO(no);
    no = NULL;
}

void destroiABP(ABP* raiz) {
    if (raiz != NULL) {
        destroiRec(*raiz);
        free(raiz);
    }
}

int estaVazia(ABP* raiz) {
    if (raiz == NULL) return 0;
    return (*raiz == NULL);
}

int comparaAluno(Aluno aluno1, Aluno aluno2) {
    return strcmp(aluno1.nome, aluno2.nome);
}

int insereRec(NO** raiz, Aluno aluno) {
    if (*raiz == NULL) {
        NO* novo = alocarNO();
        if (novo == NULL) return 0;
        novo->info = aluno;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
    } else {
        int comparacao = comparaAluno(aluno, (*raiz)->info);
        if (comparacao == 0) {
            printf("Aluno já existe na árvore!\n");
            return 0;
        }
        if (comparacao < 0)
            return insereRec(&(*raiz)->esq, aluno);
        else
            return insereRec(&(*raiz)->dir, aluno);
    }
    return 1;
}

int insereElem(ABP* raiz, Aluno aluno) {
    if (raiz == NULL) return 0;
    return insereRec(raiz, aluno);
}

int pesquisaRec(NO** raiz, char* nome, Aluno* resultado) {
    if (*raiz == NULL) return 0;
    int comparacao = comparaAluno(*resultado, (*raiz)->info);
    if (comparacao == 0) {
        *resultado = (*raiz)->info;
        return 1;
    }
    if (comparacao < 0)
        return pesquisaRec(&(*raiz)->esq, nome, resultado);
    else
        return pesquisaRec(&(*raiz)->dir, nome, resultado);
}

int pesquisa(ABP* raiz, char* nome, Aluno* resultado) {
    if (raiz == NULL) return 0;
    if (estaVazia(raiz)) return 0;
    return pesquisaRec(raiz, nome, resultado);
}

NO* encontraMaiorNota(NO* raiz) {
    if (raiz->dir != NULL)
        return encontraMaiorNota(raiz->dir);
    return raiz;
}

NO* encontraMenorNota(NO* raiz) {
    if (raiz->esq != NULL)
        return encontraMenorNota(raiz->esq);
    return raiz;
}

int removeElementoPorNome(ABP* raiz, char nome[100]) {
    if (*raiz == NULL) {
        return 0;
    }

    if (strcmp(nome, (*raiz)->info.nome) < 0) {
        return removeElementoPorNome(&((*raiz)->esq), nome);
    } else if (strcmp(nome, (*raiz)->info.nome) > 0) {
        return removeElementoPorNome(&((*raiz)->dir), nome);
    } else {
        NO* temp = *raiz;
        if ((*raiz)->esq == NULL) {
            *raiz = (*raiz)->dir;
        } else if ((*raiz)->dir == NULL) {
            *raiz = (*raiz)->esq;
        }
        free(temp);
        return 1;
    }
}

void imprimeAluno(Aluno aluno) {
    printf("Nome: %s, Matrícula: %d, Nota: %.2lf\n", aluno.nome, aluno.matricula, aluno.nota);
}

void imprime(ABP* raiz) {
    if (raiz == NULL) return;
    if (estaVazia(raiz)) {
        printf("Árvore Vazia!\n");
        return;
    }

    NO* alunoMaiorNota = encontraMaiorNota(*raiz);
    NO* alunoMenorNota = encontraMenorNota(*raiz);

    printf("Aluno com a maior nota:\n");
    imprimeAluno(alunoMaiorNota->info);

    printf("Aluno com a menor nota:\n");
    imprimeAluno(alunoMenorNota->info);
}

#endif
