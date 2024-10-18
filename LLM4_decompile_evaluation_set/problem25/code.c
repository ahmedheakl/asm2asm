#include <stdio.h>

int func0(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return n / i;
    return 1;
}
