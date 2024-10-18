#include <stdio.h>
#include <math.h>

int func0(float a, float b, float c) {
    if (roundf(a) != a) return 0;
    if (roundf(b) != b) return 0;
    if (roundf(c) != c) return 0;
    if ((a + b == c) || (a + c == b) || (b + c == a)) return 1;
    return 0;
}
