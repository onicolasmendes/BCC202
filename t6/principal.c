#include "busca.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    TDicionario dic;
    TDicionarioInicio(&dic);
    for (int i = 0; i < dic.max; i++)
    {
        scanf("%d", &dic.v[i].Chave);
    }
    int chave;
    scanf("%d", &chave);

    ordena(&dic, 0, dic.max - 1);

    int pos = TDicionarioBinaria(&dic, 0, dic.max-1, chave);

    printf("chave %d na posicao %d\n", chave, pos);

    free(dic.v);
    
    return 0;
}
