#include "randArray1.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// função que cria um vetor de tamanho n com valores aleatórios de 0 a 1
double* randArray1 (int n) {
    srand48(time(NULL));

    double* vetor = (double*)malloc(sizeof(double) * n);

    if (vetor == NULL) {
        printf("nao foi possivel");
        exit(-1);
    }

    for (int i = 0; i < n; i++) {
        vetor[i] = drand48();
    }

    return vetor;
}