#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
bool func0(int *l, int size);

int main() {
    int test1[] = {1, 3, 5, 0};
    assert(func0(test1, 4) == false);
    
    int test2[] = {1, 3, -2, 1};
    assert(func0(test2, 4) == false);
    
    int test3[] = {1, 2, 3, 7};
    assert(func0(test3, 4) == false);
    
    int test4[] = {2, 4, -5, 3, 5, 7};
    assert(func0(test4, 6) == true);
    
    int test5[] = {1};
    assert(func0(test5, 1) == false);
    
    int test6[] = {-3, 9, -1, 3, 2, 30};
    assert(func0(test6, 6) == true);
    
    int test7[] = {-3, 9, -1, 3, 2, 31};
    assert(func0(test7, 6) == true);
    
    int test8[] = {-3, 9, -1, 4, 2, 30};
    assert(func0(test8, 6) == false);
    
    int test9[] = {-3, 9, -1, 4, 2, 31};
    assert(func0(test9, 6) == false);
    
    return 0;
}
