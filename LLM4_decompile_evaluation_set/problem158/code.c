#include <stdio.h>
#include <math.h>

int func0(float a, float b, float c) {
    if (fabs(a*a + b*b - c*c) < 1e-4 || fabs(a*a + c*c - b*b) < 1e-4 || fabs(b*b + c*c - a*a) < 1e-4) return 1;
    return 0;
}
