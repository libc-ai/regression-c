/* include/metrics/metrics.h - public metrics interfaces */

#ifndef INCLUDE_METRICS_METRICS_H
#define INCLUDE_METRICS_METRICS_H

#include "../types.h"

double r2_score(const Vector *y_true, const Vector *y_pred);
double accuracy_score(const Vector *y_true, const Vector *y_pred);
double mape_score(const Vector *y_true, const Vector *y_pred);

#endif /* INCLUDE_METRICS_METRICS_H */
