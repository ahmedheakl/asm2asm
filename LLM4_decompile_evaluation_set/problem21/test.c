#include <assert.h>
#include <math.h>
void func0(float numbers[], int size, float out[2]);

int issame(float a[], float b[], int size) {
    const float EPSILON = 1e-4;
    for (int i = 0; i < size; i++) {
        if (fabs(a[i] - b[i]) > EPSILON) return 0;
    }
    return 1;
}

int main() {
    float result[2];

    float test1[] = {1.0, 2.0, 3.9, 4.0, 5.0, 2.2};
    float expected1[] = {3.9, 4.0};
    func0(test1, 6, result);
    assert(issame(result, expected1, 2));

    float test2[] = {1.0, 2.0, 5.9, 4.0, 5.0};
    float expected2[] = {5.0, 5.9};
    func0(test2, 5, result);
    assert(issame(result, expected2, 2));

    float test3[] = {1.0, 2.0, 3.0, 4.0, 5.0, 2.2};
    float expected3[] = {2.0, 2.2};
    func0(test3, 6, result);
    assert(issame(result, expected3, 2));

    float test4[] = {1.0, 2.0, 3.0, 4.0, 5.0, 2.0};
    float expected4[] = {2.0, 2.0};
    func0(test4, 6, result);
    assert(issame(result, expected4, 2));

    float test5[] = {1.1, 2.2, 3.1, 4.1, 5.1};
    float expected5[] = {2.2, 3.1};
    func0(test5, 5, result);
    assert(issame(result, expected5, 2));

    return 0;
}
