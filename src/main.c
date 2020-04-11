
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "vector.h"

double Rx[9], Ry[9], Rz[9];
extern double points[];
extern unsigned int points_len;

void populateRz(double *R, double theta) {
    R[0] = cos(theta);
    R[1] = 0.;
    R[2] = sin(theta);
    R[3] = 0.;
    R[4] = 1.;
    R[5] = 0.;
    R[6] = -sin(theta);
    R[7] = 0.;
    R[8] = cos(theta);
}

void populateRy(double *R, double theta) {
    R[0] = cos(theta);
    R[1] = -sin(theta);
    R[2] = 0.;
    R[3] = sin(theta);
    R[4] = cos(theta);
    R[5] = 0.;
    R[6] = 0.;
    R[7] = 0.;
    R[8] = 1.;
}

void populateRx(double *R, double theta) {
    R[0] = 1.;
    R[1] = 0.;
    R[2] = 0.;
    R[3] = 0.;
    R[4] = cos(theta);
    R[5] = -sin(theta);
    R[6] = 0.;
    R[7] = sin(theta);
    R[8] = cos(theta);
}


double *output_points;
int main(int argc, char **argv) {
    int k;
    struct timespec tstart={0,0}, tend={0,0};
    
    output_points = malloc(sizeof(double)*points_len); // Get some memory for output_points

    
    // Populate rotation matrices
    populateRx(Rx, 2.0);
    populateRy(Ry, 1.0);
    populateRz(Rz, 0.5);


    clock_gettime(CLOCK_MONOTONIC, &tstart); // Get start time...
    
    // Long computation goes here...

    for(k = 0; k < points_len; k += 3){
        square_matrix_vector_mult(Rx, &(points[k]), &(output_points[k]), 3);
        square_matrix_vector_mult(Ry, &(points[k]), &(output_points[k]), 3);
        square_matrix_vector_mult(Rz, &(points[k]), &(output_points[k]), 3);
    }

    clock_gettime(CLOCK_MONOTONIC, &tend); // Get end time...
    printf("vector rotation on %d points took about %1.5f milliseconds\n",
           points_len,
           ((double)tend.tv_sec*1000 + 1.0e-6*tend.tv_nsec) -
           ((double)tstart.tv_sec*1000 + 1.0e-6*tstart.tv_nsec));

    return 0;
}
