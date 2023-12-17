/* ----------------- File : it_hanoi .c - --- -- --- -- --- -- --+
2 | Torre de Hanoi Recursivo |
3 |

|

4 |

|

5 | Implementado por Guilherme C. Pena em 24/08/2014 |
6 + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+ */
/*
9 Obviamente que queremos realizar a tarefa com o menor numero de movimentos
possivel . Isto pode ser atingido com o seguinte algoritmo recursivo :
10 1. Mova n -1 discos do pino de origem para o pino de trabalho .
11 2. Mova o n- esimo do pino de origem para o pino de destino .
12 3. Mova os n -1 discos do pino de trabalho para o pino de destino .
13
14 Este algoritmo realiza exatamente 2^n -1 movimentos , que e provado ser o numero
minimo .
15 */


 // Bibliotecas --------------------------------
 # include <stdio.h>
 // --------------------------------------------

 void rec_hanoi (int n, char origem , char dest , char trab ) {
    if (n >0) {
    rec_hanoi (n -1 , origem ,trab , dest );
    printf (" Mova o disco %d do pino %c para %c\n", n, origem , dest ) ;
    rec_hanoi (n -1 , trab ,dest , origem );
    }
 }

 // MAIN
 int main () {
    int discos ;
    printf (" Digite a quantidade de discos :\n");
    scanf ("%d", &discos ) ;
    printf (" ------- RECURSIVO - - - - - - - -\n") ;
    rec_hanoi (discos , 'A', 'C','B') ;
    printf (" ---------------------------------------\n") ;

    return 0;
 }