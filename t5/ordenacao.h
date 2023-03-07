#ifndef ordenacao_h
#define ordenacao_h

typedef struct
{
    char nome[62];
    char cor[12];
    char tamanaho;
} Pessoa;

void heap_constroi(Pessoa *pessoas, int n);
void heap_refaz(Pessoa *pessoas, int esq, int dir);
void heap_sort(Pessoa *pessoas, int n);
int compara(Pessoa p1, Pessoa p2);

#endif