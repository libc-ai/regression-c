/* include/loss/loss.h - public loss function interfaces */

#ifndef INCLUDE_LOSS_LOSS_H
#define INCLUDE_LOSS_LOSS_H

#include "../types.h"

double mse_loss(const Vector *y_true, const Vector *y_pred);
double mae_loss(const Vector *y_true, const Vector *y_pred);
double huber_loss(const Vector *y_true, const Vector *y_pred, double delta);

#endif /* INCLUDE_LOSS_LOSS_H */
