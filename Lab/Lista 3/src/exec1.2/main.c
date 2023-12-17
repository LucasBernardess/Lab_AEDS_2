#include <stdio.h>
#include "cubo.h"

int main() {
    Cubo cubo;
    double lado;
    printf("Digite o tamanho do lado do cubo: ");
    scanf("%lf", &lado);
    inicializarCubo(&cubo, lado); 

    double ladoCubo = obterLado(&cubo);
    double areaSuperficie = calcularAreaSuperficie(&cubo);
    double volumeCubo = calcularVolume(&cubo);

    printf("Lado do Cubo: %.2lf\n", ladoCubo);
    printf("Área da Superfície do Cubo: %.2lf\n", areaSuperficie);
    printf("Volume do Cubo: %.2lf\n", volumeCubo);

    return 0;
}