#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
void func0(const float *xs, int xs_size, float *out);

bool issame(const float *a, int a_size, const float *b, int b_size) {
    if (a_size != b_size) return false;
    for (int i = 0; i < a_size; i++) {
        if (fabs(a[i] - b[i]) > 1e-4) return false;
    }
    return true;
}

int main() {
    float result[4];

    float case1[] = {3, 1, 2, 4, 5};
    float expected1[] = {1, 4, 12, 20};
    func0(case1, 5, result);
    assert(issame(result, 4, expected1, 4));

    float case2[] = {1, 2, 3};
    float expected2[] = {2, 6};
    func0(case2, 3, result);
    assert(issame(result, 2, expected2, 2));

    float case3[] = {3, 2, 1};
    float expected3[] = {2, 2};
    func0(case3, 3, result);
    assert(issame(result, 2, expected3, 2));

    float case4[] = {3, 2, 1, 0, 4};
    float expected4[] = {2, 2, 0, 16};
    func0(case4, 5, result);
    assert(issame(result, 4, expected4, 4));

    float case5[] = {1};
    func0(case5, 1, result);
    assert(issame(result, 0, NULL, 0));

    return 0;
}
