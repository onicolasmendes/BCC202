#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

void lerOrdem(int *ordem)
{
    scanf("%d", ordem);
}

// manter como especificado
double **alocaMatriz(int ordem)
{
    double **matriz = malloc(ordem * sizeof(double *));
    for (int i = 0; i < ordem; i++)
    {
        matriz[i] = malloc(ordem * sizeof(double));
    }
    return matriz;
}

// manter como especificado
void desalocaMatriz(double ***M, int ordem)
{
    for (int i = 0; i < ordem; i++)
    {
        free((*M)[i]);
    }
    free(*M);
}

// manter como especificadohjjfjf
void lerOperacao(char *operacao)
{
    getchar();
    scanf("%c", operacao);
}

void lerMatriz(double **M, int ordem)
{
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            scanf("%lf", &M[i][j]);
        }
    }
}

double somaMatriz(double **M, int ordem)
{
    double soma = 0;
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (j > i && (j + i) < (ordem - 1))
            {
                soma += M[i][j];
            }
        }
    }
    return soma;
}

double media(double resultado, int ordem)
{
    int cont = 0;
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            if (j > i && (j + i) < (ordem - 1))
            {
                cont++;
            }
        }
    }
    double media = resultado / cont;
    return media;
}
void printResultado(double resultado)
{
    printf("%.1lf\n", resultado);
}
