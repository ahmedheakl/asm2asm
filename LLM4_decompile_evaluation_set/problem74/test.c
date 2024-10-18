#include <stdio.h>
#include <assert.h>
int func0(int arr[], int size);

int main() {
    int test1[] = {1, 2, 3, 5, 4, 7, 9, 6};
    assert(func0(test1, 8) == 4);

    int test2[] = {1, 2, 3, 4, 3, 2, 2};
    assert(func0(test2, 7) == 1);

    int test3[] = {1, 4, 2};
    assert(func0(test3, 3) == 1);

    int test4[] = {1, 4, 4, 2};
    assert(func0(test4, 4) == 1);

    int test5[] = {1, 2, 3, 2, 1};
    assert(func0(test5, 5) == 0);

    int test6[] = {3, 1, 1, 3};
    assert(func0(test6, 4) == 0);

    int test7[] = {1};
    assert(func0(test7, 1) == 0);

    int test8[] = {0, 1};
    assert(func0(test8, 2) == 1);

    return 0;
}
