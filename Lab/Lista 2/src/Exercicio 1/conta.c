#include "conta.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void criarConta(ContaBancaria* c, int numero, char *titular){
    c->numero = numero;
    strcpy(c->nome,titular);
}
void depositar(ContaBancaria *c, double valor){
    c->saldo += valor;
}
void sacar(ContaBancaria *c, double valor){
    c->saldo -= valor;
}
double consultarSaldo(ContaBancaria *c){
    return c->saldo;
}
void imprimirInfo(ContaBancaria *c){
    printf("Nome -> %s", c->nome);
    printf("Número da conta -> %d\n", c->numero);
    printf("Saldo -> %.2lf\n", c->saldo);
}
