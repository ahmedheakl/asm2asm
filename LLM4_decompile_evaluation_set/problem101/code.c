#include <stdio.h>
#include <stdlib.h>

int* func0(int n) {
    int* out = (int*)malloc(n * sizeof(int));
    *out = n;
    for (int i = 1; i < n; i++)
        *(out + i) = *(out + i - 1) + 2;
    return out;
}
