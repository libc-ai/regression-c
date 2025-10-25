/* include/optimizers/second_order.h - second-order optimizer helpers */

#ifndef INCLUDE_OPTIMIZERS_SECOND_ORDER_H
#define INCLUDE_OPTIMIZERS_SECOND_ORDER_H

#include "optimizer.h"

int second_order_optimize(const OptimizerConfig *cfg, gradient_fn g, Vector *params, void *user_data);

#endif /* INCLUDE_OPTIMIZERS_SECOND_ORDER_H */
