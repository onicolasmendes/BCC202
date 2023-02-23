# ifndef ordenacao_h
# define ordenacao_h

typedef struct {
    int numTime;
    int pontosFeitos;
    int pontosSofridos;
    float razao;
    int pontos;
    int perdeuUmJogo;
} Time;

// Manter como especificado
void ordenacao(Time *vetor, int n);

// Manter como especificado
Time *alocaVetor(int n);

// Manter como especificado
void desalocaVetor(Time **vetor);

// faz a comparacao utilizada para ordenar os times
int compare(Time t1, Time t2);

void heapBuild(Time *times, int n);

void heapReBuild(Time *times, int esq, int dir);

void copiaTime(Time *t1, Time *t2);

void jogo(Time *times, int t1, int p1, int t2, int p2);

void imprime(Time *times, int n, int instancia);

void calculaRazao(Time *times, int n);
# endif
