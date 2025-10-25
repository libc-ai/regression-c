/* include/models/svr.h - public API */

#ifndef INCLUDE_MODELS_SVR_H
#define INCLUDE_MODELS_SVR_H

#include "../types.h"
#include "../optimizers/optimizer.h"

int svr_fit(const Matrix *X, const Vector *y, Vector *params, void *opts);

#endif /* INCLUDE_MODELS_SVR_H */
