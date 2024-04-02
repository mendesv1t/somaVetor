double *vetor = NULL; //vetor de entrada
double somaThreads;
double somaEsperada;

typedef struct {
    int id; //id da thread
    int M;
    int N;
} tArgs;
