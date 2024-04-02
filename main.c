#include "threads.c"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define TESTE

int main(int argc, char *argv[]) {

    FILE *file;
    char **lines = NULL;
    int num_lines = 0; // Número de linhas lidas

    // lendo arquivo passado como parâmetro:
     file = fopen(argv[1], "r");
     char line[100];
    while (fgets(line, sizeof (line), file) != NULL) {
        num_lines++;
        lines = realloc(lines, num_lines * sizeof(char*));
        lines[num_lines - 1] = strdup(line); // Copia a linha para o array de strings
    }

    fclose(file);
    // na penultima e ultima linha do arquivo armazenei o tamanho do vetor e a soma esperada:
    somaEsperada = atof(lines[num_lines - 1]);
    int N = (int)num_lines-2;

    vetor = malloc((N) * sizeof(double ));
    for (int i = 0; i < N; i++) {
        double valor = atof(lines[i]);
        vetor[i] = valor;
     }


    int M;
    printf("Entre com o número de threads desejado: ");
    scanf("%d", & M);

    criarThreads(M,N);


    printf("Soma gerada: %f\n", somaThreads);
    free(vetor);

    if (testaVetor()) printf("Ocorreu um erro: Algum fluxo de execução não está efetuando o cálculo correto.\n");

#ifdef TESTE
    printf("Soma esperada: %f\n", somaEsperada);
    printf("Diferença: %f\n", somaThreads - somaEsperada);
#endif

   return 0;

}