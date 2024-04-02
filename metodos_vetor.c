#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "global.c"

double randFloat(double min, double max) {
    double range = max - min;
    double scaled = (double)rand() / RAND_MAX;
    double shifted = scaled * range;
    return shifted + min;
}

void geraArquivoVetor(int N, char nome[100]) {

    srand(time(NULL));

    double min = -1000.0;
    double max = 1000.0;

    // Initializing file pointer.
    FILE *p_file;
    unsigned i;

    if(nome == NULL) {
        printf("Erro: Atribua um nome para o arquivo\n");
    }

    p_file = fopen(nome, "w");
    if (p_file == NULL) {
        printf("Erro ao criar o arquivo!");
    }

    double soma = 0;
    for (i = 1; i <= N; i++) {
        double random_num = randFloat(min, max);
        fprintf(p_file, "%f\n", random_num);
        soma += random_num;
    }

    // adicionando o tamanho na penultima posição:
    fprintf(p_file, "%f\n", (double) N);

    // adicionando a soma esperada no fim do arquivo:
    fprintf(p_file, "%f", soma);

    // Close opened file.
    fclose(p_file);

}

int testaVetor() {
    if ((somaThreads - somaEsperada) > 0.001000) {
        return 1;
    }
    return 0;
}
