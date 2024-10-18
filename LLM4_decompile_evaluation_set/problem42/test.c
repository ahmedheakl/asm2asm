#include <stdio.h>
#include <assert.h>
int func0(int n);

int main() {
    assert(func0(2) == 4);
    assert(func0(3) == 9);
    assert(func0(4) == 16);
    assert(func0(8) == 64);
    assert(func0(10) == 100);

    return 0;
}
