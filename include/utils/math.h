/* include/utils/math.h - math helpers */

#ifndef INCLUDE_UTILS_MATH_H
#define INCLUDE_UTILS_MATH_H

#include <math.h>
#include <stddef.h>

double dot_product(const double *a, const double *b, size_t n);
double l2_norm(const double *a, size_t n);

#endif /* INCLUDE_UTILS_MATH_H */
