#include "threads.c"
//#define TESTE

int main(void) {

    lerArquivoVetor();

    printf("Entre com o número de threads desejado: ");
    scanf("%d", & M);

    for (int i = 0; i < N + 1; i++) {
        printf("%.2f", vetor[i]);
    }
    criarThreads();

#ifdef TESTE
    somaEsperada = vetor[N];
    printf("Soma esperada: %.2f\n", somaEsperada);
#endif

   if (testaVetor()) printf("Ocorreu um erro: Há um de fluxo de execução calculando incorretamente a soma.\n");
   else printf("Soma gerada: %.2f\n", somaThreads);
   free(vetor);

   return 0;

}