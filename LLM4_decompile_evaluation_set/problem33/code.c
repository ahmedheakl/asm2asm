// func0.c
#include <math.h>

#define MAX_ITERATIONS 1000
#define EPSILON 1e-6

double func0(const double *xs, int size) {
    double ans = 0.0;
    double value, driv, x_pow;
    int i, iteration = 0;

    if (size == 1) {
        // Handle constant equation
        return (fabs(xs[0]) < EPSILON) ? 0.0 : NAN;
    }

    value = xs[0];
    for (i = 1; i < size; i++) {
        x_pow = 1.0;
        for (int j = 0; j < i; j++) {
            x_pow *= ans;
        }
        value += xs[i] * x_pow;
    }

    while (fabs(value) > EPSILON && iteration < MAX_ITERATIONS) {
        driv = 0.0;
        for (i = 1; i < size; i++) {
            x_pow = 1.0;
            for (int j = 1; j < i; j++) {
                x_pow *= ans;
            }
            driv += i * xs[i] * x_pow;
        }
        
        if (fabs(driv) < EPSILON) {
            // If derivative is too close to zero, we can't continue
            return NAN;
        }
        
        ans = ans - value / driv;

        value = xs[0];
        for (i = 1; i < size; i++) {
            x_pow = 1.0;
            for (int j = 0; j < i; j++) {
                x_pow *= ans;
            }
            value += xs[i] * x_pow;
        }
        
        iteration++;
    }

    return (iteration == MAX_ITERATIONS) ? NAN : ans;
}