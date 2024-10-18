#include <assert.h>
int func0(int n);

int main() {
    assert(func0(2) == 1);
    assert(func0(1) == 0);
    assert(func0(5) == 4);
    assert(func0(8) == 24);
    assert(func0(10) == 81);
    assert(func0(12) == 274);
    assert(func0(14) == 927);

    return 0;
}
