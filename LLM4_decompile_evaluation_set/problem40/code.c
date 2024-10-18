#include <stdio.h>

int func0(int n) {
    int f1 = 1, f2 = 2, m;
    int count = 0;
    while (count < n) {
        f1 = f1 + f2;
        m = f1; f1 = f2; f2 = m;
        int isprime = 1;
        for (int w = 2; w * w <= f1; w++) {
            if (f1 % w == 0) {
                isprime = 0; break;
            }
        }
        if (isprime) count += 1;
        if (count == n) return f1;
    }
    return 0;
}
