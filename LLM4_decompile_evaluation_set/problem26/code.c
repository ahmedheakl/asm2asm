#include <stdio.h>
#include <stdlib.h>

int* func0(int n, int* size) {
    int* out = malloc(sizeof(int) * 64);
    *size = 0;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            n = n / i;
            out[(*size)++] = i;
        }
    }
    if (n > 1) {
        out[(*size)++] = n;
    }
    return out;
}
