#include <assert.h>
int func0(int n);

int main() {
    assert(func0(3) == 1);
    assert(func0(7) == 1);
    assert(func0(10) == 5);
    assert(func0(100) == 50);
    assert(func0(49) == 7);

    return 0;
}
