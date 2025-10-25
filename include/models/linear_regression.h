/* include/models/linear_regression.h
 * Public API for linear regression model
 */

#ifndef INCLUDE_MODELS_LINEAR_REGRESSION_H
#define INCLUDE_MODELS_LINEAR_REGRESSION_H

#include "../types.h"
#include "../optimizers/optimizer.h"

/* Fit linear regression. X: feature matrix, y: target vector.
 * params: output parameter vector (preallocated).
 * opts: optional optimizer or config pointer (can be NULL).
 * Returns 0 on success.
 */
int linear_regression_fit(const Matrix *X, const Vector *y, Vector *params, void *opts);

int linear_regression_predict(const Matrix *X, const Vector *params, Vector *out);

#endif /* INCLUDE_MODELS_LINEAR_REGRESSION_H */
