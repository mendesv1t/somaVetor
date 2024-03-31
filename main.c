#include "threads.c"
#define TESTE
#define MAX_LINES 10000 // Número máximo de linhas
#define MAX_LINE_LENGTH 100 // Tamanho máximo da linha

int main(int argc, char *argv[]) {

    FILE *file;
    char lines[MAX_LINES][MAX_LINE_LENGTH]; // array de strings para armazenar as linhas
    int num_lines = 0; // Número de linhas lidas

    // lendo arquivo passado como parâmetro:
     file = fopen(argv[1], "r");

    while (fgets(lines[num_lines], 100, file) != NULL) {
        num_lines++;
        if (num_lines >= MAX_LINES) {
            break;
        }
    }

    fclose(file);

    // na penultima e ultima linha do arquivo armazenei o tamanho do vetor e a soma esperada:
    somaEsperada = atof(lines[num_lines - 1]);
    int N = (int)num_lines-2;

    vetor = malloc((N) * sizeof(float));
    for (int i = 0; i < N; i++) {
        float valor = atof(lines[i]);
        vetor[i] = valor;
     }


    int M;
    printf("Entre com o número de threads desejado: ");
    scanf("%d", & M);

    criarThreads(M,N);

#ifdef TESTE
    printf("Soma esperada: %.2f\n", somaEsperada);
    if (testaVetor()) printf("Ocorreu um erro: Algum fluxo de execução não está efetuando o cálculo correto.\n");
    printf("Soma gerada: %.2f\n", somaThreads);
#endif





   free(vetor);

   return 0;

}