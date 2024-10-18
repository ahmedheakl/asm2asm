#include <assert.h>
int func0(int* lst, int size);

int main() {
    int test1[] = {5, 8, 7, 1};
    assert(func0(test1, 4) == 12);

    int test2[] = {3, 3, 3, 3, 3};
    assert(func0(test2, 5) == 9);

    int test3[] = {30, 13, 24, 321};
    assert(func0(test3, 4) == 0);

    int test4[] = {5, 9};
    assert(func0(test4, 2) == 5);

    int test5[] = {2, 4, 8};
    assert(func0(test5, 3) == 0);

    int test6[] = {30, 13, 23, 32};
    assert(func0(test6, 4) == 23);

    int test7[] = {3, 13, 2, 9};
    assert(func0(test7, 4) == 3);

    return 0;
}
