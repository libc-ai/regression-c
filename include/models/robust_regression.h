/* include/models/robust_regression.h - public API */

#ifndef INCLUDE_MODELS_ROBUST_REGRESSION_H
#define INCLUDE_MODELS_ROBUST_REGRESSION_H

#include "../types.h"
#include "../optimizers/optimizer.h"

int robust_regression_fit(const Matrix *X, const Vector *y, Vector *params, void *opts);

#endif /* INCLUDE_MODELS_ROBUST_REGRESSION_H */
