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

void geraVetor() {
    vetor = malloc((N + 1)* sizeof(float));
    vet = malloc((N + 1)* sizeof(float));

    int i;

    srand(time(NULL));

    float min = -1000.0;
    float max = 1000.0;

    for (i = 0; i < N; i++) {
        float random_num = randFloat(min, max);
        vetor[i] = random_num;
    }
    // atribuindo o ultimo valor do arquivo para ser a soma esperada
    vetor[N] = recuperarSomaVetor(0,N);
}


void criaArquivoVetor() {
    // Initializing file pointer.
    FILE * p_file;
    unsigned i;

    p_file = fopen("vetor.txt", "w");
    if (p_file == NULL) {
        printf("Erro ao criar o arquivo!");
    }

    for (i = 0; i < N + 1; i++) {
        fprintf(p_file, "%f\n", vetor[i]);
    }

    // Close opened file.
    fclose(p_file);

}

void lerArquivoVetor() {

    // Initializing file pointer.
    FILE * p_file;
    unsigned i;

    p_file = fopen("vetor.txt", "r");
    if (p_file == NULL) {
        printf("Erro ao ler o arquivo!");
    }

    /*Lendo os elementos do vetor:*/
    for(i = 0; i < N; i++)
        fscanf(p_file,"%f\n",&vet[i]);
    fclose(p_file);

}

// criar um método para cálcular o erro de precisão aceito (será o testaVetor)
int testaVetor() {
    return 0;
}
