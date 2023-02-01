#include <stdio.h>
#include <string.h>
#include "lista.h"
#define MAXTAM 100000

int main()
{
    // Inicializa a lista

    TLista lista, nova;
    TLista_Inicia(&lista);
    TLista_Inicia(&nova);

    // Leitura
    char textoDigitado[MAXTAM], beiju[MAXTAM], naoEhBeiju[MAXTAM];
    int i;
    char c;
    while(scanf("%c", &c) != EOF)
    {
        textoDigitado[i] = c;
        i++;
    }
    textoDigitado[i] = '\0';
    
    i = 0;
    
   // detectando texto beiju
    int  ehBeiju = 0, iBeiju = 0, iNaoEhBeiju = 0;
    while (textoDigitado[i] != '\0')
    {
        //Verificação se trata-se de um beiju
        if (textoDigitado[i] == '[')
        {
            ehBeiju = 1;
            i++;
            
        }
        else if (textoDigitado[i] == ']')
        {
            ehBeiju = 0;
            i++;
        }

        //Adiciona o beiju a string beiju e os demais caracteres vão para a string naoEhBeiju, com exceção dos '[' e ']'
        if(ehBeiju == 1 && textoDigitado[i] != '[' && textoDigitado[i] != ']')
        {
            beiju[iBeiju] = textoDigitado[i];
            iBeiju++;
        }
        else if(ehBeiju == 0 && textoDigitado[i] != '[' && textoDigitado[i] != ']')
        {
            naoEhBeiju[iNaoEhBeiju] = textoDigitado[i];
            iNaoEhBeiju++;
        }

        //Verificação final
        if(textoDigitado[i] == ']')
        {
            ehBeiju = 0;
        }

        i++;
    }
    //Adicionando \0
    beiju[iBeiju] = '\0';
    naoEhBeiju[iNaoEhBeiju] = '\0';
    printf("%s", textoDigitado);
   /*
    //Concatenando as strings
    strcat(beiju, naoEhBeiju);

    //Adicionando cada elemento da string beiju a lista
    i = 0;
    while(beiju[i] != '\0')
    {
        TLista_Insere_Fim(&lista, beiju[i]);
        i++;
    }

    //imprime a lista
    TLista_Imprime(&lista);
    TLista_Esvazia(&lista);*/

    return 0;
}