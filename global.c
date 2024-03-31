float *vetor = NULL; //vetor de entrada
float somaThreads;
float somaEsperada;

typedef struct {
    int id; //id da thread
    int M;
    int N;
} tArgs;
