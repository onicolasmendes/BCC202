#include "busca.h"
#include <stdio.h>
#include <stdlib.h>


void TDicionarioInicio(TDicionario *t)
{
    t->n = 0;
    t->max = 1000;
    t->v = (TRegistro*) malloc(t->max * sizeof(TRegistro));
}

int TDicionarioBinaria(TDicionario *t, int esq, int dir, int x){
    int meio = (esq + dir)/2;

    if(t->v[meio].Chave != x && esq == dir)
    {
        return -1;
    }
    else if(x > t->v[meio].Chave)
    {
        return TDicionarioBinaria(t, meio + 1, dir, x);
    }
    else if(x < t->v[meio].Chave)
    {
        return TDicionarioBinaria(t, esq, meio - 1, x);
    }
    else
    {
        return meio;
    }
}

void ordena(TDicionario *dic, int inicio, int final)
{
    int pivo, esquerda, direita;
    TRegistro aux;
    pivo = inicio;
    esquerda = inicio;
    direita = final;

    while(esquerda <= direita)
    {
        while((esquerda < final) && (dic->v[esquerda].Chave < dic->v[pivo].Chave))
        {
            esquerda++;
        }
        while((direita > inicio) && (dic->v[direita].Chave > dic->v[pivo].Chave))
        {
            direita--;
        }
        if(esquerda <= direita)
        {
            aux = dic->v[esquerda];
            dic->v[esquerda] = dic->v[direita];
            dic->v[direita] = aux;
            esquerda++;
            direita--;
        }
    }
    if(direita > inicio)
    {
        ordena(dic, inicio, direita);
    }
    if(esquerda < final)
    {
        ordena(dic, esquerda, final);
    }
}