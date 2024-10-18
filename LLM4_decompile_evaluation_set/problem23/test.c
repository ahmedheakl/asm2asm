#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
int *func0(const char *values, int *size);

int issame(int *a, int size_a, int *b, int size_b) {
    if (size_a != size_b) return 0;
    for (int i = 0; i < size_a; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int size;

    // Test 1
    int *result1 = func0("", &size);
    assert(issame(result1, size, (int[]){}, 0));

    // Test 2
    int *result2 = func0("4,,23.2,9,adasd", &size);
    assert(issame(result2, size, (int[]){4, 9}, 2));

    // Test 3
    int *result3 = func0("3,c,3,3,a,b", &size);
    assert(issame(result3, size, (int[]){3, 3, 3}, 3));

    printf("All tests passed.\n");
    return 0;
}
