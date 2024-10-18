#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
bool func0(int q[], int size, int w);

int main() {
    int test1[] = {3, 2, 3};
    assert(func0(test1, 3, 9) == true);

    int test2[] = {1, 2};
    assert(func0(test2, 2, 5) == false);

    int test3[] = {3};
    assert(func0(test3, 1, 5) == true);

    int test4[] = {3, 2, 3};
    assert(func0(test4, 3, 1) == false);

    int test5[] = {1, 2, 3};
    assert(func0(test5, 3, 6) == false);

    int test6[] = {5};
    assert(func0(test6, 1, 5) == true);

    printf("All tests passed.\n");
    return 0;
}
