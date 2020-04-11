

#include <stdio.h>

double inner_product(double *a, double *b, unsigned int n) {
    double result = 0.;
    unsigned int k;

    for(k = 0; k < n; k++) {
        result += a[k] * b[k];
    }

    return result;
}

void square_matrix_vector_mult(double *A, double *x, double *result, unsigned int n) {
    unsigned int row;

    for(row = 0; row < n; row++) {
        result[row] = inner_product(&A[row*n], x, n);
    }
}

