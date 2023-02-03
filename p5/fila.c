#include "fila.h"
#include "pilha.h"

bool FilaInicia(Fila *pFila)
{
    return ListaInicia(pFila);
}

bool FilaEnfileira(Fila *pFila, Item item)
{
    return ListaInsereFinal(pFila, item);
}

bool FilaDesinfeleira(Fila *pFila, Item *pItem)
{
    return ListaRetiraPrimeiro(pFila, pItem);
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
    Celula *aux1, *aux2;
    Item item;
    Pilha pilha;
    PilhaInicia(&pilha);

    aux1 = pFila->cabeca->prox;

    while (aux1 != NULL)
    {
        // printf("%s\n", aux1->item.nome);
        PilhaPush(&pilha, aux1->item);
        aux1 = aux1->prox;
    }
    aux1 = pilha.cabeca->prox;

    while (aux1 != NULL)
    {
        // printf("%s\n", aux1->item.nome);

        //    printf("%s\n", aux2->item.nome);
        FilaDesinfeleira(pFila, &item);

        aux1 = aux1->prox;
    }

    aux1 = pilha.cabeca->prox;
    
    while (aux1 != NULL)
    {
        printf("%s\n", aux1->item.nome);
        FilaEnfileira(pFila, aux1->item);
        aux1 = aux1->prox;
    }

    PilhaLibera(&pilha);

    return true;
}
