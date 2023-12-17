#include "cubo.h"

void inicializarCubo(Cubo *cubo, double lado) {
    cubo->lado = lado;
}

double obterLado(Cubo *cubo) {
    return cubo->lado;
}

double calcularAreaSuperficie(Cubo *cubo) {
    return 6 * cubo->lado * cubo->lado;
}

double calcularVolume(Cubo *cubo) {
    return cubo->lado * cubo->lado * cubo->lado;
}