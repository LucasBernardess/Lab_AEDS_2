#ifndef CONTA_H
#define CONTA_H

typedef struct{
    char nome[30];
    int numero;
    double saldo;
}ContaBancaria;


void criarConta(ContaBancaria* c, int numero, char *titular);
void depositar(ContaBancaria *c, double valor);
void sacar(ContaBancaria *c, double valor);
double consultarSaldo(ContaBancaria *c);
void imprimirInfo(ContaBancaria *c);


#endif