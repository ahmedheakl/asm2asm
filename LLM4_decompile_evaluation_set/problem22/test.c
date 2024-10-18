#include <assert.h>
void func0(float *numbers, int size);

int issame(float *a, float *b, int size) {
    const float EPSILON = 1e-4;
    for (int i = 0; i < size; i++) {
        if (fabs(a[i] - b[i]) > EPSILON) return 0;
    }
    return 1;
}

int main() {
    float test1[] = {2.0, 49.9};
    float expected1[] = {0.0, 1.0};
    func0(test1, 2);
    assert(issame(test1, expected1, 2));

    float test2[] = {100.0, 49.9};
    float expected2[] = {1.0, 0.0};
    func0(test2, 2);
    assert(issame(test2, expected2, 2));

    float test3[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float expected3[] = {0.0, 0.25, 0.5, 0.75, 1.0};
    func0(test3, 5);
    assert(issame(test3, expected3, 5));

    float test4[] = {2.0, 1.0, 5.0, 3.0, 4.0};
    float expected4[] = {0.25, 0.0, 1.0, 0.5, 0.75};
    func0(test4, 5);
    assert(issame(test4, expected4, 5));

    float test5[] = {12.0, 11.0, 15.0, 13.0, 14.0};
    float expected5[] = {0.25, 0.0, 1.0, 0.5, 0.75};
    func0(test5, 5);
    assert(issame(test5, expected5, 5));

    return 0;
}
