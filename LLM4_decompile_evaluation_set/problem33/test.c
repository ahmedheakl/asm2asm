#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
double func0(const double *xs, int size);

double evaluate_polynomial(const double *coeffs, int size, double x) {
    double result = 0.0;
    double term = 1.0; 
    for (int i = 0; i < size; i++) {
        if (i > 0) {
            term *= x; 
        }
        result += coeffs[i] * term;
    }
    return result;
}

int main() {
    double solution;
    int ncoeff;
    
    for (int i = 0; i < 100; i++) {
        ncoeff = 2 * (1 + rand() % 4);
        double coeffs[ncoeff];
        for (int j = 0; j < ncoeff; j++) {
            double coeff = -10 + rand() % 21;
            if (coeff == 0) coeff = 1;
            coeffs[j] = coeff;
        }
        
        solution = func0(coeffs, ncoeff);

        assert(fabs(evaluate_polynomial(coeffs, ncoeff, solution)) < 1e-3);
    }

    return 0;
}
