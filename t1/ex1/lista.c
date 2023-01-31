#include "lista.h"

void TLista_Inicia (TLista * pLista ) {
    //Aloca a cabeça da lista
    pLista->cabeca = (TCelula*) malloc(sizeof(TCelula));
    //prox da cabeça aponta prs NULL
    pLista->cabeca->prox = NULL;
    //ultimo aponta pra cabeça
    pLista->ultimo = pLista->cabeca;
}

int TLista_EhVazia ( TLista * pLista ) {
    return pLista->ultimo == pLista->cabeca;
}

int TLista_Insere_Fim ( TLista * pLista , char x) {
    TCelula *new = (TCelula*) malloc(sizeof(TCelula));
    if(new == NULL) return 0;
    new->item.letra = x;
    //Ultimo elemento aponta pra new
    pLista->ultimo->prox = new;
    //Ultimo aponta pra new
    pLista->ultimo = new;
    //o prox da celula aponta pra NULL
    pLista->ultimo->prox = NULL;

    if(TLista_EhVazia(pLista))
    {
        pLista->cabeca->prox = new;
    }

    return 1;
}

int TLista_Insere_Inicio ( TLista * pLista , char x, TCelula *aux){
    TCelula *new = (TCelula*) malloc(sizeof(TCelula));
    if(new==NULL) return 0;
    new->item.letra = x;
    //nova celula aponta pro primeiro elemento
    new->prox = aux->prox;
    //cabeça aponta pra nova celula
    pLista->cabeca = new;
    return 1;

}

void TLista_Esvazia (TLista * pLista){
    TCelula *aux1, *aux2;
    aux1 = pLista->cabeca;
    while(aux1 != NULL)
    {
        aux2 = aux1;
        aux1 = aux1->prox;
        free(aux2);
    }
    
}

void TLista_Imprime ( TLista * pLista ){

    if(TLista_EhVazia(pLista))
    {
        return;
    }

    TCelula *aux;
    aux = pLista->cabeca->prox;
    while(aux != NULL)
    {
        printf("%c", aux->item.letra);
        aux = aux->prox;
    }
    printf("\n");
}