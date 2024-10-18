#include <stdio.h>
#include <stdlib.h>

void func0(int n, int *out, int *size) {
    int capacity = 10;
    *size = 1;
    out[0] = 1;
    
    while (n != 1) {
        if (n % 2 == 1) {
            if (*size >= capacity) {
                capacity *= 2;
                out = (int*)realloc(out, capacity * sizeof(int));
            }
            out[(*size)++] = n;
            n = n * 3 + 1;
        } else {
            n = n / 2;
        }
    }

    for (int i = 1; i < *size; i++) {
        int key = out[i];
        int j = i - 1;

        while (j >= 0 && out[j] > key) {
            out[j + 1] = out[j];
            j = j - 1;
        }
        out[j + 1] = key;
    }
}
