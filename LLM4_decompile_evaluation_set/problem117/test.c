#include <stdio.h>
#include <assert.h>
void func0(int *arr, int size);

int issame(int *a, int size_a, int *b, int size_b) {
    if (size_a != size_b) return 0;
    for (int i = 0; i < size_a; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int test1[] = {1, 5, 2, 3, 4};
    int expected1[] = {1, 2, 4, 3, 5};
    func0(test1, 5);
    assert(issame(test1, 5, expected1, 5));

    int test3[] = {1, 0, 2, 3, 4};
    int expected3[] = {0, 1, 2, 4, 3};
    func0(test3, 5);
    assert(issame(test3, 5, expected3, 5));

    int test4[] = {2, 5, 77, 4, 5, 3, 5, 7, 2, 3, 4};
    int expected4[] = {2, 2, 4, 4, 3, 3, 5, 5, 5, 7, 77};
    func0(test4, 11);
    assert(issame(test4, 11, expected4, 11));

    int test5[] = {3, 6, 44, 12, 32, 5};
    int expected5[] = {32, 3, 5, 6, 12, 44};
    func0(test5, 6);
    assert(issame(test5, 6, expected5, 6));

    int test6[] = {2, 4, 8, 16, 32};
    int expected6[] = {2, 4, 8, 16, 32};
    func0(test6, 5);
    assert(issame(test6, 5, expected6, 5));

    printf("All tests passed!\n");
    return 0;
}
