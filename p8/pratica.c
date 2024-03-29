#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int instancia = 1, controlBarraN = 0;
    //enquanto houver dados
    while (1) {
        int n;
        int time1, time2, pontos1, pontos2;
        int i, npartidas;
        Time *vetor;

        //leia o numero de times
        scanf("%d", &n);

        //se for zero, o programa acaba
        if(n == 0)
        {
            return 0;
        }
        if(controlBarraN > 0)
        {
            printf("\n");
        }
        //aloque o vetor
        vetor = alocaVetor(n);
        //calcula o numero de partidas
        npartidas = n * (n - 1) / 2;

        //para cada partida...
        for (i = 0; i < npartidas; i++) {
            scanf("%d %d %d %d", &time1, &pontos1, &time2, &pontos2);
            // preencher o vetor de estruturas de acordo com os dados lidos
            jogo(vetor, time1, pontos1, time2, pontos2);
        }

        calculaRazao(vetor, n);
        // ordenar os times
        ordenacao(vetor, n);
        //printf("%d %d %lf %lf\n", vetor[3].pontos, vetor[4].pontos, vetor[3].razao, vetor[4].razao);
        // imprima o resultado
        imprime(vetor, n, instancia);
        instancia++;
        controlBarraN++;

        // desaloque o vetor
        desalocaVetor(&vetor);
    }


    return 0;
}
