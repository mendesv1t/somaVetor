#include "metodos_vetor.c"
int main(void) {

    int N;
    char nomeArquivo[100];
    printf("Entre com a quantidade de floats aleatórios desejados: ");
    scanf("%d", & N);

    printf("Escolha um nome para seu arquivo do vetor: ");
    scanf("%s", &nomeArquivo);

    geraArquivoVetor(N, nomeArquivo);

    printf("Vetor gerado!\nRode o comando 'gcc - o main main.c' em seguida, rode './main nomeArquivo' para executar a soma dos valores\n");
}