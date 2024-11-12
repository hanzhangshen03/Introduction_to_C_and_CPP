#ifndef MATRIX_H
#define MATRIX_H 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct matrix matrix_t; 
struct matrix {
  int rows;
  int cols;
  double *elts;
};

matrix_t matrix_create(int rows, int cols);
void matrix_free(matrix_t m);

void matrix_print(matrix_t m);

double matrix_get(matrix_t m, int r, int c);
void matrix_set(matrix_t m, int r, int c, double d);


matrix_t matrix_multiply(matrix_t m1, matrix_t m2);

matrix_t matrix_transpose(matrix_t m);

matrix_t matrix_multiply_transposed(matrix_t m1, matrix_t m2);

matrix_t matrix_multiply_fast(matrix_t m1, matrix_t m2);

#endif 
