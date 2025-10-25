/* include/utils/io.h - simple IO helpers */

#ifndef INCLUDE_UTILS_IO_H
#define INCLUDE_UTILS_IO_H

#include "../types.h"

int load_csv_matrix(const char *path, Matrix *out);
int save_vector_csv(const char *path, const Vector *v);

#endif /* INCLUDE_UTILS_IO_H */
