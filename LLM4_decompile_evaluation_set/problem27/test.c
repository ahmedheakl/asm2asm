#include <assert.h>
#include <string.h>
int* func0(int* numbers, int size, int* new_size);

int issame(int* a, int a_size, int* b, int b_size) {
    if (a_size != b_size) return 0;
    for (int i = 0; i < a_size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int new_size;
    int* result;

    result = func0((int[]){}, 0, &new_size);
    assert(issame(result, new_size, (int[]){}, 0));
    free(result);

    result = func0((int[]){1, 2, 3, 4}, 4, &new_size);
    assert(issame(result, new_size, (int[]){1, 2, 3, 4}, 4));
    free(result);

    result = func0((int[]){1, 2, 3, 2, 4, 3, 5}, 7, &new_size);
    assert(issame(result, new_size, (int[]){1, 4, 5}, 3));
    free(result);

    return 0;
}
