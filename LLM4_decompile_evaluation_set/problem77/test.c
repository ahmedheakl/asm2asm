#include <assert.h>
int func0(int x, int n);

int main() {
    assert(func0(1, 4) == 1);
    assert(func0(2, 2) == 1);
    assert(func0(8, 2) == 1);
    assert(func0(3, 2) == 0);
    assert(func0(3, 1) == 0);
    assert(func0(5, 3) == 0);
    assert(func0(16, 2) == 1);
    assert(func0(143214, 16) == 0);
    assert(func0(4, 2) == 1);
    assert(func0(9, 3) == 1);
    assert(func0(16, 4) == 1);
    assert(func0(24, 2) == 0);
    assert(func0(128, 4) == 0);
    assert(func0(12, 6) == 0);
    assert(func0(1, 1) == 1);
    assert(func0(1, 12) == 1);

    return 0;
}
