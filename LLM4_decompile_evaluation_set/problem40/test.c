#include <stdio.h>
#include <assert.h>
int func0(int n);

int main() {
    assert(func0(1) == 2);
    assert(func0(2) == 3);
    assert(func0(3) == 5);
    assert(func0(4) == 13);
    assert(func0(5) == 89);
    assert(func0(6) == 233);
    assert(func0(7) == 1597);
    assert(func0(8) == 28657);
    assert(func0(9) == 514229);
    assert(func0(10) == 433494437);

    return 0;
}
