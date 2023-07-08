#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

void read_matrix(float ***A, float ***B, int *N)
{
    FILE *input_file = fopen("matrix.txt", "r");

    fscanf(input_file, "%d\n", N);

    *A = (float **)malloc(*N * sizeof(float *));
    for (int i = 0; i < *N; i++)
    {
        (*A)[i] = (float *)malloc(*N * sizeof(float));
    }

    *B = (float **)malloc(*N * sizeof(float *));
    for (int i = 0; i < *N; i++)
    {
        (*B)[i] = (float *)malloc(*N * sizeof(float));
    }

    for (int i = 0; i < *N; i++)
    {
        for (int j = 0; j < *N; j++)
        {
            fscanf(input_file, "%f ", &(*A)[i][j]);
        }
    }

    for (int i = 0; i < *N; i++)
    {
        for (int j = 0; j < *N; j++)
        {
            fscanf(input_file, "%f ", &(*B)[i][j]);
        }
    }

    fclose(input_file);
}

void print_matrix(float **M, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) 
        {
            printf("%f ", M[i][j]);
        }
        printf("\n");
    }
}

void free_matrix(float ***M, int N)
{
    for (int i = 0; i < N; i++)
    {
        free((*M)[i]);
    }
    free(*M);
}

float randomFloat(float min, float max)
{
    float scale = rand() / (float)RAND_MAX; // Generate a random value between 0 and 1
    return min + scale * (max - min); // Scale the value to the desired range
}

void generate_matrix(int N)
{
    srand(time(NULL));   

    float **M = (float **)malloc(N * sizeof(float *));
    for (int i = 0; i < N; i++)
    {
        M[i] = (float *)malloc(N * sizeof(float));
        for (int j = 0; j < N; j++)
        {
            M[i][j] = randomFloat(0, 100);
        }
    }

    FILE *output_file = fopen("matrix.txt", "w");
    fprintf(output_file, "%d\n", N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++) 
        {
            fprintf(output_file, "%f ", M[i][j]);
        }
        fprintf(output_file, "%f", M[i][N - 1]);
        fprintf(output_file, "\n");
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++) 
        {
            M[i][j] = randomFloat(0, 100);
        }
    }
    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++) 
        {
            fprintf(output_file, "%f ", M[i][j]);
        }
        fprintf(output_file, "%f", M[i][N - 1]);
        if(i != N - 1)
            fprintf(output_file, "\n");
    }

    fclose(output_file);
}