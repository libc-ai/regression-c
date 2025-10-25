/* include/optimizers/optimizer.h - generic optimizer interfaces */

#ifndef INCLUDE_OPTIMIZERS_OPTIMIZER_H
#define INCLUDE_OPTIMIZERS_OPTIMIZER_H

#include "../types.h"

/* Simple optimizer configuration */
typedef struct {
	double learning_rate;
	int max_iters;
} OptimizerConfig;

/* Gradient callback signature: given params, fill grad. Return 0 on success. */
typedef int (*gradient_fn)(const Vector *params, Vector *grad, void *user_data);

/* Generic optimizer runner used by models: returns 0 on success. */
int run_optimizer(const OptimizerConfig *cfg, gradient_fn g, Vector *params, void *user_data);

#endif /* INCLUDE_OPTIMIZERS_OPTIMIZER_H */
