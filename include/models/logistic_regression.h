/* include/models/logistic_regression.h - public API */

#ifndef INCLUDE_MODELS_LOGISTIC_REGRESSION_H
#define INCLUDE_MODELS_LOGISTIC_REGRESSION_H

#include "../types.h"
#include "../optimizers/optimizer.h"

int logistic_regression_fit(const Matrix *X, const Vector *y, Vector *params, void *opts);
int logistic_regression_predict_prob(const Matrix *X, const Vector *params, Vector *out);

#endif /* INCLUDE_MODELS_LOGISTIC_REGRESSION_H */
