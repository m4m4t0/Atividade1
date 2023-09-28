#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

double* randArray100 (int n) {
    srand48(time(NULL));

    double min = 0;
    double max = 100;

    double* vetor = (double*)malloc(sizeof(double) * n);

    if (vetor == NULL) {
        printf("nao foi possivel");
        exit(-1);
    }

    for (int i = 0; i < n; i++) {
        vetor[i] = min + drand48() * (max - min);
    }

    return vetor;
}

int main() {
    int n[3];

    for (int k = 0; k < 3; k++) {
        scanf("%d", &n[k]);
    }

    double* a = randArray1(n[0]);  
    
    double* b = randArray10(n[1]);
    
    double* c = randArray100(n[2]);

    for (int i = 0; i < n[0]; i++) {
        printf("%lf ", a[i]);
    }
    printf("\n");

    for (int i = 0; i < n[1]; i++) {
        printf("%lf ", b[i]);
    }
    printf("\n");

    for (int i = 0; i < n[2]; i++) {
        printf("%lf ", c[i]);
    }
    printf("\n");

    free(a);
    free(b);
    free(c);

    return 0;
}