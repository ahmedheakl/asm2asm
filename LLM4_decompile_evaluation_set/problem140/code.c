#include <stdio.h>

long long func0(int n) {
    long long fact = 1, bfact = 1;
    for (int i = 1; i <= n; i++) {
        fact = fact * i;
        bfact = bfact * fact;
    }
    return bfact;
}
