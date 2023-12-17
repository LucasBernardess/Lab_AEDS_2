#include <stdio.h>
#include <stdlib.h>
#include "avlF.h"

int main() {
    AVL *arvoreAVL = criaAVL();
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Criar AVL\n");
        printf("2 - Inserir um Funcionario pelo salario\n");
        printf("3 - Buscar um Funcionario pelo salario e imprimir suas informacoes\n");
        printf("4 - Remover um Funcionario pelo nome\n");
        printf("5 - Imprimir a AVL em ordem\n");
        printf("6 - Imprimir as informacoes do Funcionario com o maior salario\n");
        printf("7 - Imprimir as informacoes do Funcionario com o menor salario\n");
        printf("8 - Destruir a AVL\n");
        printf("9 - Sair\n");
        printf("Escolha a opcao: ");
        scanf("%d", &opcao);
        double salario;
        char nome[50];
        int anoContratacao;

        switch (opcao) {
            case 1:
                destroiAVL(arvoreAVL);
                arvoreAVL = criaAVL();
                break;
            case 2:
                printf("Digite o nome do Funcionario: ");
                scanf("%s", nome);
                printf("Digite o salario do Funcionario: ");
                scanf("%lf", &salario);
                printf("Digite o ano de contratacao do Funcionario: ");
                scanf("%d", &anoContratacao);
                insereFuncionario(arvoreAVL, nome, salario, anoContratacao);
                break;
            case 3:
                printf("Digite o salario do Funcionario a ser buscado: ");
                scanf("%lf", &salario);
                NO *funcionarioBuscado = pesquisaFuncionario(arvoreAVL, salario);
                if (funcionarioBuscado != NULL) {
                    imprimeFuncionario(funcionarioBuscado->info);
                } else {
                    printf("Funcionario nao encontrado!\n");
                }
                 break;
            case 4:
                printf("Digite o nome do Funcionario a ser removido: ");
                scanf("%s", nome);
                removeFuncionarioPorNome(arvoreAVL, nome);
                break;
            case 5:
                imprimeTodosFuncionarios(arvoreAVL);
                break;
            case 6:
                imprimeMaiorSalario(arvoreAVL);
                break;
            case 7:
                imprimeMenorSalario(arvoreAVL);
                break;
            case 8:
                destroiAVL(arvoreAVL);
                break;
            case 9:
                destroiAVL(arvoreAVL);
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 9);

    return 0;
}
