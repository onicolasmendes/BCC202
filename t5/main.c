//IMPLEMENTE UTILIZANDO HEAPSORT
#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int n;
    int contPrint = 0;
    int control = 0;
    control = scanf("%d\n", &n);
    while(control != EOF && n)
    {
        if(contPrint>0)
        {
            printf("\n");
        }
        Pessoa *pessoas = (Pessoa*) malloc(n * sizeof(Pessoa));
        for(int i = 0; i < n; i++)
        {
            fgets(pessoas[i].nome, 62, stdin);
            int tam = strlen(pessoas[i].nome);
            pessoas[i].nome[tam - 1] = '\0';
            //printf("%s\n", pessoas[i].nome);
            scanf("%s %c\n", pessoas[i].cor,  &pessoas[i].tamanaho);
            //printf("%s %c\n", pessoas[i].cor, pessoas[i].tamanaho);
            //return 0;
        }
        heap_sort(pessoas, n);
        for(int i = 0; i < n; i++)
        {
            printf("%s %c %s\n", pessoas[i].cor, pessoas[i].tamanaho, pessoas[i].nome);
        }
        
        free(pessoas);
        contPrint++;
        control = scanf("%d\n", &n);
    }
    return 0;
}
