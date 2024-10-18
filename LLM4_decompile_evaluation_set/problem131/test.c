#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
int* func0(int n);

int issame(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int size;

    int tri_3[] = {1, 3, 2, 8};
    size = 4;
    int* out3 = func0(3);
    assert(issame(out3, tri_3, size));
    free(out3);

    int tri_4[] = {1, 3, 2, 8, 3};
    size = 5;
    int* out4 = func0(4);
    assert(issame(out4, tri_4, size));
    free(out4);

    int tri_5[] = {1, 3, 2, 8, 3, 15};
    size = 6;
    int* out5 = func0(5);
    assert(issame(out5, tri_5, size));
    free(out5);

    int tri_6[] = {1, 3, 2, 8, 3, 15, 4};
    size = 7;
    int* out6 = func0(6);
    assert(issame(out6, tri_6, size));
    free(out6);

    int tri_7[] = {1, 3, 2, 8, 3, 15, 4, 24};
    size = 8;
    int* out7 = func0(7);
    assert(issame(out7, tri_7, size));
    free(out7);

    int tri_8[] = {1, 3, 2, 8, 3, 15, 4, 24, 5};
    size = 9;
    int* out8 = func0(8);
    assert(issame(out8, tri_8, size));
    free(out8);

    int tri_9[] = {1, 3, 2, 8, 3, 15, 4, 24, 5, 35};
    size = 10;
    int* out9 = func0(9);
    assert(issame(out9, tri_9, size));
    free(out9);

    int tri_20[] = {1, 3, 2, 8, 3, 15, 4, 24, 5, 35, 6, 48, 7, 63, 8, 80, 9, 99, 10, 120, 11};
    size = 21;
    int* out20 = func0(20);
    assert(issame(out20, tri_20, size));
    free(out20);

    int tri_0[] = {1};
    size = 1;
    int* out0 = func0(0);
    assert(issame(out0, tri_0, size));
    free(out0);

    int tri_1[] = {1, 3};
    size = 2;
    int* out1 = func0(1);
    assert(issame(out1, tri_1, size));
    free(out1);

    return 0;
}
