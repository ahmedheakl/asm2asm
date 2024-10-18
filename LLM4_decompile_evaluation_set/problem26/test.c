#include <assert.h>
#include <stdlib.h>
#include <string.h>
int* func0(int n, int* size);

int issame(int* a, int a_size, int* b, int b_size) {
    if (a_size != b_size) return 0;
    for (int i = 0; i < a_size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int size;
    int* result;

    result = func0(2, &size);
    assert(issame(result, size, (int[]){2}, 1));
    free(result);

    result = func0(4, &size);
    assert(issame(result, size, (int[]){2, 2}, 2));
    free(result);

    result = func0(8, &size);
    assert(issame(result, size, (int[]){2, 2, 2}, 3));
    free(result);

    result = func0(3 * 19, &size);
    assert(issame(result, size, (int[]){3, 19}, 2));
    free(result);

    result = func0(3 * 19 * 3 * 19, &size);
    assert(issame(result, size, (int[]){3, 3, 19, 19}, 4));
    free(result);

    result = func0(3 * 19 * 3 * 19 * 3 * 19, &size);
    assert(issame(result, size, (int[]){3, 3, 3, 19, 19, 19}, 6));
    free(result);

    result = func0(3 * 19 * 19 * 19, &size);
    assert(issame(result, size, (int[]){3, 19, 19, 19}, 4));
    free(result);

    result = func0(3 * 2 * 3, &size);
    assert(issame(result, size, (int[]){2, 3, 3}, 3));
    free(result);

    return 0;
}
