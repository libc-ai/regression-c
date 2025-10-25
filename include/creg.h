/* include/creg.h - central public header
 * This header aggregates the project's public headers so that examples
 * and consumers only need to `#include "creg.h"`.
 */

#ifndef INCLUDE_CREG_H
#define INCLUDE_CREG_H

/* Core types */
#include "types.h"

/* Models */
#include "models/linear_regression.h"
#include "models/logistic_regression.h"
#include "models/poisson_regression.h"
#include "models/robust_regression.h"
#include "models/lasso.h"
#include "models/ridge.h"
#include "models/elastic_net.h"
#include "models/svr.h"

/* Optimizers */
#include "optimizers/optimizer.h"
#include "optimizers/first_order.h"
#include "optimizers/second_order.h"
#include "optimizers/coordinate.h"

/* Analytic solvers */
#include "analytic/normal_equation.h"
#include "analytic/ridge_analytic.h"
#include "analytic/qr.h"
#include "analytic/svd.h"

/* Loss / Metrics / Utils */
#include "loss/loss.h"
#include "metrics/metrics.h"
#include "utils/matrix.h"
#include "utils/math.h"
#include "utils/io.h"

#endif /* INCLUDE_CREG_H */
