.
├── include/
│   ├── models/
│   │   ├── linear_regression.h
│   │   ├── logistic_regression.h
│   │   ├── poisson_regression.h
│   │   ├── robust_regression.h
│   │   ├── lasso.h
│   │   ├── ridge.h
│   │   ├── elastic_net.h
│   │   └── svr.h
│   │
│   ├── optimizers/
│   │   ├── optimizer.h
│   │   ├── first_order.h
│   │   ├── second_order.h
│   │   └── coordinate.h
│   │
│   ├── analytic/
│   │   ├── normal_equation.h
│   │   └── ridge_analytic.h
│   │
│   ├── loss/
│   │   └── loss.h
│   │
│   ├── metrics/
│   │   └── metrics.h
│   │
│   ├── utils/
│   │   ├── matrix.h
│   │   ├── math.h
│   │   └── io.h
│   │
│   ├── types.h
│   └── creg.h
│
├── src/
│   ├── models/
│   │   ├── linear_regression/
│   │   │   ├── linear_regression.c
│   │   │   └── README.md
│   │   ├── logistic_regression/
│   │   │   ├── logistic_regression.c
│   │   │   └── README.md
│   │   ├── poisson_regression/
│   │   │   ├── poisson_regression.c
│   │   │   └── README.md
│   │   ├── robust_regression/
│   │   │   ├── robust_regression.c
│   │   │   └── README.md
│   │   ├── lasso/
│   │   │   ├── lasso.c
│   │   │   └── README.md
│   │   ├── ridge/
│   │   │   ├── ridge.c
│   │   │   └── README.md
│   │   ├── elastic_net/
│   │   │   ├── elastic_net.c
│   │   │   └── README.md
│   │   └── svr/
│   │       ├── svr.c
│   │       └── README.md
│   │
│   ├── optimizers/
│   │   ├── FirstOrder/
│   │   │   ├── gd/
│   │   │   │   ├── gd.c
│   │   │   │   └── README.md
│   │   │   ├── sgd/
│   │   │   │   ├── sgd.c
│   │   │   │   └── README.md
│   │   │   ├── minibatch_gd/
│   │   │   │   ├── minibatch_gd.c
│   │   │   │   └── README.md
│   │   │   ├── momentum/
│   │   │   │   ├── momentum.c
│   │   │   │   └── README.md
│   │   │   ├── nesterov_momentum/
│   │   │   │   ├── nesterov_momentum.c
│   │   │   │   └── README.md
│   │   │   ├── adagrad/
│   │   │   │   ├── adagrad.c
│   │   │   │   └── README.md
│   │   │   ├── adadelta/
│   │   │   │   ├── adadelta.c
│   │   │   │   └── README.md
│   │   │   ├── rmsprop/
│   │   │   │   ├── rmsprop.c
│   │   │   │   └── README.md
│   │   │   ├── adam/
│   │   │   │   ├── adam.c
│   │   │   │   └── README.md
│   │   │   ├── adamw/
│   │   │   │   ├── adamw.c
│   │   │   │   └── README.md
│   │   │   ├── adamax/
│   │   │   │   ├── adamax.c
│   │   │   │   └── README.md
│   │   │   └── nadam/
│   │   │       ├── nadam.c
│   │   │       └── README.md
│   │   │
│   │   ├── SecondOrder/
│   │   │   ├── newton_method/
│   │   │   │   ├── newton_method.c
│   │   │   │   └── README.md
│   │   │   └── lbfgs/
│   │   │       ├── lbfgs.c
│   │   │       └── README.md
│   │   │
│   │   └── Coordinate/
│   │       └── coordinate_descent/
│   │           ├── coordinate_descent.c
│   │           └── README.md
│   │
│   ├── analytic/
│   │   ├── normal_equation/
│   │   │   ├── normal_equation.c
│   │   │   └── README.md
│   │   ├── ridge_analytic/
│   │   │   ├── ridge_analytic.c
│   │   │   └── README.md
│   │   ├── qr/
│   │   │   ├── qr.c
│   │   │   └── README.md
│   │   └── svd/
│   │       ├── svd.c
│   │       └── README.md
│   │
│   ├── loss/
│   │   ├── mse/
│   │   │   ├── mse.c
│   │   │   └── README.md
│   │   ├── mae/
│   │   │   ├── mae.c
│   │   │   └── README.md
│   │   ├── logloss/
│   │   │   ├── logloss.c
│   │   │   └── README.md
│   │   ├── huber/
│   │   │   ├── huber.c
│   │   │   └── README.md
│   │   └── loss_gradients/
│   │       ├── loss_gradients.c
│   │       └── README.md
│   │
│   ├── metrics/
│   │   ├── r2/
│   │   │   ├── r2.c
│   │   │   └── README.md
│   │   ├── accuracy/
│   │   │   ├── accuracy.c
│   │   │   └── README.md
│   │   └── mape/
│   │       ├── mape.c
│   │       └── README.md
│   │
│   └── utils/
│       ├── matrix/
│       │   ├── matrix.c
│       │   └── README.md
│       ├── math/
│       │   ├── math.c
│       │   └── README.md
│       └── io/
│           ├── io.c
│           └── README.md
│
examples/
├── Linear_Regression/
│   ├── Analytic/
│   │   ├── normal_equation.c
│   │   ├── qr.c
│   │   └── svd.c
│   │
│   └── Iterative/
│       ├── gd.c
│       ├── sgd.c
│       ├── mini_batch.c
│       ├── momentum.c
│       ├── nesterov_momentum.c
│       ├── adagrad.c
│       ├── adadelta.c
│       ├── rmsprop.c
│       ├── adam.c
│       ├── adamw.c
│       ├── adamax.c
│       ├── nadam.c
│       ├── newton.c
│       ├── quasi_newton.c       // (LBFGS kullanarak)
│       └── coordinate_descent.c
│
├── Logistic_Regression/
│   └── Iterative/
│       ├── gd.c
│       ├── sgd.c
│       ├── mini_batch.c
│       ├── momentum.c
│       ├── nesterov_momentum.c
│       ├── adagrad.c
│       ├── adadelta.c
│       ├── rmsprop.c
│       ├── adam.c
│       ├── adamw.c
│       ├── adamax.c
│       ├── nadam.c
│       ├── newton.c
│       └── quasi_newton.c       // (LBFGS kullanarak)
│
├── Ridge_Regression/
│   ├── Analytic/
│   │   └── closed_form.c        // (ridge_analytic.c'yi kullanır)
│   │
│   └── Iterative/
│       ├── gd.c
│       ├── sgd.c
│       ├── adam.c
│       └── newton.c
│
├── Lasso_Regression/
│   └── Iterative/
│       └── coordinate_descent.c
│
├── ElasticNet_Regression/
│   └── Iterative/
│       └── coordinate_descent.c
│
├── Poisson_Regression/
│   └── Iterative/
│       ├── gd.c
│       ├── sgd.c
│       ├── adam.c
│       ├── newton.c
│       └── quasi_newton.c
│
├── Robust_Regression/
│   └── Iterative/
│       ├── gd.c
│       ├── sgd.c
│       └── coordinate_descent.c
│
├── SVR/
│   └── Iterative/
│       ├── gd.c
│       ├── sgd.c
│       └── coordinate_descent.c
│
├── .gitignore
├── Makefile
└── README.md