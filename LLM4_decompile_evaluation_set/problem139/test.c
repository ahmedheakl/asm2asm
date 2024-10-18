#include <assert.h>
int func0(int n);

int main() {
    assert(func0(4) == 0);
    assert(func0(6) == 0);
    assert(func0(8) == 1);
    assert(func0(10) == 1);
    assert(func0(11) == 0);
    assert(func0(12) == 1);
    assert(func0(13) == 0);
    assert(func0(16) == 1);

    return 0;
}
