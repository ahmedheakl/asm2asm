#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
bool func0(const int *lst, int lst_size);

int main() {
    int list1[] = {5};
    assert(func0(list1, 1) == true);

    int list2[] = {1, 2, 3, 4, 5};
    assert(func0(list2, 5) == true);

    int list3[] = {1, 3, 2, 4, 5};
    assert(func0(list3, 5) == false);

    int list4[] = {1, 2, 3, 4, 5, 6};
    assert(func0(list4, 6) == true);

    int list5[] = {1, 2, 3, 4, 5, 6, 7};
    assert(func0(list5, 7) == true);

    int list6[] = {1, 3, 2, 4, 5, 6, 7};
    assert(func0(list6, 7) == false);

    assert(func0(NULL, 0) == true);

    int list7[] = {1};
    assert(func0(list7, 1) == true);

    int list8[] = {3, 2, 1};
    assert(func0(list8, 3) == false);

    int list9[] = {1, 2, 2, 2, 3, 4};
    assert(func0(list9, 6) == false);

    int list10[] = {1, 2, 3, 3, 3, 4};
    assert(func0(list10, 6) == false);

    int list11[] = {1, 2, 2, 3, 3, 4};
    assert(func0(list11, 6) == true);

    int list12[] = {1, 2, 3, 4};
    assert(func0(list12, 4) == true);

    return 0;
}
