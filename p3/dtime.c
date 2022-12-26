#include "duende.h"
#include "dtime.h"
#include <stdio.h>
#include <stdlib.h>

typedef enum { NAO=0, SIM } ESCALADO; //Implementei a struct duende nesse .c porque o mesmo não estava conseguindo encontrar a implementação da struct duende na hora de implementar a struct time, mesmo com o uso de "*" no nome Duende

struct duende {
    char nome[20];
    int idade;
    ESCALADO escalado;
};

struct time
{
    Duende* lider;
    Duende* piloto;
    Duende* entregador;
};

// Manter como especificado
Time *alocaTimes(int n)
{
    /* Aloca um vetor de n times */
    Time *times;
    times = (Time *)malloc(n * sizeof(Time));
    return times;
}

// Manter como especificado
void desalocaTimes(Time **times, int n)
{
    /* Desaloca um vetor ou um unico time alocado dinamicamente */

    for (int i = 0; i < n; i++)
    {
        free((*times)[i].entregador);
        free((*times)[i].lider);
        free((*times)[i].piloto);
    }
  
    free(*times);
}

// Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes)
{
    int i, index;
    int qtdTime = qtdDuendes / 3;
    // Escalando os lideres
    for (i = 0; i < qtdTime; i++)
    {
        index = proximoMaisVelho(duendes, qtdDuendes);
        times[i].lider = copiaDuende(duendes, index);
        escalarDuende(duendes, index);
    }

    // Escalando os pilotos
    for (i = 0; i < qtdTime; i++)
    {
        index = proximoMaisVelho(duendes, qtdDuendes);
        times[i].piloto = copiaDuende(duendes, index);
        escalarDuende(duendes, index);
    }

    // Escalando os entregadores
    for (i = 0; i < qtdTime; i++)
    {
        index = proximoMaisVelho(duendes, qtdDuendes);
        times[i].entregador = copiaDuende(duendes, index);
        escalarDuende(duendes, index);
    }
}

// Manter como especificado
void printTimes(Time *times, int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        printf("Time %d\n", i + 1);
        printf("[L] ");
        printDuende(times[i].lider);
        printf("[P] ");
        printDuende(times[i].piloto);
        printf("[E] ");
        printDuende(times[i].entregador);
        printf("\n");
    }
}
