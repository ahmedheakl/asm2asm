#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
void func0(int *x, int size, int **out, int *out_size);

bool issame(int *a, int a_size, int *b, int b_size) {
    if (a_size != b_size) return false;
    for (int i = 0; i < a_size; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

int main() {
    // Test cases
    int test1[] = {15, 33, 1422, 1};
    int expected1[] = {1, 15, 33};
    int *out1;
    int out1_size;
    func0(test1, 4, &out1, &out1_size);
    assert(issame(out1, out1_size, expected1, 3));
    free(out1);

    int test2[] = {152, 323, 1422, 10};
    int *out2;
    int out2_size;
    func0(test2, 4, &out2, &out2_size);
    assert(issame(out2, out2_size, NULL, 0));
    free(out2);

    int test3[] = {12345, 2033, 111, 151};
    int expected3[] = {111, 151};
    int *out3;
    int out3_size;
    func0(test3, 4, &out3, &out3_size);
    assert(issame(out3, out3_size, expected3, 2));
    free(out3);

    int test4[] = {135, 103, 31};
    int expected4[] = {31, 135};
    int *out4;
    int out4_size;
    func0(test4, 3, &out4, &out4_size);
    assert(issame(out4, out4_size, expected4, 2));
    free(out4);

    return 0;
}
