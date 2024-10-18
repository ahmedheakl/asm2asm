#include <assert.h>
#include <string.h>
void func0(int *lst, int size, int *out);

int issame(int *a, int *b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int a1[] = {1, 2, 3, 4};
    int e1[] = {1, 4, 2, 3};
    int out1[4];
    func0(a1, 4, out1);
    assert(issame(e1, out1, 4));

    int a2[] = {5, 6, 7, 8, 9};
    int e2[] = {5, 9, 6, 8, 7};
    int out2[5];
    func0(a2, 5, out2);
    assert(issame(e2, out2, 5));

    int a3[] = {1, 2, 3, 4, 5};
    int e3[] = {1, 5, 2, 4, 3};
    int out3[5];
    func0(a3, 5, out3);
    assert(issame(e3, out3, 5));

    int a4[] = {5, 6, 7, 8, 9, 1};
    int e4[] = {1, 9, 5, 8, 6, 7};
    int out4[6];
    func0(a4, 6, out4);
    assert(issame(e4, out4, 6));

    int a5[] = {5, 5, 5, 5};
    int e5[] = {5, 5, 5, 5};
    int out5[4];
    func0(a5, 4, out5);
    assert(issame(e5, out5, 4));

    int a6[] = {};
    int e6[] = {};
    int out6[0];
    func0(a6, 0, out6);
    assert(issame(e6, out6, 0));

    int a7[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int e7[] = {1, 8, 2, 7, 3, 6, 4, 5};
    int out7[8];
    func0(a7, 8, out7);
    assert(issame(e7, out7, 8));

    int a8[] = {0, 2, 2, 2, 5, 5, -5, -5};
    int e8[] = {-5, 5, -5, 5, 0, 2, 2, 2};
    int out8[8];
    func0(a8, 8, out8);
    assert(issame(e8, out8, 8));

    int a9[] = {111111};
    int e9[] = {111111};
    int out9[1];
    func0(a9, 1, out9);
    assert(issame(e9, out9, 1));

    return 0;
}
