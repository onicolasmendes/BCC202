#include "ordenacao.h"

void converteMinuscula(char *palavra, int tam)
{
    for (int i = 0; palavra[i] != '\0'; i++)
    {
        if (palavra[i] >= 65 && palavra[i] <= 90)
        {
            palavra[i] = palavra[i] + 32;
        }
    }

    //printf("%s\n", palavra);
}

void ordenaPalavra(char *palavra, int inicio, int final)
{
    int pivo, esquerda, direita;
    char aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while (esquerda <= direita)
    {
        while ((esquerda < final) && (palavra[esquerda] < palavra[pivo]))
        {
            esquerda++;
        }

        while ((direita > inicio) && (palavra[direita] > palavra[pivo]))
        {
            direita--;
        }

        if (esquerda <= direita)
        {
            aux = palavra[esquerda];
            palavra[esquerda] = palavra[direita];
            palavra[direita] = aux;
            esquerda++;
            direita--;
        }
    }

    if(direita > inicio)
    {
        ordenaPalavra(palavra, inicio, direita);
    }

    if(esquerda < final)
    {
        ordenaPalavra(palavra, esquerda, final);
    }
}

int verificaOrdenacao(char *palavra, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        if(palavra[i] >= palavra[i+1])
        {
            return 0;
        }
    }
    return 1;
}