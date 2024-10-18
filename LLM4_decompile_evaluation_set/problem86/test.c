#include <assert.h>
int func0(int lst[], int size);

int main() {
    int array1[] = {4, 88};
    assert(func0(array1, sizeof(array1) / sizeof(array1[0])) == 88);

    int array2[] = {4, 5, 6, 7, 2, 122};
    assert(func0(array2, sizeof(array2) / sizeof(array2[0])) == 122);

    int array3[] = {4, 0, 6, 7};
    assert(func0(array3, sizeof(array3) / sizeof(array3[0])) == 0);

    int array4[] = {4, 4, 6, 8};
    assert(func0(array4, sizeof(array4) / sizeof(array4[0])) == 12);

    return 0;
}
