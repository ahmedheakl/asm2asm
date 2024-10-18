#include <assert.h>
int func0(int arr[], int k);

int main() {
    int test1[] = {1, -2, -3, 41, 57, 76, 87, 88, 99};
    assert(func0(test1, 3) == -4);

    int test2[] = {111, 121, 3, 4000, 5, 6};
    assert(func0(test2, 2) == 0);

    int test3[] = {11, 21, 3, 90, 5, 6, 7, 8, 9};
    assert(func0(test3, 4) == 125);

    int test4[] = {111, 21, 3, 4000, 5, 6, 7, 8, 9};
    assert(func0(test4, 4) == 24);
    
    int test5[] = {1};
    assert(func0(test5, 1) == 1);

    return 0;
}
