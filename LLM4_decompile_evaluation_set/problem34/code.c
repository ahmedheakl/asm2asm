#include <stdio.h>
#include <stdlib.h>

void func0(int *l, int size, int *out) {
    int *third = malloc((size / 3 + 1) * sizeof(int));
    int i, k = 0, third_size = 0;

    for (i = 0; i * 3 < size; i++) {
        third[i] = l[i * 3];
        third_size++;
    }

    for (i = 0; i < third_size - 1; i++) {
        int min_idx = i;
        for (k = i + 1; k < third_size; k++) {
            if (third[k] < third[min_idx])
                min_idx = k;
        }
        if (min_idx != i) {
            int temp = third[i];
            third[i] = third[min_idx];
            third[min_idx] = temp;
        }
    }

    for (i = 0; i < size; i++) {
        if (i % 3 == 0) {
            out[i] = third[i / 3];
        } else {
            out[i] = l[i];
        }
    }

    free(third);
}
