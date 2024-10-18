#include <assert.h>
int func0(int n);

int main() {
    assert(func0(10) == 55);
    assert(func0(1) == 1);
    assert(func0(8) == 21);
    assert(func0(11) == 89);
    assert(func0(12) == 144);

    return 0;
}
