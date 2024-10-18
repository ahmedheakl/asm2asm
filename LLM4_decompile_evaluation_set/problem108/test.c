#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int* func0(int n);

int issame(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int* result;

    result = func0(123);
    int expected1[] = {8, 13};
    assert(issame(result, expected1, 2));
    free(result);

    result = func0(12);
    int expected2[] = {4, 6};
    assert(issame(result, expected2, 2));
    free(result);

    result = func0(3);
    int expected3[] = {1, 2};
    assert(issame(result, expected3, 2));
    free(result);

    result = func0(63);
    int expected4[] = {6, 8};
    assert(issame(result, expected4, 2));
    free(result);

    result = func0(25);
    int expected5[] = {5, 6};
    assert(issame(result, expected5, 2));
    free(result);

    result = func0(19);
    int expected6[] = {4, 6};
    assert(issame(result, expected6, 2));
    free(result);

    result = func0(9);
    int expected7[] = {4, 5};
    assert(issame(result, expected7, 2));
    free(result);

    result = func0(1);
    int expected8[] = {0, 1};
    assert(issame(result, expected8, 2));
    free(result);

    return 0;
}
