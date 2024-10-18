#include <assert.h>
#include <stdlib.h>
#include <string.h>
int *func0(int *l1, int size1, int *l2, int size2, int *out_size);

int main() {
    int size;

    int l1[] = {1, 4, 3, 34, 653, 2, 5};
    int l2[] = {5, 7, 1, 5, 9, 653, 121};
    int expected1[] = {1, 5, 653};
    int *result1 = func0(l1, 7, l2, 7, &size);
    for (int i = 0; i < size; i++) {
        assert(result1[i] == expected1[i]);
    }
    free(result1);

    int l3[] = {5, 3, 2, 8};
    int l4[] = {3, 2};
    int expected2[] = {2, 3};
    int *result2 = func0(l3, 4, l4, 2, &size);
    for (int i = 0; i < size; i++) {
        assert(result2[i] == expected2[i]);
    }
    free(result2);

    int l5[] = {4, 3, 2, 8};
    int l6[] = {3, 2, 4};
    int expected3[] = {2, 3, 4};
    int *result3 = func0(l5, 4, l6, 3, &size);
    for (int i = 0; i < size; i++) {
        assert(result3[i] == expected3[i]);
    }
    free(result3);

    int l7[] = {4, 3, 2, 8};
    int l8[] = {};
    int *result4 = func0(l7, 4, l8, 0, &size);
    assert(size == 0); // Since l8 is empty, result4 should be empty as well
    free(result4);

    return 0;
}

