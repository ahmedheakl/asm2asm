#include <assert.h>
#include <stdbool.h>
bool func0(int *l, int size, int t);

int main() {
    int list1[] = {1, 2, 4, 10};
    assert(func0(list1, 4, 100));

    int list2[] = {1, 20, 4, 10};
    assert(!func0(list2, 4, 5));
    
    int list3[] = {1, 20, 4, 10};
    assert(func0(list3, 4, 21));
    
    int list4[] = {1, 20, 4, 10};
    assert(func0(list4, 4, 22));
    
    int list5[] = {1, 8, 4, 10};
    assert(func0(list5, 4, 11));
    
    int list6[] = {1, 8, 4, 10};
    assert(!func0(list6, 4, 10));

    return 0;
}
