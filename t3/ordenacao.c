#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordenacao.h"

struct upa
{
    char nome[50];
    int emergencia;
    int urgencia;
    int semUrgencia;
    int plantonistas;
};

int alocarUpa(TADupa **aux, int n)
{
    *aux = (TADupa *)malloc(n * sizeof(TADupa));
    if (*aux == NULL)
    {
        return 0;
    }
    return 1;
}

void preencheVetor(TADupa *upas, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d %d\n", upas[i].nome, &upas[i].emergencia, &upas[i].urgencia, &upas[i].semUrgencia, &upas[i].plantonistas);
    }
}



void imprimeUpas(TADupa *upas, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s %d %d %d %d\n", upas[i].nome, upas[i].emergencia, upas[i].urgencia, upas[i].semUrgencia, upas[i].plantonistas);
    }
}

void desalocaUpas(TADupa **aux)
{
    free(*aux);
}

void ordenaEmergencia(TADupa *upas, int inicio, int final)
{
    int esquerda, direita, pivo;
    TADupa aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while (esquerda <= direita)
    {
        while ((esquerda < final) && (upas[esquerda].emergencia > upas[pivo].emergencia))
        {
            esquerda++;
        }

        while ((direita > inicio) && (upas[direita].emergencia < upas[pivo].emergencia))
        {
            direita--;
        }

        if (esquerda <= direita)
        {
            aux = upas[esquerda];
            upas[esquerda] = upas[direita];
            upas[direita] = aux;
            esquerda++;
            direita--;
        }
    }
    if (direita > inicio)
    {
        ordenaEmergencia(upas, inicio, direita);
    }

    if (esquerda < final)
    {
        ordenaEmergencia(upas, esquerda, final);
    }
}

void ordenaUrgencia(TADupa *upas, int inicio, int final)
{
    int esquerda, direita, pivo;
    TADupa aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while (esquerda <= direita)
    {
        while ((esquerda < final) && (upas[esquerda].urgencia > upas[pivo].urgencia))
        {
            esquerda++;
        }

        while ((direita > inicio) && (upas[direita].urgencia < upas[pivo].urgencia))
        {
            direita--;
        }

        if (esquerda <= direita)
        {
            aux = upas[esquerda];
            upas[esquerda] = upas[direita];
            upas[direita] = aux;
            esquerda++;
            direita--;
        }
    }
    if (direita > inicio)
    {
        ordenaUrgencia(upas, inicio, direita);
    }

    if (esquerda < final)
    {
        ordenaUrgencia(upas, esquerda, final);
    }
}

void ordenaSemUrgencia(TADupa *upas, int inicio, int final)
{
    int esquerda, direita, pivo;
    TADupa aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while (esquerda <= direita)
    {
        while ((esquerda < final) && (upas[esquerda].semUrgencia > upas[pivo].semUrgencia))
        {
            esquerda++;
        }

        while ((direita > inicio) && (upas[direita].semUrgencia < upas[pivo].semUrgencia))
        {
            direita--;
        }

        if (esquerda <= direita)
        {
            aux = upas[esquerda];
            upas[esquerda] = upas[direita];
            upas[direita] = aux;
            esquerda++;
            direita--;
        }
    }
    if (direita > inicio)
    {
        ordenaSemUrgencia(upas, inicio, direita);
    }

    if (esquerda < final)
    {
        ordenaSemUrgencia(upas, esquerda, final);
    }
}

void ordenaPlantonistas(TADupa *upas, int inicio, int final)
{
    int esquerda, direita, pivo;
    TADupa aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while (esquerda <= direita)
    {
        while ((esquerda < final) && (upas[esquerda].plantonistas < upas[pivo].plantonistas))
        {
            esquerda++;
        }

        while ((direita > inicio) && (upas[direita].plantonistas > upas[pivo].plantonistas))
        {
            direita--;
        }

        if (esquerda <= direita)
        {
            aux = upas[esquerda];
            upas[esquerda] = upas[direita];
            upas[direita] = aux;
            esquerda++;
            direita--;
        }
    }
    if (direita > inicio)
    {
        ordenaPlantonistas(upas, inicio, direita);
    }

    if (esquerda < final)
    {
        ordenaPlantonistas(upas, esquerda, final);
    }
}

