#include "metodos_vetor.c"
int main(void) {

    printf("Entre com a quantidade de floats aleatórios desejados: ");
    scanf("%d", & N);

    geraArquivoVetor();

    printf("Vetor gerado!\nRode o comando 'gcc - o main main.c > vetor.txt ' para executar a soma dos valores\n");
}