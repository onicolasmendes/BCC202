#include <stdio.h>
#include "lista.h"

int main()
{
    // Inicializa a lista

    TLista lista, nova;
    TLista_Inicia(&lista);
    TLista_Inicia(&nova);

    // Leitura

    char c;
    c = getchar();
    while (c != EOF)
    {
        TLista_Insere_Fim(&lista, c);
        c = getchar();
    }

    // Processamento
    TCelula *aux, *aux2;
    aux2 = nova.cabeca;
    aux = lista.cabeca->prox;
    int controle = 0;

    while (aux != NULL)
    {
        if (aux->item.letra == '[')
        {
            controle = 1;
            aux = aux->prox;
        }
        else if (aux->item.letra == ']')
        {
            controle = 0;
            aux = aux->prox;
        }

        if(controle == 0 && aux->item.letra != '[' && aux->item.letra != ']')
        {
            TLista_Insere_Fim(&nova, aux->item.letra);
        }else if (controle == 1 && aux->item.letra != '[' && aux->item.letra != ']')
        {
            TLista_Insere_Inicio(&nova, aux->item.letra, aux2);
        }

        aux = aux->prox;
    }
    TLista_Imprime(&nova);
    TLista_Esvazia(&lista);
    TLista_Esvazia(&nova);

    return 0;
}