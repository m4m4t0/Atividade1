#include "randArray10.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// função que cria um vetor de tamanho n com valores aleatórios de 0 a 10
double* randArray10 (int n) {
    srand48(time(NULL));

    double min = 0.0;
    double max = 10.0; 

    double* vetor = (double*)malloc(sizeof(double) * n);

    if (vetor == NULL) {
        printf("nao foi possivel");
        exit(-1);
    }

    for (int i = 0; i < n; i++) {
        vetor[i] = min + drand48() * (max-min);
    }

    return vetor;
}