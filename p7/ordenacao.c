#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Manter como especificado
void ordena(Aluno *alunos, int n) {
	int h, j;
    char aux[21];

    //Definição do H
    for(h =1; h < n;)
    {
        h = 3*h +1;
    }

    do
    {
      //Atualiza H
      h = (h - 1)/ 3;

      //Ordenação
      for (int i = h; i < n; i++)
      {
        strcpy(aux, alunos[i].nome);
        j = i;
        while(compare(alunos[j-h].nome, aux) == 1)
        {
            strcpy(alunos[j].nome, alunos[j-h].nome);
            j = j - h;
            if(j < h)
            {
                break;   
            }
        }
        strcpy(alunos[j].nome, aux);
      }
        
    } while (h != 1);
    
}

// Manter como especificado
int compare(const char* aluno1, const char* aluno2) {
    int aux = strcmp(aluno1, aluno2);
    if(aux == 0)
    {
        return 0;
    }else if (aux < 0)
    {
        return -1;
    }else
    {
        return 1;
    }
}

/* Manter como especificado */
void imprimeResposta(Aluno* alunos, int n, int k) {
    printf("%s\n", alunos[k-1].nome);
}

/* Manter como especificado */
Aluno* alocaAlunos(int n) {
    Aluno *alunos = (Aluno*) malloc (n * sizeof(Aluno));
    return alunos;
}

/* Manter como especificado */
void liberaAlunos(Aluno** alunos) {
    free(*alunos);
}

/* Manter como especificado */
void leAlunos(Aluno* alunos, int n) {
    for(int i = 0; i < n; i++)
    {
        scanf("%s", alunos[i].nome);
    }
}

/* Manter como especificado */
void leQuantidades(int* n, int* k) {
    scanf("%d %d", n, k);
}

