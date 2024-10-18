#include <stdio.h>
#include <assert.h>
void func0(int a, int b, int *out, int *size);

int issame(const int *a, int a_size, const int *b, int b_size) {
    if (a_size != b_size) return 0;
    for (int i = 0; i < a_size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int result[10], size;

    int expected1[] = {2, 4, 6, 8};
    func0(2, 10, result, &size);
    assert(issame(result, size, expected1, 4));

    int expected2[] = {2, 4, 6, 8};
    func0(10, 2, result, &size);
    assert(issame(result, size, expected2, 4));

    int expected3[] = {2, 4, 6, 8};
    func0(132, 2, result, &size);
    assert(issame(result, size, expected3, 4));

    int expected4[] = {}; // Empty set
    func0(17, 89, result, &size);
    assert(issame(result, size, expected4, 0));

    printf("All tests passed.\n");

    return 0;
}