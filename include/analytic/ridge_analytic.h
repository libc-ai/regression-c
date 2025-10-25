/* include/analytic/ridge_analytic.h - public API for ridge analytic solver */

#ifndef INCLUDE_ANALYTIC_RIDGE_ANALYTIC_H
#define INCLUDE_ANALYTIC_RIDGE_ANALYTIC_H

#include "../types.h"

int ridge_analytic_solve(const Matrix *X, const Vector *y, double lambda, Vector *out_params);

#endif /* INCLUDE_ANALYTIC_RIDGE_ANALYTIC_H */
