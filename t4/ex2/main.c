//ORDENE CADA PALAVRA UTILIZANDO METODOS DE ORDENACAO
//SE NENHUM METODO FOR APLICADO DURANTE A RESOLUCAO, A QUESTAO SERA INVALIDADA
#include "ordenacao.h"
#include <string.h>
#define TAMMAX 43
int main(int argc, char const *argv[])
{
    int p;
    scanf("%d", &p);
    for (int i = 0; i < p; i++)
    {
        char palavra[TAMMAX], palavraMinuscula[TAMMAX], palavraCopia[TAMMAX];
        scanf("%s", palavra);
        int tam = strlen(palavra) - 1;
        strcpy(palavraMinuscula, palavra);
        converteMinuscula(palavraMinuscula, tam);
        strcpy(palavraCopia, palavraMinuscula);
        ordenaPalavra(palavraMinuscula, 0, tam);
        if(strcmp(palavraCopia, palavraMinuscula) == 0 && (verificaOrdenacao(palavraMinuscula, tam)))
        {
            printf("%s: O\n", palavra);
        }
        else
        {
            printf("%s: N\n", palavra);
        }
    }
    
    return 0;
}
