#include "recursividade.h"

void TLista_FazVazia ( TLista * pLista ) {
   pLista->primeiro = 0;
   pLista->ultimo = 0;
}

int TLista_Insere ( TLista * pLista , TItem x) {
    if(pLista->ultimo == MAXTAM) return 0;
    pLista->vet[pLista->ultimo].num = x.num;
    pLista->ultimo++;
    return 1; 
}

int recursividade(TLista* pLista, int posicao){
    if (posicao == pLista->ultimo - 1)
    {
        return pLista->vet[pLista->ultimo-1].num;
    }

    int soma = 0;
    soma = pLista->vet[posicao].num + recursividade(pLista, posicao+1);
    return soma;
}