#include "recursividade.h"
int main()
{
    TLista lista;
    TLista_FazVazia(&lista);

    TItem x;
    while (scanf("%d", &x.num) != EOF)
    {
        TLista_Insere(&lista, x);
    }
    int soma;
    soma = recursividade(&lista, lista.primeiro);

    printf("%d\n", soma);

    return 0;
}