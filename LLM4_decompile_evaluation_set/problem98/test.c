#include <assert.h>
int func0(int a, int b);

int main() {
    assert(func0(148, 412) == 16);
    assert(func0(19, 28) == 72);
    assert(func0(2020, 1851) == 0);
    assert(func0(14, -15) == 20);
    assert(func0(76, 67) == 42);
    assert(func0(17, 27) == 49);
    assert(func0(0, 1) == 0);
    assert(func0(0, 0) == 0);

    return 0;
}
