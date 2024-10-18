#include <assert.h>
int func0(int operations[], int size);

int main() {
    int case1[] = {};
    assert(func0(case1, 0) == 0);

    int case2[] = {1, 2, -3, 1, 2, -3};
    assert(func0(case2, 6) == 0);

    int case3[] = {1, 2, -4, 5, 6};
    assert(func0(case3, 5) == 1);

    int case4[] = {1, -1, 2, -2, 5, -5, 4, -4};
    assert(func0(case4, 8) == 0);

    int case5[] = {1, -1, 2, -2, 5, -5, 4, -5};
    assert(func0(case5, 8) == 1);

    int case6[] = {1, -2, 2, -2, 5, -5, 4, -4};
    assert(func0(case6, 8) == 1);

    return 0;
}
