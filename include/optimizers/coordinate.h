/* include/optimizers/coordinate.h - coordinate descent interface */

#ifndef INCLUDE_OPTIMIZERS_COORDINATE_H
#define INCLUDE_OPTIMIZERS_COORDINATE_H

#include "optimizer.h"

int coordinate_descent_optimize(const OptimizerConfig *cfg, gradient_fn g, Vector *params, void *user_data);

#endif /* INCLUDE_OPTIMIZERS_COORDINATE_H */
