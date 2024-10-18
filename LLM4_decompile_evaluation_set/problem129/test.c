#include <stdio.h>
#include <assert.h>
int func0(int *arr, int arr_size);

int main() {
    int arr1[] = {1, 2, 2, -4};
    assert(func0(arr1, 4) == -9);

    int arr2[] = {0, 1};
    assert(func0(arr2, 2) == 0);

    int arr3[] = {1, 1, 1, 2, 3, -1, 1};
    assert(func0(arr3, 7) == -10);

    assert(func0(NULL, 0) == -32768);

    int arr5[] = {2, 4, 1, 2, -1, -1, 9};
    assert(func0(arr5, 7) == 20);

    int arr6[] = {-1, 1, -1, 1};
    assert(func0(arr6, 4) == 4);

    int arr7[] = {-1, 1, 1, 1};
    assert(func0(arr7, 4) == -4);

    int arr8[] = {-1, 1, 1, 0};
    assert(func0(arr8, 4) == 0);
    
    return 0;
}
