#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void func0(int *array, int size, int **out_array, int *out_size);

int issame(int *a, int aSize, int *b, int bSize) {
    if (aSize != bSize) return 0;
    for (int i = 0; i < aSize; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int *result, result_size;

    func0((int[]){}, 0, &result, &result_size);
    assert(issame(result, result_size, (int[]){}, 0));
    free(result);

    func0((int[]){5}, 1, &result, &result_size);
    assert(issame(result, result_size, (int[]){5}, 1));
    free(result);

    func0((int[]){2, 4, 3, 0, 1, 5}, 6, &result, &result_size);
    assert(issame(result, result_size, (int[]){0, 1, 2, 3, 4, 5}, 6));
    free(result);

    func0((int[]){2, 4, 3, 0, 1, 5, 6}, 7, &result, &result_size);
    assert(issame(result, result_size, (int[]){6, 5, 4, 3, 2, 1, 0}, 7));
    free(result);

    func0((int[]){2, 1}, 2, &result, &result_size);
    assert(issame(result, result_size, (int[]){1, 2}, 2));
    free(result);

    func0((int[]){15, 42, 87, 32, 11, 0}, 6, &result, &result_size);
    assert(issame(result, result_size, (int[]){0, 11, 15, 32, 42, 87}, 6));
    free(result);

    func0((int[]){21, 14, 23, 11}, 4, &result, &result_size);
    assert(issame(result, result_size, (int[]){23, 21, 14, 11}, 4));
    free(result);

    return 0;
}
