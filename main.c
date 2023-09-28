#include <stdio.h>
#include <stdlib.h>
#include "randArray1.h"
#include "randArray10.h"
#include "randArray100.h"

void main() {
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

    return;
}