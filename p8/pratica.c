#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    int instancia = 1;
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

        // ordenar os times
        ordenacao(vetor, n);

        // imprima o resultado
        imprime(vetor, n, instancia);
        printf("\n");
        printf("%d %d %d %d %lf %lf\n", vetor[0].pontos, vetor[1].pontos, vetor[0].perdeuUmJogo, vetor[1].perdeuUmJogo, vetor[0].razao, vetor[1].razao);
        instancia++;

        // desaloque o vetor
        desalocaVetor(&vetor);
    }


    return 0;
}
