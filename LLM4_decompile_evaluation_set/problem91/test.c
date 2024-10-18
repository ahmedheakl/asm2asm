#include <assert.h>
int func0(int *lst, int size);

int main() {
    int test1[] = {1, 2, 3, 4, 5};
    assert(func0(test1, 5) == 2);

    int test2[] = {5, 1, 4, 3, 2};
    assert(func0(test2, 5) == 2);

    assert(func0((int[]){}, 0) == -1);

    int test4[] = {1, 1};
    assert(func0(test4, 2) == -1);

    int test5[] = {1, 1, 1, 1, 0};
    assert(func0(test5, 5) == 1);

    int test6[] = {-35, 34, 12, -45};
    assert(func0(test6, 4) == -35);

    return 0;
}
