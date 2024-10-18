#include <stdio.h>

int func0(int n) {
    for (int i = 2; i * i <= n; i++)
        while (n % i == 0 && n > i) n = n / i;
    return n;
}
