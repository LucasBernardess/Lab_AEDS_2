#include "conta.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

int main(){
    ContaBancaria* c = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    srand(time(NULL));
    char titular[30];
    printf("Digite o nome do titular da conta:  ");
    fgets(titular, 30, stdin);
    int numero = rand() % 1000;
    criarConta(c, numero,titular);
    double valor;
    printf("Digite quanto você quer depositar: ");
    scanf("%lf", &valor);
    depositar(c, valor);
    valor = 0;
    printf("Digite quanto vc quer sacar: ");
    scanf("%lf", &valor);
    sacar(c,valor);
    printf("Aqui está o seu saldo\n");
    double SaldoAtual = consultarSaldo(c);
    printf("Saldo atual -> %.2lf\n", SaldoAtual);
    printf("Informações da conta: \n");
    imprimirInfo(c);
    return 0;
}