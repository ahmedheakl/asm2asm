#include <stdio.h>

int func0(int n, int p) {
    int out = 1;
    for (int i = 0; i < n; i++)
        out = (out * 2) % p;
    return out;
}
