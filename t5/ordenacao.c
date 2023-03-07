#include "ordenacao.h"
#include <stdio.h>
#include <string.h>



void heap_constroi(Pessoa *pessoas, int n)
{
    int esq = (n / 2) - 1;
    while (esq >= 0)
    {
        heap_refaz(pessoas, esq, n - 1);
        esq--;
    }
}

void heap_refaz(Pessoa *pessoas, int esq, int dir){
    int i = esq;
    int j = i * 2   + 1;
    Pessoa aux = pessoas[i];
    while(j <= dir)
    {
        if ((j < dir)&&(!compara(pessoas[j], pessoas[j+1])))
        {
            j = j + 1;
        }
        if(compara(aux, pessoas[j]))
        {
            break;
        }
        pessoas[i] = pessoas[j];
        i = j;
        j = i * 2 + 1;
    }
    pessoas[i] = aux;
}

void heap_sort(Pessoa* pessoas, int n){
    heap_constroi(pessoas, n);
    while(n > 1)
    {
        Pessoa aux = pessoas[n-1];
        pessoas[n-1] = pessoas[0];
        pessoas[0] = aux;
        n = n - 1;
        heap_refaz(pessoas, 0, n -1);
    }
}

int compara(Pessoa p1, Pessoa p2){
    if((strcmp(p1.cor, p2.cor) < 0) || (((strcmp(p1.cor, p2.cor) == 0) && (p1.tamanaho > p2.tamanaho))) || ((strcmp(p1.cor, p2.cor) == 0) && ((p1.tamanaho == p2.tamanaho) && ((strcmp(p1.nome, p2.nome) < 0)))))
    {
        return 0;
    }
    return 1;
}
