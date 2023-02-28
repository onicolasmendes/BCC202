#include <stdio.h>
#include "ordenacao.h"

int main(){
    
    int n;
    TADupa *upas;
    scanf("%d", &n);
    alocarUpa(&upas, n);
    preencheVetor(upas, n);
    ordenaUpas(upas, n);
    imprimeUpas(upas, n);
    desalocaUpas(&upas);
    return 0;
}

