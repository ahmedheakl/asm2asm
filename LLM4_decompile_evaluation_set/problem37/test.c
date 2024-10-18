#include <stdio.h>
#include <assert.h>
int func0(int n);

int main() {
    assert(func0(50) == 0);
    assert(func0(78) == 2);
    assert(func0(79) == 3);
    assert(func0(100) == 3);
    assert(func0(200) == 6);
    assert(func0(4000) == 192);
    assert(func0(10000) == 639);
    assert(func0(100000) == 8026);
}
