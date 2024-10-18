#include <stdio.h>

int func0(int n) {
    int ff[100] = {0};
    ff[1] = 0;
    ff[2] = 1;
    for (int i = 3; i <= n; ++i) {
        ff[i] = ff[i - 1] + ff[i - 2] + ff[i - 3];
    }
    return ff[n];
}
