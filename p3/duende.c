#include "duende.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { NAO=0, SIM } ESCALADO;

struct duende {
    char nome[20];
    int idade;
    ESCALADO escalado;
};

// Manter como especificado
void lerQuantidade(int *qtd) { 
    /* Le a quantidade de duendes que serao inseridos */
    scanf("%d", qtd);
}

// Manter como especificado
Duende *alocaDuendes(int n) { 
    /* Aloca n de Duendes*/
    Duende *duendes;
    duendes = (Duende*) malloc(n * sizeof(Duende));
    return duendes;
}

// Manter como especificado
Duende *copiaDuende(Duende *duendes, int i) {
    /* Aloca um novo duende baseado nos dados de um outro duende */ 
    Duende *duende_temp;
    duende_temp = (Duende*) malloc(sizeof(Duende));
    *duende_temp = duendes[i];
    return duende_temp;
}

// Manter como especificado
void desalocaDuendes(Duende **duendes){
    /* Desaloca um vetor ou um unico duende alocado dinamicamente */
    free(*duendes);
}

// Manter como especificado
void lerDuendes(Duende *duendes, int n) {
    /* Lê os dados de n de Duendes */
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", duendes[i].nome, &duendes[i].idade);
        duendes[i].escalado = NAO;
    }  
}

// Manter como especificado
int proximoMaisVelho(Duende *duendes, int n) {
    /* Pega o próximo duende mais velho que ainda nao foi escalado */
    //Ordena o vetor
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (duendes[i].idade < duendes[j].idade)
            {
                Duende temp = duendes[i];
                duendes[i] = duendes[j];
                duendes[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(duendes[i].escalado == NAO)
        {
            return i;
        }
    }
    
    return 0;
}

// Manter como especificado
void escalarDuende(Duende *duendes, int index) {
    /* Dado um vetor de duendes, "seta" como escalado um duende */
    duendes[index].escalado = SIM;
}

// Manter como especificado
void printDuende(Duende *duende) {
    /* Imprime os dados de um duende e um \n no final */
    printf("%s %d\n", duende->nome, duende->idade);
}