#include "ordenacao.h"
#include <stdlib.h>
#include <stdio.h>

// Manter como especificado
Time *alocaVetor(int n)
{
    Time *new = (Time *)calloc(n ,sizeof(Time));
    for (int i = 0; i < n; i++)
    {
        new[i].numTime = i + 1;
    }
    return new;
}

// Manter como especificado
void desalocaVetor(Time **vetor)
{
    free(*vetor);
}

// implemente sua funcao de ordenacao aqui, que deve invocar a funcao compare
void ordenacao(Time *vetor, int n)
{
    heapBuild(times, n);

    Time aux;
    while(n > 1){
        copiaTime(&aux, &times[n - 1]);
        copiaTime(&times[n - 1], &times[0]);
        copiaTime(&times[0], &aux);

        n--;

        heapReBuild(times, 0, n-1);
    }
}

// compara dois elementos do vetor de times, indicado se o metodo de ordenacao deve troca-los de lugar ou nao
int compare(const Time t1, const Time t2)
{

    if (t1.pontosSofridos == 0 && t2.pontosSofridos == 0)
    {
        t1.razao = t1.pontosFeitos;
        t2.razao = t2.pontosFeitos;
    }
    else if (t2.pontosSofridos == 0)
    {
        t2.razao = t2.pontosFeitos;
        t1.razao = t1.pontosFeitos /  t1.pontosSofridos;
    }
    else if (t1.pontosSofridos == 0)
    {
        t1.razao = t1.pontosFeitos;
        t2.razao = t2.pontosFeitos / t2.pontosSofridos;
    }else{
        t1.razao = t1.pontosFeitos /  t1.pontosSofridos;
        t2.razao = t2.pontosFeitos / t2.pontosSofridos;
    }



    if (t1.pontos > t2.pontos)
    {
        return 1;
    }
    else if (t1.pontos < t2.pontos)
    {
        return 0;
    }
    else if (t1.pontos == t2.pontos && t1.razao > t2.razao)
    {
        return 1;
    }
    else if (t1.pontos == t2.pontos && t1.razao < t2.razao)
    {
        return 0;
    }else if(t1.pontos == t2.pontos && t1.razao == t2.razao && t1.pontosFeitos > t2.pontosFeitos)
    {
        return 1;
    }else if(t1.pontos == t2.pontos && t1.razao == t2.razao && t1.pontosFeitos < t2.pontosFeitos)
    {
        return 0;
    }else if(t1.pontos == t2.pontos && t1.razao == t2.razao && t1.pontosFeitos == t2.pontosFeitos && t1.numTime > t2.numTime)
    {
        return 0;
    }else if(t1.pontos == t2.pontos && t1.razao == t2.razao && t1.pontosFeitos == t2.pontosFeitos && t1.numTime < t2.numTime)
    {
        return 1;
    }
}

void heapBuild(Time *times, int n)
{
    int esq = (n / 2) - 1;
    while(esq >= 0)
    {
        heapReBuild(times, esq, n - 1);
        esq--;
    }
}

void heapReBuild(Time *times, int esq, int dir)
{
    int i = e(sq;
    int j = i * 2 + 1;
    Time *aux = times[i];

    while(j <= dir)
    {
        if(j < dir && compare(times[j], times[j+1])) //Compara  os irmãos
        {
            j++; //Caso o irmão j + 1 tenha mais prioridade j passa a ser a posição dele
        }
        
        if(!compare(aux, times[j])) //Compara o irmão com mais prioridade com o pai
        {
            break; //Caso o pai tenha mais prioridade, sai fora do loop
        }

        copiaTime(&times[i], &times[j]); //Caso o pai esteja na posição errada, troca com o filho de maior prioridade

        i = j;
        j = i * 2 + 1;

    }
    copiaTime(&times[i], &aux);
}

void copiaTime(Time *t1, Time *t2)
{
    t1->numTime = t2->numTime;
    t1->pontos = t2->pontos;
    t1->pontosFeitos = t2->pontosFeitos; 
    t1->pontosSofridos = t2->pontosSofridos;
    t1->razao = t2->razao;
}

void jogo(Time *times, int t1, int p1, int t2, int p2)
{
     times[t1-1].pontosFeitos += p1;
     times[t1-1].pontosSofridos += p2;
     times[t2-1].pontosFeitos += p2;
     times[t2-1].pontosSofridos += p1;
    if(p1 > p2)
    {
        times[t1-1].pontos += 2;
        times[t2-1].pontos += 1;
    }else if(p1 < p2)
    {
        times[t2-1].pontos += 2;
        times[t1-1].pontos += 1;
    }
}
void imprime(Time *times, int n, int instancia)
{
    printf("Instancia %d\n", instancia);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", times[i].numTime);
    }
    printf("\n");
}