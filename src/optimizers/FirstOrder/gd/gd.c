/* src/optimizers/FirstOrder/gd/gd.c - Gradient Descent (placeholder) */

#include "optimizers/first_order.h"
#include "optimizers/optimizer.h"
#include "utils/math.h"
#include "types.h"
#include "utils/matrix.h"



int gd_optimize(const OptimizerConfig *cfg, gradient_fn g, Vector *params, void *user_data) {
    (void)cfg; (void)g; (void)params; (void)user_data;
    return 0;
}
