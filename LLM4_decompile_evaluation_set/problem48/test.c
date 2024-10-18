#include <stdio.h>
#include <assert.h>
#include <math.h>
float func0(float *l, int size);

int main() {
    float list1[] = {3, 1, 2, 4, 5};
    assert(fabs(func0(list1, 5) - 3) < 1e-4);

    float list2[] = {-10, 4, 6, 1000, 10, 20};
    assert(fabs(func0(list2, 6) - 8.0) < 1e-4);

    float list3[] = {5};
    assert(fabs(func0(list3, 1) - 5) < 1e-4);

    float list4[] = {6, 5};
    assert(fabs(func0(list4, 2) - 5.5) < 1e-4);

    float list5[] = {8, 1, 3, 9, 9, 2, 7};
    assert(fabs(func0(list5, 7) - 7) < 1e-4);

    return 0;
}
