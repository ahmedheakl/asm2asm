#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void func0(float *l, int size, float *out) {
    float *even = malloc((size / 2 + 1) * sizeof(float));
    int i, j, even_count = 0;

    for (i = 0; i < size; i += 2) {
        even[even_count++] = l[i];
    }

    for (i = 0; i < even_count - 1; i++) {
        for (j = 0; j < even_count - i - 1; j++) {
            if (even[j] > even[j + 1]) {
                float temp = even[j];
                even[j] = even[j + 1];
                even[j + 1] = temp;
            }
        }
    }

    // Merging even-indexed sorted and odd-indexed as they are
    for (i = 0; i < size; i++) {
        if (i % 2 == 0) {
            out[i] = even[i / 2];
        } else {
            out[i] = l[i];
        }
    }

    free(even);
}
