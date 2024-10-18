#include <stdio.h>
#include <stdlib.h>

int* func0(int n) {
    int* out = (int*)malloc(n * sizeof(int));
    int sum = 0, prod = 1;
    for (int i = 1; i <= n; i++) {
        sum += i;
        prod *= i;
        if (i % 2 == 0) out[i - 1] = prod;
        else out[i - 1] = sum;
    }
    return out;
}
