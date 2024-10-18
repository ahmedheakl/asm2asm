#include <stdio.h>
#include <stdlib.h>

int *func0(int *l1, int size1, int *l2, int size2, int *out_size) {
    int *out = malloc(size1 * sizeof(int));
    int k = 0, i, j, m;

    for (i = 0; i < size1; i++) {
        int exists_in_out = 0;
        for (m = 0; m < k; m++) {
            if (out[m] == l1[i]) {
                exists_in_out = 1;
                break;
            }
        }
        if (!exists_in_out) {
            for (j = 0; j < size2; j++) {
                if (l1[i] == l2[j]) {
                    out[k++] = l1[i];
                    break;
                }
            }
        }
    }

    for (i = 0; i < k - 1; i++) {
        for (j = 0; j < k - i - 1; j++) {
            if (out[j] > out[j + 1]) {
                int temp = out[j];
                out[j] = out[j + 1];
                out[j + 1] = temp;
            }
        }
    }

    *out_size = k;
    return out;
}
