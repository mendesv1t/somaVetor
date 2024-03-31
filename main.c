#include "threads.c"
//#define TESTE

int main(void) {

    //printf("Entre com o número de threads desejado: ");
    //scanf("%d", & M);

    //criarThreads();

    lerArquivoVetor();
    for (int i = 0; i < N; i++) {
        printf("%.3f", vet[i]);
    }

#ifdef TESTE
    somaEsperada = vetor[N];
    printf("Soma esperada: %.2f\n", somaEsperada);
#endif

   // if(testaVetor()) printf("Ocorreu um erro: Há um de fluxo de execução calculando incorretamente a soma.\n");
   // else printf("Soma gerada: %.2f\n", somaThreads);
    free(vetor);
    free(vet);

    return 0;

}