/* src/optimizers/FirstOrder/sgd/sgd.c - Stochastic Gradient Descent (placeholder)
 * Follows architecture: optimizers should include optimizer public headers and utils.
 */

#include "optimizers/first_order.h"
#include "optimizers/optimizer.h"
#include "utils/math.h"
#include "utils/matrix.h"
#include "types.h"

int sgd_optimize(const OptimizerConfig *cfg, gradient_fn g, Vector *params, void *user_data) {
    (void)cfg; (void)g; (void)params; (void)user_data;
    return 0;
}
