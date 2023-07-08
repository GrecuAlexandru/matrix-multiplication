#ifndef READ_MATRIX_H
#define READ_MATRIX_H

void read_matrix(float ***A, float ***B, int *N);
void print_matrix(float **M, int N);
void free_matrix(float ***M, int N);
void generate_matrix(int N);

#endif  