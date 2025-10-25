/* include/optimizers/first_order.h - first-order optimizer helpers */

#ifndef INCLUDE_OPTIMIZERS_FIRST_ORDER_H
#define INCLUDE_OPTIMIZERS_FIRST_ORDER_H

#include "optimizer.h"

/* An example first-order entry point that specific algorithms can implement */
int first_order_optimize(const OptimizerConfig *cfg, gradient_fn g, Vector *params, void *user_data);

#endif /* INCLUDE_OPTIMIZERS_FIRST_ORDER_H */
