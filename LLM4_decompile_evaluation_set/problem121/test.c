#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
void func0(int* arr, int arr_size, int k, int* out);

int issame(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

int main() {
    int arr1[] = {-3, -4, 5};
    int out1[3];
    func0(arr1, 3, 3, out1);
    int expected1[] = {-4, -3, 5};
    assert(issame(out1, expected1, 3));

    int arr2[] = {4, -4, 4};
    int out2[2];
    func0(arr2, 3, 2, out2);
    int expected2[] = {4, 4};
    assert(issame(out2, expected2, 2));

    int arr3[] = {-3, 2, 1, 2, -1, -2, 1};
    int out3[1];
    func0(arr3, 7, 1, out3);
    int expected3[] = {2};
    assert(issame(out3, expected3, 1));

    int arr4[] = {123, -123, 20, 0, 1, 2, -3};
    int out4[3];
    func0(arr4, 7, 3, out4);
    int expected4[] = {2, 20, 123};
    assert(issame(out4, expected4, 3));

    int arr5[] = {-123, 20, 0, 1, 2, -3};
    int out5[4];
    func0(arr5, 6, 4, out5);
    int expected5[] = {0, 1, 2, 20};
    assert(issame(out5, expected5, 4));

    int arr6[] = {5, 15, 0, 3, -13, -8, 0};
    int out6[7];
    func0(arr6, 7, 7, out6);
    int expected6[] = {-13, -8, 0, 0, 3, 5, 15};
    assert(issame(out6, expected6, 7));

    int arr7[] = {-1, 0, 2, 5, 3, -10};
    int out7[2];
    func0(arr7, 6, 2, out7);
    int expected7[] = {3, 5};
    assert(issame(out7, expected7, 2));

    int arr8[] = {1, 0, 5, -7};
    int out8[1];
    func0(arr8, 4, 1, out8);
    int expected8[] = {5};
    assert(issame(out8, expected8, 1));

    int arr9[] = {4, -4};
    int out9[2];
    func0(arr9, 2, 2, out9);
    int expected9[] = {-4, 4};
    assert(issame(out9, expected9, 2));

    int arr10[] = {-10, 10};
    int out10[2];
    func0(arr10, 2, 2, out10);
    int expected10[] = {-10, 10};
    assert(issame(out10, expected10, 2));

    int arr11[] = {1, 2, 3, -23, 243, -400, 0};
    int out11[0];
    func0(arr11, 7, 0, out11); // Empty output expected
    int expected11[] = {}; // Empty array
    assert(issame(out11, expected11, 0));

    return 0;
}
