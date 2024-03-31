#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "global.c"

float recuperarSomaVetor(long int inicio, long int fim) {
    float somaAux = 0;
    for (long int i = inicio; i < fim; i++) {
        somaAux += vetor[i];
    }
    return somaAux;
}


float randFloat(float min, float max) {
    float range = max - min;
    float scaled = (float)rand() / RAND_MAX;
    float shifted = scaled * range;
    return shifted + min;
}

void geraArquivoVetor() {

    srand(time(NULL));

    float min = -1000.0;
    float max = 1000.0;

    // Initializing file pointer.
    FILE * p_file;
    unsigned i;

    p_file = fopen("vetor.txt", "w");
    if (p_file == NULL) {
        printf("Erro ao criar o arquivo!");
    }

    float soma = 0;
    for (i = 0; i < N; i++) {
        float random_num = randFloat(min, max);
        fprintf(p_file, "%.2f\n", random_num);
        soma += random_num;
    }
    // adicionando a soma esperada no fim do arquivo:
    fprintf(p_file, "%f\n", soma);

    // Close opened file.
    fclose(p_file);

}


void lerArquivoVetor(FILE * p_file, char line[]) {

    if (p_file == NULL) {
        printf("Erro ao ler o arquivo!");
        return;
    }

    // Alocando espaço para o vetor de floats
    vetor = malloc((N+1) * sizeof(float));
    if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor!");
        return;
    }

    for(int i = 0; i <= N; i++) {
        fscanf(p_file, "%f\n", &vetor[i]);
    }

}

int testaVetor() {
    if (vetor[N] != somaThreads) {
        return 1;
    }
    return 0;
}
