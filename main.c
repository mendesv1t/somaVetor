#include "threads.c"
#define TESTE

int main(int argc, char *argv[]) {

    FILE *file;
    char line[N];

    // lendo arquivo passado como parâmetro:
     file = fopen(argv[1], "r");

    while (fgets(line,N+1,file) != NULL) {
        puts(line);
    }


    lerArquivoVetor(file, line);

    printf("Estou aqui: %.2f\n", vetor[0]);

    //printf("Entre com o número de threads desejado: ");
   // scanf("%d", & M);

    //criarThreads();

#ifdef TESTE
    somaEsperada = vetor[N];
    printf("Soma esperada: %.2f\n", somaEsperada);
#endif

   if (testaVetor()) printf("Ocorreu um erro: Há um de fluxo de execução não efetuando o cálculo correto.\n");
   else printf("Soma gerada: %.2f\n", somaThreads);
   pclose(file);
   free(vetor);

   return 0;

}