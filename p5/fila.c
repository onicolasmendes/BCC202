#include "fila.h"
#include "pilha.h"
#include <stdlib.h>

bool FilaInicia(Fila *pFila)
{
    return ListaInicia(pFila);
}

bool FilaEnfileira(Fila *pFila, Item item)
{
    Celula *new = (Celula*) malloc(sizeof(Celula));
    if(new == NULL)
    {
        return false;
    }
    new->item = item;
    new->prox = NULL;
    pFila->ultimo->prox = new;
    pFila->ultimo = new;
    return true;
}

bool FilaDesinfeleira(Fila *pFila, Item *pItem)
{
    if(FilaEhVazia(pFila))
    {
        return false;
    }
    //printf("entrei\n");
    Celula *aux;
    aux = pFila->cabeca->prox;
    *pItem = aux->item;
    pFila->cabeca->prox = pFila->cabeca->prox->prox;
    free(aux);
    return true;
}

bool FilaEhVazia(Fila *pFila)
{
    return ListaEhVazia(pFila);
}

void FilaLibera(Fila *pFila)
{
    ListaLibera(pFila);
}

bool FilaInverte(Fila *pFila)
{
    Celula *aux1;
    Item Titem;
    Pilha pilha;
    PilhaInicia(&pilha);

    aux1 = pFila->cabeca->prox;

    while (aux1 != NULL)
    {
        PilhaPush(&pilha, aux1->item);
        aux1 = aux1->prox;
    }

    aux1 = pFila->cabeca->prox;

    while (aux1 != NULL)
    {  
        FilaDesinfeleira(pFila, &Titem);
        aux1 = pFila->cabeca->prox;
    }

    pFila->ultimo = pFila->cabeca;
    
    aux1 = pilha.cabeca->prox;
    
    while (aux1 != NULL)
    {   
        FilaEnfileira(pFila, aux1->item);
        aux1 = aux1->prox;
    }

    PilhaLibera(&pilha);

    return true;
}
