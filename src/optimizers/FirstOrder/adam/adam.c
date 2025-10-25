/* src/optimizers/FirstOrder/adam/adam.c - placeholder */

#include "optimizers/first_order.h"
#include "optimizers/optimizer.h"
#include "utils/math.h"
#include "utils/matrix.h"
#include "types.h"

int adam_optimize(const OptimizerConfig *cfg, gradient_fn g, Vector *params, void *user_data) {
    (void)cfg; (void)g; (void)params; (void)user_data;
    return 0;
}
