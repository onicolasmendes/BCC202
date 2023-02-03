#include <stdio.h>
#include "lista.h"
#define MAXTAM 100000

int main()
{
    // Inicializa a lista

    TLista lista;
    TLista_Inicia(&lista);
    
    // Leitura
    char textoDigitado[MAXTAM], beiju[MAXTAM];
    int i = 0, j, iBeiju = -1;
    // Leitura linha por linha
    while (fgets(textoDigitado, MAXTAM, stdin) != NULL)
    {
        int tam = strlen(textoDigitado);
        if (textoDigitado[tam - 1] == '\n')
        {
            textoDigitado[tam - 1] = '\0';
            tam--;
        }

        if (textoDigitado[0] == '[')
        {
            i = 1;
        }
        else
        {
            i = 0;
        }
        for (; i < tam; i++)
        {
            if (textoDigitado[i] == '[')
            {

                for (j = i + 1; j < tam && textoDigitado[j] != '[' && textoDigitado[j] != ']'; j++)
                {
                    iBeiju++;
                    beiju[iBeiju] = textoDigitado[j];
                }
                beiju[iBeiju + 1] = '\0';
                for (int b = iBeiju; b >= 0; b--)
                {
                    TLista_Insere_Inicio(&lista, beiju[b]);
                }
                iBeiju = -1;
                i = j - 1;
            }
            else if (textoDigitado[i] != ']')
            {
                TLista_Insere_Fim(&lista, textoDigitado[i]);
            }
        }
        TLista_Imprime(&lista);
        TLista_Esvazia(&lista);
        TLista_Inicia(&lista);
    }
    TLista_Esvazia(&lista);
    
    return 0;
}