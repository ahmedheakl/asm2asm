#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
int *func0(int *numbers, int size);

int issame(int *a, int *b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int *result;

    // First test case
    result = func0((int[]){}, 0);
    assert(result == NULL);
    free(result);

    // Second test case
    int test1[] = {1, 2, 3, 4};
    result = func0(test1, 4);
    assert(issame(result, (int[]){1, 2, 3, 4}, 4));
    free(result);

    // Third test case
    int test2[] = {4, 3, 2, 1};
    result = func0(test2, 4);
    assert(issame(result, (int[]){4, 4, 4, 4}, 4));
    free(result);

    // Fourth test case
    int test3[] = {3, 2, 3, 100, 3};
    result = func0(test3, 5);
    assert(issame(result, (int[]){3, 3, 3, 100, 100}, 5));
    free(result);
    
    return 0;
}
