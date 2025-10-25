/* include/analytic/normal_equation.h - public API for analytic solvers */

#ifndef INCLUDE_ANALYTIC_NORMAL_EQUATION_H
#define INCLUDE_ANALYTIC_NORMAL_EQUATION_H

#include "../types.h"

int normal_equation_solve(const Matrix *X, const Vector *y, Vector *out_params);

#endif /* INCLUDE_ANALYTIC_NORMAL_EQUATION_H */
