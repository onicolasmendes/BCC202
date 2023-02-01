#ifndef RECURSIVIDADE
#define RECURSIVIDADE

# define MAXTAM 1000
#include <stdio.h>
#include <stdlib.h>

typedef struct titem {
    int num;
} TItem ;

typedef struct {
    TItem vet[MAXTAM];
    int primeiro, ultimo;
} TLista ;

void TLista_FazVazia ( TLista * pLista );
int recursividade(TLista *plista, int posicao);
int TLista_Insere ( TLista * pLista , TItem x);

#endif