#include <stdio.h>
#include <assert.h>
#include <math.h>
float func0(float a, float h);

int main() {
    assert(fabs(func0(5, 3) - 7.5) < 1e-4);
    assert(fabs(func0(2, 2) - 2.0) < 1e-4);
    assert(fabs(func0(10, 8) - 40.0) < 1e-4);

    return 0;
}
