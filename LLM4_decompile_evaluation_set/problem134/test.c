#include <assert.h>
int func0(float *lst, int size);

int main() {
    float lst1[] = {1, 2, 3};
    assert(func0(lst1, 3) == 14);

    float lst2[] = {1.0, 2, 3};
    assert(func0(lst2, 3) == 14);

    float lst3[] = {1, 3, 5, 7};
    assert(func0(lst3, 4) == 84);

    float lst4[] = {1.4, 4.2, 0};
    assert(func0(lst4, 3) == 29);

    float lst5[] = {-2.4, 1, 1};
    assert(func0(lst5, 3) == 6);

    float lst6[] = {100, 1, 15, 2};
    assert(func0(lst6, 4) == 10230);

    float lst7[] = {10000, 10000};
    assert(func0(lst7, 2) == 200000000);

    float lst8[] = {-1.4, 4.6, 6.3};
    assert(func0(lst8, 3) == 75);

    float lst9[] = {-1.4, 17.9, 18.9, 19.9};
    assert(func0(lst9, 4) == 1086);

    float lst10[] = {0};
    assert(func0(lst10, 1) == 0);

    float lst11[] = {-1};
    assert(func0(lst11, 1) == 1);

    float lst12[] = {-1, 1, 0};
    assert(func0(lst12, 3) == 2);

    return 0;
}
