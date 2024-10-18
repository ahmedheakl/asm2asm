#include <assert.h>
#include <string.h>
int *func0(int n, int *count);

int issame(int *a, int a_count, int *b, int b_count) {
    if (a_count != b_count) return 0;
    for (int i = 0; i < a_count; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int count;
    int expected[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

    int *result = func0(5, &count);
    assert(issame(result, count, (int[]){2, 3}, 2));
    free(result);

    result = func0(6, &count);
    assert(issame(result, count, (int[]){2, 3, 5}, 3));
    free(result);

    result = func0(7, &count);
    assert(issame(result, count, (int[]){2, 3, 5}, 3));
    free(result);

    result = func0(10, &count);
    assert(issame(result, count, (int[]){2, 3, 5, 7}, 4));
    free(result);

    result = func0(0, &count);
    assert(count == 0);
    free(result);

    result = func0(22, &count);
    assert(issame(result, count, (int[]){2, 3, 5, 7, 11, 13, 17, 19}, 8));
    free(result);

    result = func0(1, &count);
    assert(count == 0);
    free(result);

    result = func0(18, &count);
    assert(issame(result, count, (int[]){2, 3, 5, 7, 11, 13, 17}, 7));
    free(result);

    result = func0(47, &count);
    assert(issame(result, count, (int[]){2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43}, 14));
    free(result);

    result = func0(101, &count);
    assert(issame(result, count, expected, 25));
    free(result);

    return 0;
}
