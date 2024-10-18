#include <stdio.h>
#include <assert.h>
#include <math.h>
float func0(float number);

int main() {
    assert(func0(3.5f) == 0.5f);
    assert(fabs(func0(1.33f) - 0.33f) < 1e-4);
    assert(fabs(func0(123.456f) - 0.456f) < 1e-4);

    return 0;
}
