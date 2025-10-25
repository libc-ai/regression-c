/* include/analytic/svd.h - SVD decomposition API */

#ifndef INCLUDE_ANALYTIC_SVD_H
#define INCLUDE_ANALYTIC_SVD_H

#include "../types.h"

/* Compute SVD of A: A = U * diag(S) * Vt
 * A: input matrix (m x n)
 * U: output left singular vectors (m x m) or (m x k)
 * S: output singular values (length k)
 * Vt: output right singular vectors transposed (k x n)
 * k is typically min(m,n). Returns 0 on success.
 */
int svd_decompose(const Matrix *A, Matrix *U, Vector *S, Matrix *Vt);

#endif /* INCLUDE_ANALYTIC_SVD_H */
