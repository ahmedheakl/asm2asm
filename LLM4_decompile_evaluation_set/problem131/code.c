#include <stdio.h>
#include <stdlib.h>

int* func0(int n) {
    int* out = (int*)malloc((n + 1) * sizeof(int));
    out[0] = 1;
    if (n == 0) return out;
    out[1] = 3;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) out[i] = 1 + i / 2;
        else out[i] = out[i - 1] + out[i - 2] + 1 + (i + 1) / 2;
    }
    return out;
}
