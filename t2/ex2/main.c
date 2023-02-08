#include "r9.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    char num[1000];
    int tam, algarismo;
    while ((scanf("%s", num)) != EOF)
    {
        tam = strlen(num);
        if (strcmp(num, "0") == 0)
        {
            return 0;
        }

        int soma = 0;
        for (int i = 0; i < tam; i++)
        {
            algarismo = num[i] - '0';
            soma += algarismo;
        }

        if (soma_r9(soma) == 1)
        {
            printf("%s is a multiple of 9\n", num);
        }
        else
        {
            printf("%s is not a multiple of 9\n", num);
        }
    }

    return 0;
}