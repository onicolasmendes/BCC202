#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inicia as variaveis da lista
void TLista_Inicia(TLista *pLista)
{
    pLista->cabeca = (TCelula *)malloc(sizeof(TCelula));
    pLista->cabeca->prox = NULL;
    pLista->ultimo = pLista->cabeca;
}

// Retorna se a lista esta vazia
int TLista_EhVazia(TLista *pLista)
{
    if (pLista->ultimo == pLista->cabeca)
        return 1;
    return 0;
}

// Insere um item no final da lista
int TLista_InsereFinal(TLista *pLista, TItem x)
{
    // Aloca uma nova célula
    pLista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
    // Ponteiro último passa a apontar para a célula alocada
    pLista->ultimo = pLista->ultimo->prox;
    // Item atribuído
    pLista->ultimo->item = x;
    // O prox do ultimo passa a apontar para nulo
    pLista->ultimo->prox = NULL;
    return 1;
}

// Retira o primeiro item da lista
int TLista_RetiraPrimeiro(TLista *pLista, TItem *pX)
{
    if (TLista_EhVazia(pLista))
        return 0;

    // Variável auxiliar
    TCelula *aux;
    // Auxiliar para a primeira posição
    aux = pLista->cabeca->prox;
    // Item é passado por parâmetro
    *pX = aux->item;
    // A prox da cabeça passa a apontar para o segundo elemento que passa a ser o primeiro
    pLista->cabeca->prox = aux->prox;
    free(aux);
    return 1;
}

// Imprime os elementos da lista
void TLista_Imprime(TLista *pLista)
{
    if (TLista_EhVazia(pLista))
    {
        return;
    }

    TCelula *aux;
    aux = pLista->cabeca->prox;
    while (aux != NULL)
    {
        printf("%s ", aux->item.nome);
        aux = aux->prox;
    }
    printf("\n");
}

// Remove cada elemento de uma lista e libera a memória
void TLista_Esvazia(TLista *pLista)
{
    TCelula *aux1;
    aux1 = pLista->cabeca;
    while (aux1 != NULL)
    {
        TCelula *aux2;
        aux2 = aux1;
        aux1 = aux1->prox;
        free(aux2);
    }
}

// Acrescenta o conteudo de uma lista ao final de outra, apenas manipulando ponteiros
void TLista_append(TLista *pLista1, TLista *pLista2)
{
    if(TLista_EhVazia(pLista1) || TLista_EhVazia(pLista2)) return;
    pLista1->ultimo->prox = pLista2->cabeca->prox;
    free(pLista2->cabeca);
}

// Inclui o conteudo de uma lista em outra, na posicao anterior a str, apenas manipulando ponteiros
void TLista_include(TLista *pLista1, TLista *pLista2, char *str)
{
    TCelula *aux1;
    aux1 = pLista1->cabeca;
    
    while (aux1 != NULL)
    {
        TCelula *aux2;
        aux2 = aux1;
        aux1 = aux1->prox;
        
        if (strcmp(aux1->item.nome, str) == 0)
        {
           aux2->prox = pLista2->cabeca->prox;
           pLista2->ultimo->prox = aux1;
           free(pLista2->cabeca);
           return;
        }
    }
    
}
