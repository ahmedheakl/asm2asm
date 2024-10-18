#include <stdio.h>

int func0(int n) {
    int f[1000] = {0};
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    return f[n];
}
