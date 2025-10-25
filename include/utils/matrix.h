/* include/utils/matrix.h - minimal matrix utilities API */

#ifndef INCLUDE_UTILS_MATRIX_H
#define INCLUDE_UTILS_MATRIX_H

#include "../types.h"

int matrix_mul(const Matrix *A, const Matrix *B, Matrix *out);
int matrix_vec_mul(const Matrix *A, const Vector *v, Vector *out);

#endif /* INCLUDE_UTILS_MATRIX_H */
