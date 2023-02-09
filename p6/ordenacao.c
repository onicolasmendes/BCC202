#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>

//Manter como especificado
int *alocaVetor(int *vetor, int n){
    int* vet = (int*) malloc(n * sizeof(int));
    if(vet == NULL)
    {
        printf("Memória insuficiente\n");
        exit (1);
    }
    return vet;
}

//Manter como especificado
int *desalocaVetor(int *vetor){
    free(vetor);
    return vetor;
}

void ordenacao(int *vetor, int n, int *movimentos){
    int aux;
    for(int i = 0; i < n; i++)
    {
        for (int j = 1; j < n-i; j++)
        {
            if(vetor[j] < vetor[j-1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j-1];
                vetor[j - 1] = aux;
                *movimentos+=1;   
            }
        }
        
    }
}
