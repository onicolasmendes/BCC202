#include "ordenacao.h"
#include <stdio.h>

int main ()
{

	int *vetor;
	int n;
	int movimentos;
	while(scanf("%d", &n), n)
	{
		
		//alocar o vetor
		vetor = alocaVetor(vetor, n);
		//preencher o vetor
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &vetor[i]);
		}
		//ordenar o vetor e determinar o número de movimentos
		ordenacao(vetor, n, &movimentos);
		//imprimir o resultado
		if(movimentos % 2 == 0)
		{
			printf("Carlos\n");
		}else
		{
			printf("Marcelo\n");
		}
		//desalocar o vetor
		vetor = desalocaVetor(vetor);
		movimentos = 0;
	}

	return 0;
}
