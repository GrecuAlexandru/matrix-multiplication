#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"


float** simple(float** A, float** B, int N)
{
    float** C = (float**)malloc(N * sizeof(float*));
    for (int i = 0; i < N; i++)
    {
        C[i] = (float*)malloc(N * sizeof(float));
        for (int k = 0; k < N; k++)
        {
            float sum = 0;
            for (int j = 0; j < N; j++)
            {
                sum += A[i][j] * B[j][k];
            }
            C[i][k] = sum;
        }
    }
    return C;
}

int main()
{
    float **A, **B, **C;
    int N;
    generate_matrix(1024);
    read_matrix(&A, &B, &N);
    // printf("N = %d\n", N);
    // print_matrix(A, N);
    // printf("\n");
    // print_matrix(B, N);

    clock_t begin = clock();
    C = simple(A, B, N);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTime spent: %f\n", time_spent);
    // print_matrix(C, N);

    // Free the dynamically allocated memory for matrix C
    free_matrix(&A, N);
    free_matrix(&B, N);
    free_matrix(&C, N);

    return 0;
}
