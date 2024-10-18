#include <stdio.h>
#include <stdlib.h>

int *func0(int n, int *count) {
    int *out = malloc(n * sizeof(int));
    *count = 0;
    int i, j, isp, k;

    for (i = 2; i < n; i++) {
        isp = 1;
        for (j = 0; j < *count; j++) {
            k = out[j];
            if (k * k > i) break;
            if (i % k == 0) {
                isp = 0;
                break;
            }
        }
        if (isp) {
            out[*count] = i;
            (*count)++;
        }
    }
    return out;
}
