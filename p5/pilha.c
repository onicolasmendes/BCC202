#include "pilha.h"
#include <stdlib.h>

bool PilhaInicia(Pilha* pPilha) {
    pPilha->cabeca = (Celula*) malloc(sizeof(Celula));
    if(pPilha->cabeca == NULL)
    {
        return false;
    }
    pPilha->cabeca->prox = NULL;
    return true;
}

bool PilhaPush(Pilha* pPilha, Item item) {
    Celula *new = (Celula*) malloc(sizeof(Celula));
    if(new == NULL)
    {
        return false;
    }
    new->item = item;
    new->prox = pPilha->cabeca->prox;
    pPilha->cabeca->prox = new;
    return true;
}

bool PilhaPop(Pilha* pPilha, Item* pItem) {
    if(PilhaEhVazia(pPilha))
    {
        return false;
    }
    Celula *aux;
    aux = pPilha->cabeca->prox;
    *pItem = aux->item;
    pPilha->cabeca->prox = aux->prox;
    free(aux);
    return true;
 }

bool PilhaEhVazia(Pilha* pPilha) {
    if(pPilha->cabeca->prox == NULL){
        return true;
    }
    return false;
}

void PilhaLibera(Pilha* pPilha) {
    ListaLibera(pPilha);
}