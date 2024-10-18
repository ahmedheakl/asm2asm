#include <stdio.h>
#include <assert.h>
#include <math.h>
float func0(float *l, int size);

int main() {
    float list1[] = {1, 2, 3};
    assert(fabs(func0(list1, 3) - 3) < 1e-4);

    float list2[] = {5, 3, -5, 2, -3, 3, 9, 0, 124, 1, -10};
    assert(fabs(func0(list2, 11) - 124) < 1e-4);
}
