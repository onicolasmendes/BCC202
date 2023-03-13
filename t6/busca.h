#ifndef busca_h
#define busca_h

typedef int TChave;

typedef struct{
    TChave Chave;
}TRegistro;

typedef struct{
    TRegistro *v;
    int n, max;
}TDicionario;

void TDicionarioInicio(TDicionario *t);

int TDicionarioBinaria(TDicionario *t, int esq, int dir, int x);

void ordena(TDicionario *dic, int inicio, int final);



#endif