/* include/analytic/qr.h - QR decomposition API */

#ifndef INCLUDE_ANALYTIC_QR_H
#define INCLUDE_ANALYTIC_QR_H

#include "../types.h"

/* Compute QR decomposition of A: A = Q * R
 * A: input matrix (m x n)
 * Q: output orthogonal matrix (m x m) or (m x k)
 * R: output upper triangular matrix (k x n)
 * Returns 0 on success, non-zero on failure.
 */
int qr_decompose(const Matrix *A, Matrix *Q, Matrix *R);

#endif /* INCLUDE_ANALYTIC_QR_H */
