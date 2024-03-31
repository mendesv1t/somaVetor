float *vetor = NULL; //vetor de entrada
int N;
int M;
float somaThreads;
float somaEsperada;

typedef struct {
    int id; //id da thread
    long int tamLote; //tamanho do bloco (cada thread processa um bloco)
    float somaLote;
} tArgs;
