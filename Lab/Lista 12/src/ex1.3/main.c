#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 5
#define MAX_NOME 50

struct Aluno {
    char nome[MAX_NOME];
    int matricula;
    float notas[3];
};

int comparaPorNome(const void* a, const void* b) {
    return strcmp(((struct Aluno*)a)->nome, ((struct Aluno*)b)->nome);
}

int comparaPorMatricula(const void* a, const void* b) {
    return ((struct Aluno*)a)->matricula - ((struct Aluno*)b)->matricula;
}

void buscaBinariaPorNome(struct Aluno alunos[], int tamanho, char nomeAluno[]) {
    int inicio = 0;
    int fim = tamanho - 1;
    
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        if (strcmp(alunos[meio].nome, nomeAluno) == 0) {
            printf("Aluno encontrado pelo nome: %s\n", alunos[meio].nome);
            return;
        } else if (strcmp(alunos[meio].nome, nomeAluno) < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    printf("Aluno não encontrado pelo nome.\n");
}

void buscaBinariaPorMatricula(struct Aluno alunos[], int tamanho, int matriculaAluno) {
    int inicio = 0;
    int fim = tamanho - 1;
    
    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        if (alunos[meio].matricula == matriculaAluno) {
            printf("Aluno encontrado pela matrícula: %s\n", alunos[meio].nome);
            return;
        } else if (alunos[meio].matricula < matriculaAluno) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    
    printf("Aluno não encontrado pela matrícula.\n");
}

int main() {
    struct Aluno alunos[MAX_ALUNOS] = {
        {"Alice", 1001, {7.5, 8.0, 9.2}},
        {"Bob", 1002, {6.8, 7.5, 8.0}},
        {"Carol", 1003, {9.0, 8.5, 9.8}},
        {"David", 1004, {8.2, 7.0, 7.5}},
        {"Eva", 1005, {6.5, 8.8, 7.2}}
    };

    qsort(alunos, MAX_ALUNOS, sizeof(struct Aluno), comparaPorNome);

    char nomeBusca[MAX_NOME] = "Lucas";
    buscaBinariaPorNome(alunos, MAX_ALUNOS, nomeBusca);

    qsort(alunos, MAX_ALUNOS, sizeof(struct Aluno), comparaPorMatricula);

    int matriculaBusca = 1004;
    buscaBinariaPorMatricula(alunos, MAX_ALUNOS, matriculaBusca);

    return 0;
}
