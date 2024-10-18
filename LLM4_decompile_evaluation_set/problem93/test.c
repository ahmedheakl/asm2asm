#include <assert.h>
int func0(float a, float b, float c);

int main() {
    assert(func0(2, 3, 1) == 1);
    assert(func0(2.5, 2, 3) == 0);
    assert(func0(1.5, 5, 3.5) == 0);
    assert(func0(2, 6, 2) == 0);
    assert(func0(4, 2, 2) == 1);
    assert(func0(2.2, 2.2, 2.2) == 0);
    assert(func0(-4, 6, 2) == 1);
    assert(func0(2, 1, 1) == 1);
    assert(func0(3, 4, 7) == 1);
    assert(func0(3.01, 4, 7) == 0);

    return 0;
}
