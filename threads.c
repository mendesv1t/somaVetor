#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include "metodos_vetor.c"

void * somaLote(void * arg) {

    tArgs * args = (tArgs *) arg;
    double tsoma = 0;

    int M = args->M;
    int N = args->N;
    int id = args->id;


    int lote = N / (M * (N / M));

    int inicio = 0;
    if (id > 1) {
        inicio = (id - 1) * (N / M) * lote;
    }

    int fim = id * (N / M) * lote;

    // para garantir casos ímpares chegarem ao fim do vetor:
    if (id == M) {
        fim = N;
    }

    for (int i = inicio; i < fim; i++) {
        tsoma += vetor[i];
    }


    double * tsomaP = malloc(sizeof (double ));
    * tsomaP = tsoma;

    free(args);
    //retorna o resultado da soma local, com o id da thread que calculou
    pthread_exit(tsomaP);
}

void criarThreads(int M, int N) {

    // recuperando o id das threads no sistema:
    pthread_t tid_sistema[M];
    int threads[M];

    // criando M threads:
    for (int i = 1; i <= M; i++) {

        threads[i] = i;
        tArgs * args = malloc(sizeof (tArgs));
        args->id = i;
        args->M = M;
        args->N = N;

        if (pthread_create(&tid_sistema[i], NULL, somaLote, args)) {
            printf("--ERRO: pthread_create()\n");
            exit(-1);
        }
    }

    for (int i = 1; i <= M; i++) {
        double * somaBlocoP;
        pthread_join(tid_sistema[i], (void *) &somaBlocoP);
        somaThreads += *somaBlocoP;
    }

}
