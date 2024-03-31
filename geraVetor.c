#include "metodos_vetor.c"
int main(void) {

    int N;
    printf("Entre com a quantidade de floats aleatórios desejados: ");
    scanf("%d", & N);

    geraArquivoVetor(N);

    printf("Vetor gerado!\nRode o comando 'gcc - o main main.c' em seguida, rode './main vetor.txt' para executar a soma dos valores\n");
}