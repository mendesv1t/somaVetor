#include "threads.c"
#include "stdlib.h"
#include "stdio.h"

#define TESTE
int main(int argc, char *argv[]) {

    FILE *file;
    // lendo arquivo passado como parâmetro:
    file = fopen(argv[1], "r");

    // com o arquivo lido, monta o vetor com base nele e retorna o tamanho do vetor:
    int N = montarVetor(file);
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