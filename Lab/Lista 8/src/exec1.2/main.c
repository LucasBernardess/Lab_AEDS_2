#include <stdio.h>
#include "abp.h"

int main() {
    ABP* arvore = NULL;
    int opcao;
    Aluno aluno;

    do {
        printf("\nMenu:\n");
        printf("1 - Criar ABP\n");
        printf("2 - Inserir um Aluno\n");
        printf("3 - Buscar um Aluno pelo nome\n");
        printf("4 - Remover um Aluno pelo nome\n");
        printf("5 - Imprimir a ABP em ordem\n");
        printf("6 - Imprimir as informações do aluno com a maior nota\n");
        printf("7 - Imprimir as informações do aluno com a menor nota\n");
        printf("8 - Destruir a ABP\n");
        printf("9 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (arvore != NULL) {
                    printf("A árvore já foi criada!\n");
                } else {
                    arvore = criaABP();
                    printf("Árvore criada com sucesso!\n");
                }
                break;

            case 2:
                if (arvore == NULL) {
                    printf("Crie a árvore antes de inserir um Aluno.\n");
                } else {
                    printf("Digite o nome do Aluno: ");
                    scanf(" %[^\n]", aluno.nome);
                    printf("Digite a matrícula do Aluno: ");
                    scanf("%d", &aluno.matricula);
                    printf("Digite a nota do Aluno: ");
                    scanf("%lf", &aluno.nota);

                    if (insereElem(arvore, aluno)) {
                        printf("Aluno inserido com sucesso!\n");
                    }
                }
                break;

            case 3:
                if (arvore == NULL) {
                    printf("A árvore não foi criada ainda.\n");
                } else {
                    printf("Digite o nome do Aluno que deseja buscar: ");
                    char nomeBusca[100];
                    scanf(" %[^\n]", nomeBusca);
                    if (pesquisa(arvore, nomeBusca, &aluno)) {
                        printf("Aluno encontrado:\n");
                        printf("Nome: %s, Matrícula: %d, Nota: %.2lf\n", aluno.nome, aluno.matricula, aluno.nota);
                    } else {
                        printf("Aluno não encontrado.\n");
                    }
                }
                break;

            case 4:
                if (arvore == NULL) {
                    printf("A árvore não foi criada ainda.\n");
                } else {
                    printf("Digite o nome do Aluno que deseja remover: ");
                    char nomeRemove[100];
                    scanf(" %[^\n]", nomeRemove);
                    if (removeElementoPorNome(arvore, nomeRemove)) {
                        printf("Aluno removido com sucesso!\n");
                    } else {
                        printf("Aluno não encontrado.\n");
                    }
                }
                break;

            case 5:
                if (arvore == NULL) {
                    printf("A árvore não foi criada ainda.\n");
                } else {
                    printf("Árvore em ordem:\n");
                    imprime(arvore);
                }
                break;

            case 6:
                if (arvore == NULL) {
                    printf("A árvore não foi criada ainda.\n");
                } else {
                    NO* alunoMaiorNota = encontraMaiorNota(*arvore);
                    printf("Aluno com a maior nota:\n");
                    printf("Nome: %s, Matrícula: %d, Nota: %.2lf\n", alunoMaiorNota->info.nome, alunoMaiorNota->info.matricula, alunoMaiorNota->info.nota);
                }
                break;

            case 7:
                if (arvore == NULL) {
                    printf("A árvore não foi criada ainda.\n");
                } else {
                    NO* alunoMenorNota = encontraMenorNota(*arvore);
                    printf("Aluno com a menor nota:\n");
                    printf("Nome: %s, Matrícula: %d, Nota: %.2lf\n", alunoMenorNota->info.nome, alunoMenorNota->info.matricula, alunoMenorNota->info.nota);
                }
                break;

            case 8:
                if (arvore != NULL) {
                    destroiABP(arvore);
                    arvore = NULL;
                    printf("Árvore destruída.\n");
                }
                break;

            case 9:
                if (arvore != NULL) {
                    destroiABP(arvore);
                }
                printf("Saindo do programa. Adeus!\n");
                break;

            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 9);

    return 0;
}
