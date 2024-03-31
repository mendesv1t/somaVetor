float *vetor = NULL; //vetor de entrada
float somaThreads;
float somaEsperada;

typedef struct {
    int id; //id da thread
    float somaBloco;
    int M;
    int N;
} tArgs;
