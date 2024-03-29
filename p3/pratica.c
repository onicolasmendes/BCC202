#include <stdio.h>
#include "duende.h"
#include "dtime.h"

int main() {
    int qtdDuendes, qtdTimes;
    Duende *duendes;
    Time *times;

    lerQuantidade(&qtdDuendes);
    qtdTimes = qtdDuendes / 3;
    duendes = alocaDuendes(qtdDuendes);
    times = alocaTimes(qtdTimes);
    lerDuendes(duendes, qtdDuendes);
    escalarTimes(duendes, times, qtdDuendes);
    printTimes(times, qtdTimes);
    desalocaDuendes(&duendes);
    desalocaTimes(&times, qtdTimes);

    /*
    Ordem de complexidade:

    Considerando o termo de maior grau de cada função, temos:

    proximoMaisVelho = O (n) -> Complexidade linear 

    escalarTimes = O (n^2) -> Complexidade quadrática

   ------------------------------------------------------------------------

    proximoMaisVelho = O (escalarTimes)
    escalarTimes = omega (proximoMaisVelho)

    (O = Big o)
    */

    return 0; //nao remova
}
