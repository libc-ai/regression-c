/* include/types.h - minimal common type definitions */

#ifndef INCLUDE_TYPES_H
#define INCLUDE_TYPES_H

#include <stddef.h>

/* Simple matrix and vector types used across the project.
 * These are intentionally minimal; replace with a richer implementation
 * as needed.
 */
typedef struct {
	double *data;
	size_t rows;
	size_t cols;
} Matrix;

typedef struct {
	double *data;
	size_t len;
} Vector;

#endif /* INCLUDE_TYPES_H */
