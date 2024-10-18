#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
bool func0(int *l, int size);

int main() {
    int test1[] = {1, 3, 5, 0};
    assert(func0(test1, 4) == false);
    
    int test2[] = {1, 3, 5, -1};
    assert(func0(test2, 4) == false);
    
    int test3[] = {1, 3, -2, 1};
    assert(func0(test3, 4) == true);
    
    int test4[] = {1, 2, 3, 7};
    assert(func0(test4, 4) == false);
    
    int test5[] = {1, 2, 5, 7};
    assert(func0(test5, 4) == false);
    
    int test6[] = {2, 4, -5, 3, 9, 7};
    assert(func0(test6, 6) == true);
    
    int test7[] = {1};
    assert(func0(test7, 1) == false);
    
    int test8[] = {1, 3, 5, -100};
    assert(func0(test8, 4) == false);
    
    int test9[] = {100, 3, 5, -100};
    assert(func0(test9, 4) == false);

    return 0;
}
