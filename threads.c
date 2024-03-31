#include<stdlib.h>
#include<pthread.h>
#include "metodos_vetor.c"

void * somaLote(void * arg) {
    tArgs args = *(tArgs *) arg;
    args.somaLote = 0;

    int lote = N / (M * (N / M));

    int inicio = 0;
    if (args.id > 1) {
        inicio = (args.id - 1) * (N / M) * lote;
    }

    int fim = args.id * (N / M) * lote;

    // para garantir casos ímpares chegarem ao fim do vetor:
    if (args.id == M) {
        fim = N;
    }

    for (long int i = inicio; i < fim; i++) {
        args.somaLote += vetor[i];
    }


    //retorna o resultado da soma local, com o id da thread que calculou
    pthread_exit((void *) &args);
}

void criarThreads() {

    // recuperando o id das threads no sistema:
    pthread_t tid_sistema[M];
    int threads[M];

    // criando M threads:
    for (int i = 1; i <= M; i++) {
        threads[i] = i;
        if (pthread_create(&tid_sistema[i], NULL, somaLote, (void *)&threads[i])) {
            printf("--ERRO: pthread_create()\n");
            exit(-1);
        }
    }

    // pthread_join aguarda o término das threads:
    for (int i = 0; i < M; i++) {
        pthread_join(tid_sistema[i], NULL);
    }

}