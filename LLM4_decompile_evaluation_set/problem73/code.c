#include <stdio.h>
#include <stdbool.h>

bool func0(int q[], int size, int w) {
    int sum = 0;
    for (int i = 0; i < size / 2; i++) {
        if (q[i] != q[size - 1 - i]) return false;
        sum += q[i] + q[size - 1 - i];
    }
    if (size % 2 == 1) sum += q[size / 2];
    return sum <= w;
}
