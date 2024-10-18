#include <stdio.h>
#include <stdlib.h>

float* func0(const float* l, int count, int* out_count) {
    float* out = (float*)malloc(count * sizeof(float));
    *out_count = 0;

    for (int i = 0; i < count; i++) {
        if (l[i] > 0) {
            out[(*out_count)++] = l[i];
        }
    }

    return out;
}