void ordenaNome(TADupa *upas, int inicio, int final)
{
    int esquerda, direita, pivo;
    TADupa aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while (esquerda <= direita)
    {
        while ((esquerda < final) && (strcmp(upas[esquerda].nome, upas[pivo].nome) < 0))
        {
            esquerda++;
        }

        while ((direita > inicio) && (strcmp(upas[direita].nome, upas[pivo].nome) > 0))
        {
            direita--;
        }

        if (esquerda <= direita)
        {
            // Troca posição
            aux = upas[esquerda];
            upas[esquerda] = upas[direita];
            upas[direita] = aux;

            esquerda++;
            direita--;
        }
    }

    // Chamadas recursivas
    if (direita > inicio)
    {
        ordenaNome(upas, inicio, direita);
    }
    if (esquerda < final)
    {
        ordenaNome(upas, esquerda, final);
    }
}

void ordenaUpas(TADupa *upas, int n)
{
    int i;

    ordenaEmergencia(upas, 0, n - 1);

    for (i = 0; i < n - 1; i++)
    {
        if (upas[i].emergencia == upas[i + 1].emergencia)
        {
            int novoFinal = i;
            while ((novoFinal < n) && (upas[i].emergencia == upas[novoFinal].emergencia))
            {
                novoFinal++;
            }
            novoFinal--;
            ordenaUrgencia(upas, i, novoFinal);
            i = novoFinal;
        }
    }

    for (i = 0; i < n - 1; i++)
    {
        if ((upas[i].emergencia == upas[i + 1].emergencia) && (upas[i].urgencia == upas[i + 1].urgencia))
        {
            int novoFinal = i;
            while ((novoFinal < n) && (upas[i].emergencia == upas[novoFinal].emergencia) && (upas[i].urgencia == upas[novoFinal].urgencia))
            {
                novoFinal++;
            }
            novoFinal--;
            ordenaSemUrgencia(upas, i, novoFinal);
            i = novoFinal;
        }
    }

    for (i = 0; i < n - 1; i++)
    {
        if ((upas[i].emergencia == upas[i + 1].emergencia) && (upas[i].urgencia == upas[i + 1].urgencia) && (upas[i].semUrgencia == upas[i + 1].semUrgencia))
        {
            int novoFinal = i;
            while ((novoFinal < n) && (upas[i].emergencia == upas[novoFinal].emergencia) && (upas[i].urgencia == upas[novoFinal].urgencia) && (upas[i].semUrgencia == upas[novoFinal].semUrgencia))
            {
                novoFinal++;
            }
            novoFinal--;
            ordenaPlantonistas(upas, i, novoFinal);
            i = novoFinal;
        }
    }

    for (i = 0; i < n - 1; i++)
    {
        if ((upas[i].emergencia == upas[i + 1].emergencia) && (upas[i].urgencia == upas[i + 1].urgencia) && (upas[i].semUrgencia == upas[i + 1].semUrgencia) && (upas[i].plantonistas == upas[i + 1].plantonistas))
        {
            int novoFinal = i;
            while ((novoFinal < n) && (upas[i].emergencia == upas[novoFinal].emergencia) && (upas[i].urgencia == upas[novoFinal].urgencia) && (upas[i].semUrgencia == upas[novoFinal].semUrgencia) && (upas[i].plantonistas == upas[novoFinal].plantonistas))
            {
                novoFinal++;
            }
            novoFinal--;
            ordenaNome(upas, i, novoFinal);
            i = novoFinal;
        }
    }
}
