/* src/models/linear_regression/linear_regression.c
 * Linear regression implementation (placeholder)
 */

#include <stdio.h>
#include "models/linear_regression.h"
#include "optimizers/optimizer.h"
#include "utils/matrix.h"
#include "loss/loss.h"
#include "types.h"

int linear_regression_fit(const Matrix *X, const Vector *y, Vector *params, void *opts) {
    /* TODO: implement fit using run_optimizer and gradient callback */
    (void)X; (void)y; (void)params; (void)opts;
    return 0;
}
