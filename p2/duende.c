#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duende.h"

struct duende
{
    char nome[21];
    int idade;
    ESCALADO escalado;
};

struct time
{
    char nomePiloto[21];
    char nomeConfei[21];
    char nomeEntreg[21];
    char nomeEmbrul[21];
    int idadePiloto;
    int idadeConfei;
    int idadeEntreg;
    int idadeEmbrul;
};

// Manter como especificado
void lerQuantidade(int *qtdDuendes)
{
    scanf("%d", qtdDuendes);
}

// Manter como especificado
Duende *alocaDuendes(int qtdDuendes)
{
    Duende *duendes;
    duendes = (Duende *)malloc(qtdDuendes * sizeof(Duende));
    return duendes;
}

// Manter como especificado
Time *alocaTimes(int qtdTimes)
{
    Time *times;
    times = (Time *)malloc(qtdTimes * sizeof(Time));
    return times;
}

// Manter como especificado
void desalocaDuendes(Duende **duendes)
{
    free(*duendes);
}

// Manter como especificado
void desalocaTimes(Time **times)
{
    free(*times);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int qtdDuendes)
{
    for (int i = 0; i < qtdDuendes; i++)
    {
        scanf("%s %d\n", duendes[i].nome, &duendes[i].idade);
        duendes[i].escalado = NAO;
    }
}

// Manter como especificado
void escalarTimes(Duende *duendes, Time *times, int qtdDuendes) 
{
    int i, index;
    int qtdTime = qtdDuendes / 4;
    Duende duendeTemp;

    // Escalando os lideres
    for (i = 0; i < qtdTime; i++)
    {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendeTemp = duendes[index];
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como lider de um time
        strcpy(times[i].nomePiloto, duendeTemp.nome);
        // Copiar a idade do duende encontrado como lider de um time
        times[i].idadePiloto = duendeTemp.idade;
    }

    // Escalando os confeiteiros
    for (i = 0; i < qtdTime; i++)
    {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendeTemp = duendes[index];
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como confeiteiro de um time
        strcpy(times[i].nomeConfei, duendeTemp.nome);
        // Copiar a idade do duende encontrado como confeiteiro de um time
        times[i].idadeConfei = duendeTemp.idade;
    }

    // Escalando os entregador
    for (i = 0; i < qtdTime; i++)
    {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendeTemp = duendes[index];
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como entregador de um time
        strcpy(times[i].nomeEntreg, duendeTemp.nome);
        // Copiar a idade do duende encontrado como entregador de um time
        times[i].idadeEntreg = duendeTemp.idade;
    }

    // Escalando os embrulhador
    for (i = 0; i < qtdTime; i++)
    {
        // Bucar o proximo mais velho disponivel
        index = proximoMaisVelho(duendes, qtdDuendes);
        duendeTemp = duendes[index];
        // Marca o duende como escalado
        duendes[index].escalado = SIM;
        // Copiar o nome do duende encontrado como embrulhador de um time
        strcpy(times[i].nomeEmbrul, duendeTemp.nome);
        // Copiar a idade do duende encontrado como embrulhador de um time
        times[i].idadeEmbrul = duendeTemp.idade;
    }
}

int proximoMaisVelho(Duende *duendes, int qtdDuendes) 
{
    Duende maisVelho;
    strcpy(maisVelho.nome, "Teste");
    maisVelho.idade = -1;
    maisVelho.escalado = NAO;
    int indice = -1;

    for (int i = 0; i < qtdDuendes; i++)
    {
        if (duendes[i].escalado == NAO && maisVelho.idade < duendes[i].idade)
        {
            indice = i;
            maisVelho = duendes[i];
        }
    }

    return indice;
}

// Manter como especificado
void printTimes(Time *times, int qtdTimes)
{
    for (int i = 0; i < qtdTimes; i++)
    {
        printf("Time %d\n", i + 1);
        printf("PILOTO > %s %d\n", times[i].nomePiloto, times[i].idadePiloto);
        printf("CONFEI > %s %d\n", times[i].nomeConfei, times[i].idadeConfei);
        printf("ENTREG > %s %d\n", times[i].nomeEntreg, times[i].idadeEntreg);
        printf("EMBRUL > %s %d\n\n", times[i].nomeEmbrul, times[i].idadeEmbrul);
    }
}
