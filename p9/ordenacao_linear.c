#include "ordenacao_linear.h"

#include <stdlib.h>

#include <stdio.h>

// Manter como especificado
int char2int(char c) {
    /* Funcao auxiliar para converter um char em um inteiro */
    return (int) (c - '0');
}

// Manter como especificado
void le(Paciente* pacientes, int n) {
    // PREENCHER AQUI
    /*
     * pacientes = vetor onde devem ser salvos os valores lidos
     * n = tamanho do vetor A
     */
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s\n", pacientes[i].senha, pacientes[i].nome);
        //printf("%s %s\n", pacientes[i].senha, pacientes[i].nome);
    
    }
    
}

// Manter como especificado
void imprime(Paciente* pacientes, int n){
    // PREENCHER AQUI
    /*
     * pacientes = vetor onde devem ser salvos os valores lidos
     * n = tamanho do vetor A
     */
    for (int i = 0; i < n; i++)
    {
        printf("%s %s\n", pacientes[i].senha, pacientes[i].nome);
    }
    
}

// Manter como especificado
void coutingSort(Paciente* A, Paciente* B, int n, int i) {
    // PREENCHER AQUI
    /*
     * A = vetor a ser ordenado
     * B = vetor auxiliar para armazenar o vetor A ordenado
     * n = tamanho do vetor A
     * i = digito a ser usado na ordenacao
     */
    int *C = malloc(10 * sizeof(int));
    for(int j = 0; j < 10; j++)
    {
        C[j] = 0;
    }

    for(int h = 0; h < n; h++)
    {
        C[char2int(A[h].senha[i])]++;
    }

    for(int l = 1; l < 10; l++)
    {
        C[l] += C[l-1];
    }

    for(int j = n - 1; j >= 0; j--)
    {
        B[C[char2int(A[j].senha[i])]-1] = A[j];
        C[char2int(A[j].senha[i])] = C[char2int(A[j].senha[i])] - 1;    
    }

    for (int j = 0; j < n; j++)
    {
        A[j] = B[j];
    }
    free(C);
    


}

// Manter como especificado
void radixSort(Paciente* pacientes, int n, int m) {
    // Vetor auxiliar a ser usado no couting sort
    Paciente B[MAX_N];
    /*
     * pacientes = vetor a ser ordenado
     * n = tamanho do vetor A
     * m = quantidade de digitos
     */
    for (int i = m - 1; i >= 0; i--)
    {
        coutingSort(pacientes, B, n, i);
    }
    
}

void moveSenha(Paciente *pacientes, int n)
{
    for (int i = n; i < 0; i--)
    {
        pacientes[i] = pacientes[i-1];   
    }
    
}
