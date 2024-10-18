#include <stdio.h>

void func0(int a, int b, int *out, int *size) {
    int m;
    *size = 0;

    if (b < a) {
        m = a;
        a = b;
        b = m;
    }

    for (int i = a; i <= b; i++) {
        if (i < 10 && i % 2 == 0) {
            out[(*size)++] = i;
        }
    }
}