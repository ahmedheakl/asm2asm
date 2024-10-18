#include <stdio.h>

int func0(int x, int n) {
    int p = 1, count = 0;
    while (p <= x && count < 100) {
        if (p == x) return 1;
        p = p * n; count += 1;
    }
    return 0;
}
