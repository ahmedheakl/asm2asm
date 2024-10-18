#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int* func0(int n);

int issame(int* a, int a_size, int* b, int b_size) {
    if (a_size != b_size) return 0;
    for (int i = 0; i < a_size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int *result;
    int expected1[] = {1, 2, 6, 24, 15};
    result = func0(5);
    assert(issame(result, 5, expected1, 5));
    free(result);

    int expected2[] = {1, 2, 6, 24, 15, 720, 28};
    result = func0(7);
    assert(issame(result, 7, expected2, 7));
    free(result);

    int expected3[] = {1};
    result = func0(1);
    assert(issame(result, 1, expected3, 1));
    free(result);

    int expected4[] = {1, 2, 6};
    result = func0(3);
    assert(issame(result, 3, expected4, 3));
    free(result);

    return 0;
}
