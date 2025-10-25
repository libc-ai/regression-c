/* include/models/elastic_net.h - public API */

#ifndef INCLUDE_MODELS_ELASTIC_NET_H
#define INCLUDE_MODELS_ELASTIC_NET_H

#include "../types.h"
#include "../optimizers/optimizer.h"

int elastic_net_fit(const Matrix *X, const Vector *y, Vector *params, void *opts);

#endif /* INCLUDE_MODELS_ELASTIC_NET_H */
