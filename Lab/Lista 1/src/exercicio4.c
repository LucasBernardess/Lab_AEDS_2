/*Implemente uma fun ̧c ̃ao que calcule as ra ́ızes de uma equa ̧c ̃ao do segundo grau do tipo Ax2
+ Bx + C = 0.
Essa fun ̧c ̃ao deve obedecer ao seguinte prot ́otipo: int raizes(float A, float B, float C, float
* X1, float * X2);
Essa funçao deve ter como retorno o n ́umero de ra ́ızes reais e distintas da equa ̧c ̃ao. Se
existirem ra ́ızes reais, seus valores devem ser armazenados nas vari ́aveis apontadas por X1 e
X2. Teste a fun ̧c ̃ao com um programa main. Lembrando que:

x = −b ± √∆/2*a */
/*Implemente uma fun ̧c ̃ao que calcule as ra ́ızes de uma equa ̧c ̃ao do segundo grau do tipo Ax2
+ Bx + C = 0.
Essa fun ̧c ̃ao deve obedecer ao seguinte prot ́otipo: int raizes(float A, float B, float C, float
* X1, float * X2);
Essa funçao deve ter como retorno o n ́umero de ra ́ızes reais e distintas da equa ̧c ̃ao. Se
existirem ra ́ızes reais, seus valores devem ser armazenados nas vari ́aveis apontadas por X1 e
X2. Teste a fun ̧c ̃ao com um programa main. Lembrando que:

x = −b ± √∆/2*a */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int raizes(float A, float B, float C, float * X1, float * X2){
    double delta = pow(B,2) - (4*A*C);
    if(delta>0){
        *X1 = ((-B)+sqrt(delta))/(2*A);
        *X2 = ((-B)-sqrt(delta))/(2*A);
        return 2;
    }else if(delta == 0){
        *X1 = (-B)/(2*A);
        return 1;
    }else{
        return 0;
    }
}

int main(){
    float A, B, C;
    float X1, X2;
    scanf("%f %f %f", &A, &B, &C);
    int resultado = raizes(A,B,C,&X1,&X2);
    if (resultado == 2) {
        printf("Duas raízes reais: X1 = %.2f, X2 = %.2f\n", X1, X2);
    } else if (resultado == 1) {
        printf("Uma raiz real: X1 = %.2f\n", X1);
    } else {
        printf("Nenhuma raiz real.\n");
    }
    return 0;
}